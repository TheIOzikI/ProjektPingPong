#include "main.h"
#include "main_threads.h"
#include "graphic_fcn.h"
#include "print_fcn.h"


MatrixXd prevPointsIn3f;
vector<MatrixXd> estimated_states;
vector<vector<MatrixXd>> predicted_states;
Marker3D m3d;
prevPoints3D prev_points;
EstimatedPoints estimated_point;
PredictedPoints predicted_point;
CrossPlanePoints crossplanepoints;
RealPlanePoints realplanepoints;
polyfitPredictionPoints polyfit_points;
NewtonPoints predicted_points_newton;
extern Camera cam1, cam2;
extern CRITICAL_SECTION	cs, cs2;
extern double dT;
extern LogicalVariables logicVariables;
extern ApplicationWindows appWindows;
extern xRef RefPattern[54];

void liveFeed(void* param)
{
	pCamera	cam = (pCamera)param;
	clock_t	begin, end;
	PylonGrabResult_t result;
	uint64 ctx;
	uint8 i = 0, localstrm, fot_num_1 = 0, fot_num_2 = 0;
	Mat mask_low, mask_high, binImg, calibImg;
	vector<Point2f> distorted_points(56), undistorted_points(56);
	bool isReady;
	int fontFace = FONT_HERSHEY_DUPLEX;
	float dTcam = 0.0, pix2 = 0.0, average_brightness = 0.0;
	double fontScale = 1.5;

	if (!cam->hdl) return;
	if (cam->status) return;

	cam->buffer = (uint8*)malloc(CAM_PIX);
	if (cam->buffer == nullptr) return;

	// Create and open a stream grabber for the first channel.
	PylonDeviceGetStreamGrabber(cam->hdl, 0, &cam->stream);
	PylonStreamGrabberOpen(cam->stream);

	// Get a handle for the stream grabber's wait object. The wait object
	// allows waiting for buffers to be filled with grabbed data.
	PylonStreamGrabberGetWaitObject(cam->stream, &cam->wait);

	PylonStreamGrabberSetMaxNumBuffer(cam->stream, NUM_BUFFERS);
	PylonStreamGrabberSetMaxBufferSize(cam->stream, CAM_PIX);
	PylonStreamGrabberPrepareGrab(cam->stream);

	// rozpoczecie akwizycji // od teraz czeka na trigger z trzeciego w¹tku
	PylonDeviceExecuteCommandFeature(cam->hdl, "AcquisitionStart");

	// Allocate memory for grabbing
	for (i = 0; i < NUM_BUFFERS; ++i) {
		cam->grabBuff[i] = (uint8*)malloc(CAM_PIX);
		if (cam->grabBuff[i] != nullptr) {
			PylonStreamGrabberRegisterBuffer(cam->stream, cam->grabBuff[i], CAM_PIX, &cam->streamBuff[i]);
			PylonStreamGrabberQueueBuffer(cam->stream, cam->streamBuff[i], (void*)i);
		}
		else odprintf("[Info] Error allocating buffer %d for Camera\n", i);
	}
	cam->status = 2;
	localstrm = cam->status;


	odprintf("[Info] Starting Live Feed on %s\n", cam->id);
	while (localstrm > 1 && !logicVariables.stop_exe)
	{
		begin = clock();
		PylonWaitObjectWait(cam->wait, 1000, &isReady);
		if (isReady) {
			PylonStreamGrabberRetrieveResult(cam->stream, &result, &isReady);
			if (isReady) {
				ctx = (uint64)result.Context;
				if (result.Status == Grabbed && localstrm < 4) memcpy(cam->buffer, (uint8*)result.pBuffer, CAM_PIX);
				PylonStreamGrabberQueueBuffer(cam->stream, result.hBuffer, (void*)ctx);
			}
		}

		if (localstrm == 2) {

			// czyszczenie struktur dla markerow
			memset(cam->coded_markers, 0, 56 * sizeof * cam->coded_markers);

			// przepisanie z bufora do Mat'a
			pylonImageToCvMat(cam->buffer, CAM_WIDTH, CAM_HEIGHT, cam->grayImg);

			// detekcja markerow (dziala tylko gdy kalibracja)
			if(logicVariables.marker == true) findMarkers(cam->grayImg, binImg, cam->coded_markers, 0, logicVariables.imdisp, logicVariables.mkr_color);

			// szukanie pileczki (dziala zawsze gdy nie trwa kalibracja)
			findBall(cam->grayImg, cam->colorImg, cam->coded_markers);
			
			//undistort points
				if (cam->coded_markers[0].isSet) {
					distorted_points[0].x = cam->coded_markers[0].x;
					distorted_points[0].y = cam->coded_markers[0].y;
				}
			undistorted_points = undistortPointsMG(cam, distorted_points);
				if (cam->coded_markers[0].isSet) {
					cam->coded_markers[0].x = undistorted_points[0].x;
					cam->coded_markers[0].y = undistorted_points[0].y;
				}

			// kopiowanie do obrazka RGB
			cvtColor(cam->grayImg, cam->colorImg, COLOR_GRAY2BGR);

			// maski underexposure i overexposure
			if (logicVariables.imdisp == 0) {
				mask_low = cam->grayImg > 250;
				mask_high = cam->grayImg < 5;
				cam->colorImg.setTo(Scalar(0, 0, 255), mask_low); // kolor czerwony
				cam->colorImg.setTo(Scalar(255, 0, 0), mask_high); // kolor niebieski
			}

			// do autoekspozycji (srednia jasnosc w kwadracie)
			if (logicVariables.auto_exp) {
				average_brightness = 0.0;
				for (int i = (CAM_WIDTH / 2) - 700; i <= (CAM_WIDTH / 2) + 700; i += 700) {
					for (int j = (CAM_HEIGHT / 2) - 400; j <= (CAM_HEIGHT / 2) + 400; j += 400) {
						average_brightness += cam->grayImg.at<uchar>(j, i);
						circle(cam->colorImg, Point(i, j), 30, Scalar(0, 255, 255), -1, 8, 0);
					}
				}
				average_brightness /= 9;
				cam->br_max = (uint8)average_brightness; // dla regulatora w trzecim watku
				rectangle(cam->colorImg, Point(CAM_WIDTH - 250, 250), Point(CAM_WIDTH, 0), CV_RGB(255, 255, 0), 10, CV_AA, 0);
				putText(cam->colorImg, to_string(cam->br_max), Point(CAM_WIDTH - 250 + 25, 155), fontFace, fontScale, Scalar(0, 255, 255), 10);
			}

			if (!cam->mk_lock) { // gdy zapis odblokowany
				if (logicVariables.auto_exp) cam->br_max_buff = cam->br_max; // dla regulatora w trzecim watku
				memset(cam->coded_markers_buff, 0, 56 * sizeof * cam->coded_markers);
				for (i = 0; i < 56; i++) {
					if (cam->coded_markers[i].isSet) {
						// kopiowanie do bufora, zeby nie blokowac nowego zapisu gdy bedzie odczyt z liveDataProcessing
						cam->coded_markers_buff[i].isSet = cam->coded_markers[i].isSet;
						cam->coded_markers_buff[i].code = cam->coded_markers[i].code;
						cam->coded_markers_buff[i].x = cam->coded_markers[i].x;
						cam->coded_markers_buff[i].y = cam->coded_markers[i].y;
					}
					if (i == 55) {
						EnterCriticalSection(&cs2);
						cam->mk_lock = true; // blokuje zapis do bufora
						LeaveCriticalSection(&cs2);
					}
				}
				//if (cam->cam_num == 1 && cam->coded_markers[0].isSet) odprintf("%f	%f	|", cam->coded_markers[0].x, cam->coded_markers[0].y);
			}

			// wydruk wszystkich znalezionych markerow
			for (i = 0; i < 56; i++) {
				if (cam->coded_markers[i].isSet) {
					circle(cam->colorImg, Point((int)cam->coded_markers[i].x, (int)cam->coded_markers[i].y), 30, Scalar(0, 255, 0, 0));
					if (cam->coded_markers[i].y < CAM_HEIGHT / 2)
						putText(cam->colorImg, to_string(cam->coded_markers[i].code), Point((int)cam->coded_markers[i].x + 40, (int)cam->coded_markers[i].y + 100), fontFace, fontScale, Scalar(0, 255, 255), 2);
					else
						putText(cam->colorImg, to_string(cam->coded_markers[i].code), Point((int)cam->coded_markers[i].x + 40, (int)cam->coded_markers[i].y - 100), fontFace, fontScale, Scalar(0, 255, 255), 2);
				}
			}

			// zapis obrazka do pliku
			if (logicVariables.save_img_1 && cam->cam_num == 1) {
				fot_num_1++;
				imwrite("config/obrazy/fot_C1_" + to_string(fot_num_1) + ".png", cam1.grayImg);
				logicVariables.save_img_1 = false;
			}
			else if (logicVariables.save_img_2 && cam->cam_num == 2) {
				fot_num_2++;
				imwrite("config/obrazy/fot_C2_" + to_string(fot_num_2) + ".png", cam2.grayImg);
				logicVariables.save_img_2 = false;
			}

			// wydruk informacji w oknach kamer
			if (cam->cam_num == 1) {
				putText(cam->colorImg, "CAM 1 - LEFT", Point((int)(CAM_WIDTH) / 2 - 930, 80), fontFace, fontScale, Scalar(255, 255, 0), 2);

				putText(cam->colorImg, "exp s:", Point(40, 150), fontFace, fontScale, Scalar(255, 255, 255), 2);
				putText(cam->colorImg, to_string(cam->s_exp_time), Point(330, 150), fontFace, fontScale, Scalar(255, 255, 255), 2);

				putText(cam->colorImg, "fps:", Point(40, 230), fontFace, fontScale, Scalar(255, 255, 255), 2);
				putText(cam->colorImg, toStringWithPrecision(1 / dTcam, 1), Point(330, 230), fontFace, fontScale, Scalar(255, 255, 255), 2);

				putText(cam->colorImg, "auto exp:", Point(40, 1140), fontFace, fontScale, Scalar(255, 255, 255), 2);
				putText(cam->colorImg, to_string(logicVariables.auto_exp), Point(500, 1140), fontFace, fontScale, Scalar(255, 255, 255), 2);

			}
			else {
				putText(cam->colorImg, "CAM 2 - RIGHT", Point((int)(CAM_WIDTH) / 2 - 930, 80), fontFace, fontScale, Scalar(255, 255, 0), 2);
			}
			imshow(cam->window, cam->colorImg); // wyswietlenie obrazu
		}
		EnterCriticalSection(&cs);
		localstrm = cam->status;
		LeaveCriticalSection(&cs);

		end = clock();
		dTcam = (float)((double)end - (double)begin) / CLOCKS_PER_SEC;
	}

	// zakoñczenie akwizycji
	odprintf("[Info] Stopping liveFeed on %s\n", cam->id);
	PylonDeviceExecuteCommandFeature(cam->hdl, "AcquisitionStop");
	PylonStreamGrabberCancelGrab(cam->stream);

	do { PylonStreamGrabberRetrieveResult(cam->stream, &result, &isReady); } while (isReady);

	for (i = 0; i < NUM_BUFFERS; ++i) {
		PylonStreamGrabberDeregisterBuffer(cam->stream, cam->streamBuff[i]);
		if (cam->grabBuff[i]) free(cam->grabBuff[i]);
	}

	PylonStreamGrabberFinishGrab(cam->stream);
	PylonStreamGrabberClose(cam->stream);

	if (cam->buffer) free(cam->buffer);

	EnterCriticalSection(&cs);
	cam->status = 0;
	LeaveCriticalSection(&cs);
}

void liveDataProcessing(void*)
{
	odprintf("\n[Info] Starting liveDataProcessing\n\n");

	unsigned int loop = 0;
	int li2 = 0;
	uint32 last_pts_print_step = 0;
	clock_t begin1, end1, begin2, end2;

	// set up and initialize Direct3D
	dxInit(appWindows.panel3D);
	
	while (!logicVariables.stop_exe) {
		begin1 = clock();
		begin2 = clock();
		PylonDeviceExecuteCommandFeature(cam1.hdl, "TriggerSoftware");
		PylonDeviceExecuteCommandFeature(cam2.hdl, "TriggerSoftware");


		// rekonstrukcja markerów i inne funkcje bazujace na markerach
		if (cam1.mk_lock && cam2.mk_lock) {
			// autoekspozycja dla wycinka kwadratu ze srodka obrazka lub TR_MARKER (œrodkowy ze wzorca kalibracyjnego)
			if (logicVariables.auto_exp && logicVariables.imdisp == 0) {
				if (cam1.br_max_buff != 0 && cam2.br_max_buff != 0) {
					cam1.s_exp_time += 60 * ((uint64)BIN_THRESHOLD + 40 - (int)cam1.br_max_buff);
					cam2.s_exp_time += 60 * ((uint64)BIN_THRESHOLD + 40 - (int)cam2.br_max_buff);
					odprintf("cam1.s_exp_time = %d, cam2.s_exp_time = %d\n", cam1.s_exp_time, cam2.s_exp_time);
					odprintf("cam1.br_max = %d, cam2.br_max = %d\n", cam1.br_max_buff, cam2.br_max_buff);
					setExposure(cam1.s_exp_time, 1);
					setExposure(cam2.s_exp_time, 2);
					SendMessageW(appWindows.s_expTrackbar, TBM_SETPOS, true, CAM_EXP_MAX - ((cam1.s_exp_time + cam2.s_exp_time) / 2)); // dla skanowania
				}
			}
			reconstructMarkers3D();
			listBall3dPositions();

			//metody predykcji
			if(logicVariables.prediction == 1 && prev_points.x.size() > 3){
				//Kalman filter
				kalmanPrediction();
				if (predicted_point.x.size()>0) optimalStrikePointOther(predicted_point.x, predicted_point.y, predicted_point.z, 1000.0f);
				//odprintf("[Pingpong] Strike Point	X:	%f	Y:	1500	Z:	%f\n", crossplanepoints.x, crossplanepoints.z);
				}
			if (logicVariables.prediction == 2 && prev_points.x.size() > 3){
				//Aproksymacja wielomianowa
				polyfitPrediction();
				if (polyfit_points.x.size() > 0) optimalStrikePointOther(polyfit_points.xpred, polyfit_points.ypred, polyfit_points.zpred, 1000.0f);
				//odprintf("[Pingpong] Strike Point	X:	%f	Y:	1500	Z:	%f\n", crossplanepoints.x, crossplanepoints.z);
			}
			if (logicVariables.prediction == 3 && prev_points.x.size() > 3) {
				//Równania ruchu
				newtonPrediction();
				if (predicted_points_newton.x.size() > 0) optimalStrikePointOther(predicted_points_newton.x, predicted_points_newton.y, predicted_points_newton.z, 1000.0f);
				//odprintf("[Pingpong] Strike Point	X:	%f	Y:	1500	Z:	%f\n", crossplanepoints.x, crossplanepoints.z);
			}
			if (prev_points.x.size()>0) realStrikePointOther(prev_points.x, prev_points.y, prev_points.z, 1000.0f);
			distanceBetweenPoints(crossplanepoints.x,crossplanepoints.z,realplanepoints.x, realplanepoints.z);
			if(m3d.isSet[0] == true) odprintf("[Info] Pi³eczka[%d]	%f	%f	%f	|%f\n", m3d.code[0], m3d.x[0], m3d.y[0], m3d.z[0], m3d.err[0]);

			EnterCriticalSection(&cs2);
			cam1.mk_lock = false;
			cam2.mk_lock = false;
			LeaveCriticalSection(&cs2);
		}

		// generowanie sceny 3D
		dxRenderFrame();

		//:: zwolniony wydruk czegokolwiek :://
		li2++;
		if (li2 == 10) {
			//...
			li2 = 0;
		}
		end2 = clock();
		loop = (uint)abs(DT - 1000.0 * (((double)end2 - (double)begin2) / CLOCKS_PER_SEC));
		// pozosta³y czas wolny
		Sleep((DWORD)loop);
		end1 = clock();
		dT = ((double)end1 - (double)begin1) / CLOCKS_PER_SEC;
	}
	odprintf("[Info] Stopping liveDataProcessing\n");
}

void liveFeedRestore(void* param)
{
	if (cam1.status < 2 || cam2.status < 2) return;

	if (&cs) {
		EnterCriticalSection(&cs);
		if (cam1.status > 1) cam1.status = 2;
		if (cam2.status > 1) cam2.status = 2;
		LeaveCriticalSection(&cs);
	}
}

void setExposure(uint64 exp, int mode)
{
	HRESULT res;
	if (mode == 1) {
		if (PylonDeviceFeatureIsWritable(cam1.hdl, "ExposureTime")) {
			res = PylonDeviceSetFloatFeature(cam1.hdl, "ExposureTime", (float)exp);
		}
	}
	else if (mode == 2) {
		if (PylonDeviceFeatureIsWritable(cam2.hdl, "ExposureTime")) {
			res = PylonDeviceSetFloatFeature(cam2.hdl, "ExposureTime", (float)exp);
		}
	}
	else {
		if (PylonDeviceFeatureIsWritable(cam1.hdl, "ExposureTime") && PylonDeviceFeatureIsWritable(cam2.hdl, "ExposureTime")) {
			res = PylonDeviceSetFloatFeature(cam1.hdl, "ExposureTime", (float)exp);
			res = PylonDeviceSetFloatFeature(cam2.hdl, "ExposureTime", (float)exp);
		}
	}
}

//rekonstrukcja markerów do 3D
void reconstructMarkers3D(void)
{
	uint8 i = 0, k = 0, li = 0;
	float t0[3]{}, vx13[3]{}, g[3]{};
	struct Det { float a, b, W; } det = { 0.0 };
	struct Coords { float x, y, z; } pos = { 0.0 };
	pPoint4 vr1 = NULL, vr3 = NULL, plmk = NULL, prmk = NULL;
	algn(16) float  Rl[16] = { 0.0 }, Rr[16] = { 0.0 },
		RAinvL[16] = { 0.0 }, RAinvR[16] = { 0.0 };

	// rozne potrzebne macierze
	for (i = 0; i < 9; ++i) {
		Rl[ind9to16[i]] = cam1.RT[ind9to16[i]];
		Rr[ind9to16[i]] = cam2.RT[ind9to16[i]];
	}
	Rl[15] = 1.0; Rr[15] = 1.0;

	plmk = (pPoint4)_aligned_malloc(sizeof(Point4) * 56, 16);
	prmk = (pPoint4)_aligned_malloc(sizeof(Point4) * 56, 16);

	if (plmk != NULL && prmk != NULL) {
		vr1 = (pPoint4)_aligned_malloc(sizeof(Point4) * 56, 16);
		vr3 = (pPoint4)_aligned_malloc(sizeof(Point4) * 56, 16);

		// przepisanie pozycji tylko tych markerow (kodowanych), ktore sa jednoczesnie widoczne na obu obrazkach
		for (k = 0; k < 23; k++) {
			if (cam1.coded_markers_buff[k].isSet && cam2.coded_markers_buff[k].isSet) {
				m3d.isSet[k] = true;
				//odprintf("1 [Bufor] kod[%d]	%f	%f\n", cam1.coded_markers_buff[k].code, cam1.coded_markers_buff[k].x, cam1.coded_markers_buff[k].y);
				//odprintf("2 [Bufor] kod[%d]	%f	%f\n", cam2.coded_markers_buff[k].code, cam2.coded_markers_buff[k].x, cam2.coded_markers_buff[k].y);
				plmk[k].el.x = cam1.coded_markers_buff[k].x;
				plmk[k].el.y = cam1.coded_markers_buff[k].y;
				prmk[k].el.x = cam2.coded_markers_buff[k].x;
				prmk[k].el.y = cam2.coded_markers_buff[k].y;

				plmk[k].raw[2] = plmk[k].raw[3] = 1.0f; // 1-ki potrzebne do obliczen
				prmk[k].raw[2] = prmk[k].raw[3] = 1.0f;
				li++;

			}
			else m3d.isSet[k] = false;
		}
	}

	//if (cam1.coded_markers_buff[0].isSet) odprintf("%f	%f\n", plmk[0].el.x, plmk[0].el.y);

	if (li > 0) {
		//odprintf("znalazlem %d markerow\n", li);
		li = 0;
		// tutaj tworzenie wektktorów vr1 vr3
		// (reprojekcja przez AcInv tylko z rotacj¹)
		// vr1 = Rc1*Ac1inv*[lmk]
		// vr3 = Rc2*Ac2inv*[rmk]
		M4x4_SSE(Rl, cam1.Ainv, RAinvL);
		M4x4_SSE(Rr, cam2.Ainv, RAinvR);

		M4x1NS_SSE(RAinvL, plmk[0].raw, vr1[0].raw, 56);
		M4x1NS_SSE(RAinvR, prmk[0].raw, vr3[0].raw, 56);

		// T0 = TC1-TC2
		t0[0] = cam1.RT[3] - cam2.RT[3];
		t0[1] = cam1.RT[7] - cam2.RT[7];
		t0[2] = cam1.RT[11] - cam2.RT[11];

		for (i = 0; i < 23; i++) {
			// cross product of vr1 and vr3
			vx13[0] = vr1[i].el.y * vr3[i].el.z - vr3[i].el.y * vr1[i].el.z;
			vx13[1] = vr3[i].el.x * vr1[i].el.z - vr3[i].el.z * vr1[i].el.x;
			vx13[2] = vr1[i].el.x * vr3[i].el.y - vr3[i].el.x * vr1[i].el.y;

			// rozwiazuje: g*|vx13| + g3*|v3| - g2*|v1| = |t0|
			// gdzie g ->  wspolczynniki slaowania dlugosci wektorów

			// W
			det.a = (vx13[0] * vr3[i].el.y * -vr1[i].el.z) + (vx13[1] * vr3[i].el.z * -vr1[i].el.x) + (vx13[2] * vr3[i].el.x * -vr1[i].el.y);
			det.b = (vx13[2] * vr3[i].el.y * -vr1[i].el.x) + (vx13[0] * vr3[i].el.z * -vr1[i].el.y) + (vx13[1] * vr3[i].el.x * -vr1[i].el.z);
			det.W = det.a - det.b;
			//// g (g[0])
			//det.a = (t0[0] * vr3[i].el.y * -vr1[i].el.z) + (t0[1] * vr3[i].el.z * -vr1[i].el.x) + (t0[2] * vr3[i].el.x * -vr1[i].el.y);
			//det.b = (t0[2] * vr3[i].el.y * -vr1[i].el.x) + (t0[0] * vr3[i].el.z * -vr1[i].el.y) + (t0[1] * vr3[i].el.x * -vr1[i].el.z);
			//g[0] = (det.a - det.b) / det.W;
			// g3 (g[2])
			det.a = (vx13[0] * t0[1] * -vr1[i].el.z) + (vx13[1] * t0[2] * -vr1[i].el.x) + (vx13[2] * t0[0] * -vr1[i].el.y);
			det.b = (vx13[2] * t0[1] * -vr1[i].el.x) + (vx13[0] * t0[2] * -vr1[i].el.y) + (vx13[1] * t0[0] * -vr1[i].el.z);
			g[2] = (det.a - det.b) / det.W;
			// g2 (g[1])
			det.a = (vx13[0] * vr3[i].el.y * -t0[2]) + (vx13[1] * vr3[i].el.z * -t0[0]) + (vx13[2] * vr3[i].el.x * -t0[1]);
			det.b = (vx13[2] * vr3[i].el.y * -t0[0]) + (vx13[0] * vr3[i].el.z * -t0[1]) + (vx13[1] * vr3[i].el.x * -t0[2]);
			g[1] = -(det.a - det.b) / det.W;

			// konce vp1 vp2 przeskalowanych i przesunietych - wskazuj¹ punkt blisko przeciêcia
			vr1[i].el.x = g[1] * vr1[i].el.x + cam1.RT[3];
			vr1[i].el.y = g[1] * vr1[i].el.y + cam1.RT[7];
			vr1[i].el.z = g[1] * vr1[i].el.z + cam1.RT[11];

			vr3[i].el.x = g[2] * vr3[i].el.x + cam2.RT[3];
			vr3[i].el.y = g[2] * vr3[i].el.y + cam2.RT[7];
			vr3[i].el.z = g[2] * vr3[i].el.z + cam2.RT[11];

			// odleglosc z jaka minely sie wektory vp1 vp2
			pos.x = vr1[i].el.x - vr3[i].el.x;
			pos.y = vr1[i].el.y - vr3[i].el.y;
			pos.z = vr1[i].el.z - vr3[i].el.z;

			m3d.err[i] = (float)sqrt(pos.x * pos.x + pos.y * pos.y + pos.z * pos.z);

			if (m3d.err[i] < MKR_RECON_ERR)
			{
				// 3D dane - œrednia z 2 konców wektora
				m3d.x[i] = ((float)vr1[i].el.x + (float)vr3[i].el.x) / 2.0f;
				m3d.y[i] = ((float)vr1[i].el.y + (float)vr3[i].el.y) / 2.0f;
				m3d.z[i] = ((float)vr1[i].el.z + (float)vr3[i].el.z) / 2.0f;
				m3d.code[i] = i;
				//odprintf("[Info] kod[%d]	%f	%f	%f	|%f\n", m3d.code[i], m3d.x[i], m3d.y[i], m3d.z[i], m3d.err[i]);
			}
		}
	}
	_aligned_free(plmk);
	_aligned_free(prmk);
	_aligned_free(vr1);
	_aligned_free(vr3);
}

//Szukanie markerów na obrazie
void findMarkers(Mat& img, Mat& bImg, Marker* coded_markers, uint8 mode, uint8 disp, bool mkr_color)
{
	uint8 idxc = 0, idxu = 0, codeNum;
	float ratio, x, y, ar = 0.0;

	int th_area = 151, th_const = 9;
	if (!mkr_color) adaptiveThreshold(img, bImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, th_area, th_const);
	else adaptiveThreshold(img, bImg, 255, ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY_INV, th_area, th_const);

	//if (!mkr_color) threshold(img, bImg, BIN_THRESHOLD, 255, THRESH_BINARY); // czarny srodek
	//else threshold(img, bImg, BIN_THRESHOLD, 255, THRESH_BINARY_INV); // bialy srodek

	Mat kern = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(bImg, bImg, MORPH_CLOSE, kern);
	morphologyEx(bImg, bImg, MORPH_OPEN, kern);
	cleanBorder(bImg);

	if (disp == 1)  img = bImg; // podmienia img na obraz binarny

	vector<Vec4i> hierarchy;
	vector<vector<Point>> contours;
	vector<Point> cntr;


	findContours(bImg, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_NONE, Point(0, 0));

	vector<RotatedRect> eout(contours.size()), einn(contours.size());

	for (size_t i = 0; i < contours.size(); ++i) {
		ar = contourArea(contours[i]);
		if (ar > 300.0 && ar < 1000.0)
		{
			if (hierarchy[i][2] != -1) {
				cntr = contours[hierarchy[i][2]];

				if (contours[i].size() > 5 && cntr.size() > 5) {
					eout[i] = fitEllipse(contours[i]);
					einn[i] = fitEllipse(cntr);

					x = einn[i].center.x - eout[i].center.x; // wzgledne przesuniecie srodkow koncenrtycznych okregow
					y = einn[i].center.y - eout[i].center.y;

					if (sqrt(x * x + y * y) < MKR_PIX_ERR) {
						ratio = ((einn[i].size.height / eout[i].size.height) +
							(einn[i].size.width / eout[i].size.width)) / 2.0f;
						if (ratio > MKR_MIN_RATIO && ratio < MKR_MAX_RATIO) { // dla naszych markerow idealnie jest 0,46 / po korekcji obrazu 0.55

							codeNum = readCode(bImg, eout[i]);
							//odprintf("contour size %f\n",  );


							if (codeNum >= MIN_CODE && codeNum <= MAX_CODE) {
								if (mode == 0) { // mode 0 - markery wpisywane w tablice zgodnie z numerem kodu
									idxc = codeNum + 1;
								}
								else if (mode == 1) idxc++; // mode 1 - wszytskie markery wpisywane w tablice po kolei (przy kalibracji)

								coded_markers[idxc - 1].isSet = true;
								coded_markers[idxc - 1].code = codeNum;
								coded_markers[idxc - 1].x = eout[i].center.x;
								coded_markers[idxc - 1].y = eout[i].center.y;
								coded_markers[idxc - 1].elypse = eout[i];
							}
						}
					}
				}

			}
		}
	}
}

//Szukanie pi³ki na obrazie
void findBall(Mat& grayImg, Mat& colorImg, Marker* coded_markers) {
	// Definiowanie zakresu HSV dla koloru pomarañczowego
	Scalar lowerBound(5, 180, 100);
	Scalar upperBound(25, 255, 255);
	Mat hsvImg, bgrImg, mask;


	// Konwersja obrazu szarego na kolorowy
	cvtColor(grayImg, bgrImg, COLOR_BayerBG2BGR);

	// Konwersja obrazu BGR na HSV
	cvtColor(bgrImg, hsvImg, COLOR_BGR2HSV);

	// Maskowanie zakresu koloru pomarañczowego//
	inRange(hsvImg, lowerBound, upperBound, mask);

	vector<vector<Point>> contours;
	findContours(mask, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

	bool ballDetected = false;
	Point2f center;
	float radius = 0;

	// Przegl¹danie konturów w poszukiwaniu odpowiedniego obiektu
	for (const auto& contour : contours) {
		double area = contourArea(contour);
		if (area > 100) {  // Sprawdzenie, czy kontur jest wystarczaj¹co du¿y
			minEnclosingCircle(contour, center, radius);
			ballDetected = true;
			break;
		}
	}

	if (ballDetected) {
		// Ustawienie flagi wykrycia pi³ki oraz zapisanie jej pozycji dla kamery 1
		coded_markers[0].isSet = true;
		coded_markers[0].code = 0;
		coded_markers[0].x = center.x;
		coded_markers[0].y = center.y;
	}
	else
	{
		coded_markers[0].isSet = false;
	}
	

	// Rysowanie rzeczywistej pozycji pi³eczki na obrazie kolorowym
	if (ballDetected) {
		circle(colorImg, center, static_cast<int>(radius), Scalar(0, 255, 0), 2);// Rysowanie kó³ka
		circle(colorImg, center, 3, Scalar(0, 0, 255), -1); // Rysowanie punktu centralnego
	}
}

//Lista pozycji pi³ki
void listBall3dPositions() {
	if (m3d.isSet[0] == true) {
		// przepisanie punktów do odpowiednich wektorów
		if (prev_points.x.size() < 250) {
			prev_points.x.push_back(m3d.x[0]);
			prev_points.y.push_back(m3d.y[0]);
			prev_points.z.push_back(m3d.z[0]);
		}

	}
	else
	{
		prev_points.cycles = prev_points.cycles + 1;
		//odprintf("[Info] Ball not seen %i \n", prev_points.cycles);
	}
	//kasowanie trajektorii 
	if(prev_points.cycles >= 200) {
		// wyczyszczenie wszystkich wektorów
		prev_points.x.clear();
		prev_points.y.clear();
		prev_points.z.clear();
		prev_points.x.shrink_to_fit();
		prev_points.y.shrink_to_fit();
		prev_points.z.shrink_to_fit();
		prev_points.cycles = 0;
		odprintf("[Info] Trajectory points reset\n");
	}
}

void kalmanPrediction() {
	float g = 9.8;
	int n = prev_points.x.size();  // Liczba pomiarów
	int n_future = PREDICTION_TIME * dT / 1000;  // liczba kroków do przodu

	estimated_point.x.clear();
	estimated_point.y.clear();
	estimated_point.z.clear();
	estimated_point.x.shrink_to_fit();
	estimated_point.y.shrink_to_fit();
	estimated_point.z.shrink_to_fit();
	predicted_point.x.clear();
	predicted_point.y.clear();
	predicted_point.z.clear();
	predicted_point.x.shrink_to_fit();
	predicted_point.y.shrink_to_fit();
	predicted_point.z.shrink_to_fit();

	// Inicjalizacja wektora stanu [px, py, pz, vx, vy, vz, ax, ay, az]
	VectorXf x(9);
	x << 0, 0, 0, 0, 0, 0, 0, 0, 0;

	// Macierz przejœcia stanu A
	MatrixXf A(9, 9);
	A << 1, 0, 0, DT, 0, 0, 0.5 * DT * DT, 0, 0,
		0, 1, 0, 0, DT, 0, 0, 0.5 * DT * DT, 0,
		0, 0, 1, 0, 0, DT, 0, 0, 0.5 * DT * DT,
		0, 0, 0, 1, 0, 0, DT, 0, 0,
		0, 0, 0, 0, 1, 0, 0, DT, 0,
		0, 0, 0, 0, 0, 1, 0, 0, DT,
		0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 1;

	// Macierz kontrolna B (grawitacja)
	VectorXf B(9);
	B << 0, 0, -0.5 * DT * DT * g, 0, 0, -DT * g, 0, 0, 0;

	// Macierz pomiaru H (pomiar tylko pozycji)
	MatrixXf H(3, 9);
	H << 1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0, 0, 0, 0;

	// Macierz kowariancji b³êdów
	MatrixXf P = MatrixXf::Identity(9, 9);
	MatrixXf Q = 0.001 * MatrixXf::Identity(9, 9);
	MatrixXf R = 0.000002 * MatrixXf::Identity(3, 3);

	// Pomiary bêd¹ reprezentowane jako wektor
	vector<Vector3f> measurements(n);
	for (int i = 0; i < n; ++i) {
		measurements[i] << prev_points.x[i], prev_points.y[i], prev_points.z[i];
	}

	// Zestaw prognozowanych stanów
	vector<float> estimated_x(n), estimated_y(n), estimated_z(n);
	vector<vector<float>> predicted_x(n, vector<float>(n_future)), predicted_y(n, vector<float>(n_future)), predicted_z(n, vector<float>(n_future));

	// G³ówna pêtla
	for (int k = 0; k < n; ++k) {
		// Krok predykcji
		x = A * x + B;
		P = A * P * A.transpose() + Q;

		// Aktualizacja na podstawie pomiaru
		Vector3f z = measurements[k];
		MatrixXf K = P * H.transpose() * (H * P * H.transpose() + R).inverse();
		x = x + K * (z - H * x);
		P = (MatrixXf::Identity(9, 9) - K * H) * P;

		// Sprawdzenie odbicia
		if (x(2) <= 0) {
			x(2) = 0;
			x(5) = -x(5) * BOUNCE_FACTOR;
		}

		// Przechowywanie oszacowanych wspó³rzêdnych

		estimated_point.x.push_back(x(0));
		estimated_point.y.push_back(x(1));
		estimated_point.z.push_back(x(2));


		// Prognoza na przysz³e 10 kroków
		VectorXf x_future = x;
		for (int j = 0; j < n_future; ++j) {
			x_future = A * x_future;

			// Sprawdzenie odbicia w prognozie
			if (x_future(2) <= 0) {
				x_future(2) = 0;
				x_future(5) = -x_future(5) * BOUNCE_FACTOR;
			}

			// Przewidywane pozycje

			predicted_point.x.clear();
			predicted_point.y.clear();
			predicted_point.z.clear();
			predicted_point.x.shrink_to_fit();
			predicted_point.y.shrink_to_fit();
			predicted_point.z.shrink_to_fit();

			predicted_point.x.push_back(x_future(0));
			predicted_point.y.push_back(x_future(1));
			predicted_point.z.push_back(x_future(2));



		}
	}
}

// Funkcja do dopasowania wielomianu oraz przewidywania wartoœci
void polyfitPrediction() {
	// Czyszczenie tablic
	polyfit_points.x.clear();
	polyfit_points.y.clear();
	polyfit_points.z.clear();
	polyfit_points.x.shrink_to_fit();
	polyfit_points.y.shrink_to_fit();
	polyfit_points.z.shrink_to_fit();

	int degree = 3;
	int future_points = PREDICTION_TIME * 10;  // liczba kroków do przodu

	vector<int> segment_start_indices;
	segment_start_indices.push_back(0);  // Zaczynamy od pocz¹tku

	// Wykrywanie przerw, gdy z < 20
	for (int i = 1; i < prev_points.z.size(); ++i) {
		if (prev_points.z[i] >= 100 && prev_points.z[i - 1] < 100) {
			segment_start_indices.push_back(i);  // Nowy segment
		}
	}
	segment_start_indices.push_back(prev_points.z.size());  // Zakoñczenie na koñcu danych

	// Funkcja pomocnicza do przewidywania wartoœci wielomianu
	auto polyval = [](const VectorXf& coeffs, float t) -> float {
		float result = 0.0f;
		int degree = coeffs.size() - 1;
		for (int i = 0; i <= degree; ++i) {
			result += coeffs[i] * pow(t, i);  // Wielomian o malej¹cych potêgach
		}
		return result;
		};

	// Przetwarzanie ka¿dego segmentu osobno
	for (int seg = 0; seg < segment_start_indices.size() - 1; ++seg) {
		int start_idx = segment_start_indices[seg];
		int end_idx = segment_start_indices[seg + 1];

		int n = end_idx - start_idx;
		MatrixXf A(n, degree + 1);
		VectorXf b_x(n), b_y(n), b_z(n);

		// Budowanie macierzy A i wektorów b dla bie¿¹cego segmentu
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= degree; ++j) {
				A(i, j) = pow(i + 1, j);
			}
			b_x(i) = prev_points.x[start_idx + i];
			b_y(i) = prev_points.y[start_idx + i];
			b_z(i) = prev_points.z[start_idx + i];
		}

		// Obliczanie wspó³czynników wielomianów dla bie¿¹cego segmentu
		VectorXf p_x = A.colPivHouseholderQr().solve(b_x);
		VectorXf p_y = A.colPivHouseholderQr().solve(b_y);
		VectorXf p_z = A.colPivHouseholderQr().solve(b_z);

		// Przewidywanie wartoœci dla bie¿¹cego segmentu
		for (int i = 0; i < n; ++i) {
			float pred_x = polyval(p_x, i + 1);
			float pred_y = polyval(p_y, i + 1);
			float pred_z = polyval(p_z, i + 1);

			// Dodaj przewidywane wartoœci do polyfit_points
			polyfit_points.x.push_back(pred_x);
			polyfit_points.y.push_back(pred_y);
			polyfit_points.z.push_back(pred_z);
		}

		polyfit_points.xpred.clear();
		polyfit_points.ypred.clear();
		polyfit_points.zpred.clear();
		polyfit_points.xpred.shrink_to_fit();
		polyfit_points.ypred.shrink_to_fit();
		polyfit_points.zpred.shrink_to_fit();

		// Przewidywanie przysz³ych wartoœci dla bie¿¹cego segmentu
		for (int i = 0; i < future_points; ++i) {
			float t_future = n + i + 1;  // Kontynuujemy indeks po ostatnim punkcie segmentu
			float pred_x_future = polyval(p_x, t_future);
			float pred_y_future = polyval(p_y, t_future);
			float pred_z_future = polyval(p_z, t_future);

			// Dodaj przewidywane przysz³e wartoœci do polyfit_points
			polyfit_points.xpred.push_back(pred_x_future);
			polyfit_points.ypred.push_back(pred_y_future);
			polyfit_points.zpred.push_back(pred_z_future);
		}

	}
}

void newtonPrediction() {
	double dt = dT / 1000;
	int n = prev_points.x.size();
	int n_future = PREDICTION_TIME * dT/1000;
	//odprintf("[Info]size of x	%i %i	\n", n, n_future);
	

	//czyszczenie struktury przed dodaniem
	if (predicted_points_newton.x.size() > 1) {
		predicted_points_newton.x.clear();
		predicted_points_newton.y.clear();
		predicted_points_newton.z.clear();
		predicted_points_newton.x.shrink_to_fit();
		predicted_points_newton.y.shrink_to_fit();
		predicted_points_newton.z.shrink_to_fit();
	}

	vector<float> vx, vy, vz, ax, ay, az;

	for (size_t i = 1; i < prev_points.x.size(); ++i) {
		vx.push_back((prev_points.x[i] - prev_points.x[i - 1]) / dt);
		vy.push_back((prev_points.y[i] - prev_points.y[i - 1]) / dt);
		vz.push_back((prev_points.z[i] - prev_points.z[i - 1]) / dt);
	}

	for (size_t i = 1; i < vx.size(); ++i) {
		ax.push_back((vx[i] - vx[i - 1]) / dt);
		ay.push_back((vy[i] - vy[i - 1]) / dt);
		az.push_back((vz[i] - vz[i - 1]) / dt);
	}

	// Predykcja kolejnych pozycji na podstawie ostatniej prêdkoœci i przyspieszenia
	int n_pred = 10; // Liczba przewidywanych punktów
	vector<float> x_pred(n_pred, 0), y_pred(n_pred, 0), z_pred(n_pred, 0);

	x_pred[0] = prev_points.x.back();
	y_pred[0] = prev_points.y.back();
	z_pred[0] = prev_points.z.back();

	// Symulacja trajektorii z wykrywaniem odbicia dla z = 0
	for (int t_pred = 1; t_pred < n_pred; ++t_pred) {
		// Predykcja nowych pozycji
		x_pred[t_pred] = x_pred[t_pred - 1] + vx.back() * dt + 0.5 * ax.back() * dt * dt;
		y_pred[t_pred] = y_pred[t_pred - 1] + vy.back() * dt + 0.5 * ay.back() * dt * dt;
		z_pred[t_pred] = z_pred[t_pred - 1] + vz.back() * dt + 0.5 * az.back() * dt * dt;

		// Wykrywanie odbicia w osi Z (gdy z osi¹ga 0)
		//if (z_pred[t_pred] < 0) {
		//	z_pred[t_pred] = -z_pred[t_pred];  // Symulacja odbicia
		//	vz.back() = -vz.back() * BOUNCE_FACTOR;  // Zmiana prêdkoœci z t³umieniem
		//}
		//dodawanie
		predicted_points_newton.x.push_back(x_pred[t_pred]);
		predicted_points_newton.y.push_back(y_pred[t_pred]);
		predicted_points_newton.z.push_back(z_pred[t_pred]);
	}
}

//Optymalne miejscie odbicia dla Innych z pojedycznego wektora
void optimalStrikePointOther(vector<float>& x_data, vector<float>& y_data, vector<float>& z_data, float y_plane) {

	int size = x_data.size();  // Automatyczne sprawdzenie d³ugoœci wektora

	// Znajdujemy przeciêcia dla pojedynczego wektora punktów
	for (int i = 0; i < size - 1; ++i) {
		if (x_data[i] < 1000 && x_data[i] > -1000 && z_data[i] < 700 && z_data[i] > -30) {
			float y1 = y_data[i];
			float y2 = y_data[i + 1];

			if ((y1 - y_plane) * (y2 - y_plane) <= 0 && y1 != y2) {
				float t = (y_plane - y1) / (y2 - y1);
				float x_intersection = x_data[i] + t * (x_data[i + 1] - x_data[i]);
				float z_intersection = z_data[i] + t * (z_data[i + 1] - z_data[i]);
				crossplanepoints.x = x_intersection;
				crossplanepoints.z = z_intersection;
			}
		}

	}
}
//realna pozycja przeciêcia z y 
void realStrikePointOther(vector<float>& x_data, vector<float>& y_data, vector<float>& z_data, float y_plane) {

	for (int i = 0; i < x_data.size() - 1; ++i) {
		if (x_data[i] < 1000 && x_data[i] > -1000 && z_data[i] < 700 && z_data[i] > -30) {
			float y1 = y_data[i];
			float y2 = y_data[i + 1];

			if ((y1 - y_plane) * (y2 - y_plane) <= 0 && y1 != y2) {
				float t = (y_plane - y1) / (y2 - y1);
				float x_intersection = x_data[i] + t * (x_data[i + 1] - x_data[i]);
				float z_intersection = z_data[i] + t * (z_data[i + 1] - z_data[i]);
				realplanepoints.x = x_intersection;
				realplanepoints.z = z_intersection;
			}
		}

	}
}

void distanceBetweenPoints(float&x1, float& z1, float& x2, float& z2) {
	float dx = x1 - x2;
	float dz = z1 - z2;
	realplanepoints.distance = sqrt(dx * dx + dz * dz);
}

void cleanBorder(Mat& img) {
	Scalar el;
	uint16_t i;
	for (i = 0; i < (uint16_t)img.cols; ++i) {
		el = img.at<uint8_t>(0, i);
		if (el.val[0] == 255)
			floodFill(img, Point(i, 0), Scalar(0), nullptr, Scalar(0), Scalar(0), FLOODFILL_FIXED_RANGE);
		el = img.at<uint8_t>(img.rows - 1, i);
		if (el.val[0] == 255)
			floodFill(img, Point(i, img.rows - 1), Scalar(0), nullptr, Scalar(0), Scalar(0), FLOODFILL_FIXED_RANGE);
	}
	for (i = 0; i < (uint16_t)img.rows; ++i) {
		el = img.at<uint8_t>(i, 0);
		if (el.val[0] == 255)
			floodFill(img, Point(0, i), Scalar(0), nullptr, Scalar(0), Scalar(0), FLOODFILL_FIXED_RANGE);
		el = img.at<uint8_t>(i, img.cols - 1);
		if (el.val[0] == 255)
			floodFill(img, Point(img.cols - 1, i), Scalar(0), nullptr, Scalar(0), Scalar(0), FLOODFILL_FIXED_RANGE);
	}
}

float alignRadians(Mat& roi, float radius, Point2f center) {
	int32_t x, y, count = 0;
	float mean_x = 0.0f, mean_y = 0.0f, angle = 0.0f;
	for (float rad = 0.0f; rad < pi_mul2; rad += pi * 0.02f) {
		x = (int32_t)(radius * cosf(rad) + center.x);
		y = (int32_t)(radius * sinf(rad) + center.y);
		if (y >= 0 && y < roi.rows && x >= 0 && x < roi.cols && roi.at<uint8_t>(y, x) > 0) {
			mean_x += (float)x;
			mean_y += (float)y;
			count++;
		}
	}
	if (count > 0) {
		mean_x /= (float)count;
		mean_y /= (float)count;
		angle = atan2f(mean_y - center.y, mean_x - center.x);
	}
	return angle;
}

uint8_t readCode(Mat& img, RotatedRect ellipse) {
	// odczyt kodów markerów
	uint8_t cn = 0, readCode = 0;
	uint16_t k, l;
	int32_t i, j, x, y;
	float scale, rad, rmax, r, radius = ellipse.size.height / 2.0f;
	Mat roi((int)(radius * CODE_AREA) + 2, (int)(radius * CODE_AREA) + 2, CV_8UC1);
	Mat map = Mat::zeros(2, 3, CV_32FC1);
	Point start((int)(ellipse.center.x - radius * CODE_AREA / 2.0), (int)(ellipse.center.y - radius * CODE_AREA / 2.0));
	Point end = start + Point((int)(radius * CODE_AREA), (int)(radius * CODE_AREA));
	RotatedRect eli;
	bool code[20];

	eli.angle = ellipse.angle;
	eli.size = ellipse.size;
	eli.center.x = ellipse.center.x - (float)start.x;
	eli.center.y = ellipse.center.y - (float)start.y;

	scale = eli.size.height / eli.size.width;

	roi.setTo(Scalar(0));
	for (k = 0; k < roi.cols; k++)
		for (l = 0; l < roi.rows; l++) {
			i = start.y + l;
			j = start.x + k;
			if (i > -1 && i < img.rows && j > -1 && j < img.cols) roi.at<uint8_t>(l, k) = img.at<uint8_t>(i, j);
		}

	Mat rotationMatrix = getRotationMatrix2D(eli.center, eli.angle, 1.0);
	warpAffine(roi, roi, rotationMatrix, roi.size(), INTER_NEAREST | WARP_FILL_OUTLIERS, BORDER_CONSTANT, Scalar(0));
	map.at<float>(0, 0) = scale;
	map.at<float>(0, 2) = ((float)roi.cols - ((float)roi.cols * scale)) / 2.0f;
	map.at<float>(1, 1) = 1.0f;
	warpAffine(roi, roi, map, roi.size(), INTER_NEAREST | WARP_FILL_OUTLIERS, BORDER_CONSTANT, Scalar(0));

	rad = alignRadians(roi, radius, eli.center); // osobna funkcja 
	rmax = rad + pi_mul2;
	memset(code, false, sizeof code);

	for (; rad < rmax; rad += pi * 0.2f, cn++) {
		for (r = radius * 1.4f; r < radius * 2.0f; r += 0.2f) {
			x = (int32_t)(r * cosf(rad) + eli.center.x);
			y = (int32_t)(r * sinf(rad) + eli.center.y);
			if (y >= 0 && y < roi.rows && x >= 0 && x < roi.cols && roi.at<uint8_t>(y, x) > 0) {
				code[cn] = true;
				code[cn + 10] = true;
				roi.at<uint8_t>(y, x) = 128;
				break;
			}
		}
	}

	for (cn = 0; cn < 11; cn++) if (!code[cn] && code[cn + 1] && code[cn + 2]) break;
	if (cn < 10) {
		for (i = 0; i < 7; ++i) readCode += code[cn + 3 + i] << i;
	}
	else {
		readCode = 6;
	}

	//if (codesLUT[readCode] == 8) { imshow("test2", roi); waitKey(1); }


	return codesLUT[readCode];
}

static string toStringWithPrecision(double value, int precision) {
	ostringstream out;
	out << fixed << setprecision(precision) << value;
	return out.str();
}

static void pylonImageToCvMat(const void* pBuffer, int width, int height, Mat& image)
{
	image = Mat(height, width, CV_8UC1, (uchar*)pBuffer); // tworzenie obiektu Mat z danych obrazu Pylon
}

vector<Point2f> undistortPointsMG(pCamera cam, vector<Point2f> good_points_distorted)
{
	vector<Point2f> good_points_undistorted(good_points_distorted.size());
	Point2f inv_pt;
	float radius2, KK;

	for (int i = 0; i < good_points_distorted.size(); i++) {
		// projekcja wsteczna (goodpoints) do plaszczyzny Z=1, zeby mozna bylo zastosowaæ model dystorsji
		inv_pt.x = cam->Ainv[0] * good_points_distorted[i].x +
			cam->Ainv[1] * good_points_distorted[i].y +
			cam->Ainv[2];
		inv_pt.y = cam->Ainv[4] * good_points_distorted[i].x + // to  w sumie =0 zawsze
			cam->Ainv[5] * good_points_distorted[i].y +
			cam->Ainv[6];
		radius2 = (float)(pow(inv_pt.x, 2) + pow(inv_pt.y, 2));
		KK = 1 + cam->K[0] * radius2 + cam->K[1] * (float)pow(radius2, 2) + cam->K[4] * (float)pow(radius2, 3); // wspolczynniki 0,1,4 s¹ od radialnej

		// przesuniecie pikselowe do srodka obrazu
		good_points_undistorted[i].x = ((good_points_distorted[i].x - cam->A[2]) / KK) + cam->A[2];
		good_points_undistorted[i].y = ((good_points_distorted[i].y - cam->A[6]) / KK) + cam->A[6];

		// model dystorsji tangencjalnej
		good_points_undistorted[i].x -= 2 * cam->K[2] * inv_pt.x * inv_pt.y + cam->K[3] * (radius2 + 2 * (float)pow(inv_pt.x, 2));
		good_points_undistorted[i].y -= cam->K[2] * (radius2 + 2 * (float)pow(inv_pt.y, 2)) + 2 * cam->K[3] * inv_pt.x * inv_pt.y;

		//circle(BL, Point(good_points_undistorted[i].x, good_points_undistorted[i].y), 4, Scalar(255, 255, 255), FILLED);
	}
	return good_points_undistorted;
}

void ExtrinsicParam(void* param)
{
	//POPRAWIÆ DLA DOWLNEJ LICZBY WIDOCZNYCH MARKEROW A NIE 13 !!!!!!!!!!!!!!!
	pCamera cam = (pCamera)param;

	CvMat* mkref, * mkimg, * A, * K, * rotv, * rot, * trans;
	//Marker	M[54] = { 0 }, MU[54] = { 0 };
	// tymczasowe macierze
	A = cvCreateMat(3, 3, CV_32F);
	rotv = cvCreateMat(3, 1, CV_32F);
	rot = cvCreateMat(3, 3, CV_32F);
	trans = cvCreateMat(3, 1, CV_32F);
	K = cvCreateMat(5, 1, CV_32F);

	algn(16) float	R[9] = { 0 }, Rinv[9] = { 0 }, T[3] = { 0 }, Tinv[3] = { 0 };
	uint8 i = 0, found_mkr = 0, li = 0, c;

	//CvMat* I = cvCreateMat(CAM_HEIGHT, CAM_WIDTH, CV_8UC1);
	//CvMat* binImg = cvCreateMat(CAM_HEIGHT, CAM_WIDTH, CV_8UC1);
	//CvMat* tImg = cvCreateMat(CAM_HEIGHT, CAM_WIDTH, CV_8UC1);
	//uint8  br_max = 0;
	// BRAKUJE PRZYGOTOWANIA ImPattern
	//CaptureFrame(cam, I->data.ptr, false);
	/*EnterCriticalSection(&cs); cam->status = 2; LeaveCriticalSection(&cs);*/
	// szukanie i wydruk markerów
	//FindMarkers(cam->grayImg, binImg, tImg, M, MU, 15, 27, 1, &br_max, 0, mkr_color); // mode = 1 -> marekry wszytskie, nawet powtarzajace sie, kolejno do struktury

	// zliczenie markerow jednoczesnie widocznych na obrazie i nalezacych do referencja³u
	for (i = 1; i < 54; i++) {
		c = cam->coded_markers_buff[i].code;
		if (cam->coded_markers_buff[i].isSet && RefPattern[c - 1].code > 0) {
			found_mkr++;
		}
	}
	odprintf("[Info] Iloœæ widocznych markerów: %d z 9!\n", found_mkr);
	if (found_mkr == 9)
	{
		mkimg = cvCreateMat(found_mkr, 2, CV_32F);
		mkref = cvCreateMat(found_mkr, 3, CV_32F);

		// przepisanie referencja³u i punktów obrazowych do cvmat-ów
		for (i = 0; i < 54; i++) {
			c = cam->coded_markers_buff[i].code;
			if (cam->coded_markers_buff[i].isSet && RefPattern[c - 1].code > 0)
			{
				mkimg->data.fl[li * 2] = cam->coded_markers_buff[i].x; //kolumna
				mkimg->data.fl[li * 2 + 1] = cam->coded_markers_buff[i].y; //wiersz
				mkref->data.fl[li * 3] = RefPattern[c - 1].x;
				mkref->data.fl[li * 3 + 1] = RefPattern[c - 1].y;
				mkref->data.fl[li * 3 + 2] = RefPattern[c - 1].z;
				odprintf("code:%d	ref: %f	%f	%f| img: %f	%f\n", RefPattern[c - 1].code, mkref->data.fl[i * 3], mkref->data.fl[i * 3 + 1], mkref->data.fl[i * 3 + 2], mkimg->data.fl[i * 2], mkimg->data.fl[i * 2 + 1]);
				li++;
			}
		}

		for (i = 0; i < 9; i++) {
			A->data.fl[i] = cam->A[ind9to16[i]];
		}
		cvSetData(K, cam->K, sizeof(float));
		//PrintMatFloat("A:", A);
		//PrintMatFloat("K:", K);

		// wyznaczenie parametrów zewnetrznych
		cvFindExtrinsicCameraParams2(mkref, mkimg, A, K, rotv, trans, 0);
		cvRodrigues2(rotv, rot, 0);

		// tworzenie wszystkich macierzy transformacji T R RT RTinv
		memcpy(Rinv, rot->data.fl, 9 * sizeof(float));
		I3x3_SSE(Rinv, R);

		memcpy(Tinv, trans->data.fl, 3 * sizeof(float));
		cam->Tinv[0] = T[0] = -Tinv[0];
		cam->Tinv[1] = T[1] = -Tinv[1];
		cam->Tinv[2] = T[2] = -Tinv[2];
		M3x1_SSE(R, T, T);

		//przepisanie z macierzy 3x3 do  4x4 
		for (i = 0; i < 9; i++) {
			cam->R[i] = R[i];
			cam->R[ind9to16[i]] = R[i];
			cam->RT[ind9to16[i]] = R[i];
			cam->RTinv[ind9to16[i]] = Rinv[i];
		}
		cam->RT[12] = cam->RTinv[12] = 0.0;
		cam->RT[13] = cam->RTinv[13] = 0.0;
		cam->RT[14] = cam->RTinv[14] = 0.0;
		cam->RT[15] = cam->RTinv[15] = cam->R[15] = 1.0;
		cam->RT[3] = T[0];
		cam->RT[7] = T[1];
		cam->RT[11] = T[2];
		cam->T[0] = T[0];
		cam->T[1] = T[1];  //chyb NIEPOTRZENNA
		cam->T[2] = T[2];
		cam->RTinv[3] = Tinv[0];
		cam->RTinv[7] = Tinv[1];
		cam->RTinv[11] = Tinv[2];

		printArrFloat("RT", cam->RT, 4, 4);
		printArrFloat("R", cam->R, 4, 4);
		printArrFloat("T", cam->T, 3, 1);
		printArrFloat("R", cam->R, 4, 4);
		printCamParams(cam);

		if (cam->cam_num == 1) saveCamParams(cam, CAM_LEFT_PARAM_FILE);
		else saveCamParams(cam, CAM_RIGHT_PARAM_FILE);
		odprintf("[Info] Zapisano parametry po³o¿enia kamer!\n");

		cvReleaseMat(&A);
		cvReleaseMat(&K);
		cvReleaseMat(&rot);
		cvReleaseMat(&rotv);
		cvReleaseMat(&trans);
		cvReleaseMat(&mkref);
		cvReleaseMat(&mkimg);

		//odœwie¿enie kamer w oknie directx 
		refresh3Dobjects(&cam1);
		refresh3Dobjects(&cam2);
		odprintf("[Info] Zakoñczono kalibracjê parametrów zewnêtrznych!\n");
	}
	else
	{
		// komunikat w oknie, ze za malo widocznych markerow na wzorcu
		odprintf("[Info] Zbyt ma³o widocznych markerów: %d z 9!\n", found_mkr);

	}
}

void saveCamParams(pCamera cam, const char* name) {
	CamData data = { 0 };
	FILE* file = nullptr;
	errno_t err;

	data.a11 = cam->A[0];
	data.a12 = cam->A[1];
	data.a13 = cam->A[2];
	data.a21 = cam->A[4];
	data.a22 = cam->A[5];
	data.a23 = cam->A[6];
	data.a31 = cam->A[8];
	data.a32 = cam->A[9];
	data.a33 = cam->A[10];

	data.k1 = cam->K[0];
	data.k2 = cam->K[1];
	data.k3 = cam->K[2];
	data.k4 = cam->K[3];
	data.k5 = cam->K[4];

	data.r11 = cam->RT[0];
	data.r12 = cam->RT[1];
	data.r13 = cam->RT[2];
	data.r21 = cam->RT[4];
	data.r22 = cam->RT[5];
	data.r23 = cam->RT[6];
	data.r31 = cam->RT[8];
	data.r32 = cam->RT[9];
	data.r33 = cam->RT[10];

	data.t11 = cam->RT[3];
	data.t21 = cam->RT[7];
	data.t31 = cam->RT[11];

	err = fopen_s(&file, name, "wb");
	if (file) {
		fwrite(&data, sizeof(CamData), 1, file);
		fclose(file);
	}
}
