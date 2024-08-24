#include "main_threads.h"
#include "main.h"
#include "print_fcn.h"
#include "graphic_fcn.h"

Marker3D m3d;
extern Camera cam1, cam2;
extern CRITICAL_SECTION	cs, cs2;
extern double dT;
extern LogicalVariables logicVariables;
extern ApplicationWindows appWindows;

void liveFeed(void* param)
{
	pCamera	cam = (pCamera)param;
	clock_t	begin, end;
	PylonGrabResult_t result;
	uint64 ctx;
	uint8 i = 0, localstrm, fot_num_1 = 0, fot_num_2 = 0;
	Mat mask_low, mask_high, colorImg, binImg, calibImg, hsvImg;
	vector<Point2f> distorted_points(56), undistorted_points(56);
	bool isReady;
	int fontFace = FONT_HERSHEY_DUPLEX;
	float dTcam = 0.0, pix2 = 0.0, average_brightness = 0.0;
	double fontScale = 3.0;

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

			// przepisanie z bufora do Mat'a
			pylonImageToCvBayerMat(cam->buffer, CAM_WIDTH, CAM_HEIGHT, cam->bgrImg);

			// detekcja markerow (dziala tylko gdy kalibracja)
			findMarkers(cam->grayImg, binImg, cam->coded_markers, 0, logicVariables.imdisp, logicVariables.mkr_color);

			cvtColor(cam->bgrImg, hsvImg, COLOR_BayerBG2BGR);

			// kopiowanie do obrazka RGB
			cvtColor(cam->grayImg, colorImg, COLOR_GRAY2BGR);

			// szukanie pileczki (dziala zawsze gdy nie trwa kalibracja)
			//findBall(cam->bgrImg, colorImg);

			// maski underexposure i overexposure
			if (logicVariables.imdisp == 0) {
				mask_low = cam->grayImg > 250;
				mask_high = cam->grayImg < 5;
				colorImg.setTo(Scalar(0, 0, 255), mask_low); // kolor czerwony
				colorImg.setTo(Scalar(255, 0, 0), mask_high); // kolor niebieski
			}

			if (logicVariables.auto_exp) {
				average_brightness = 0.0;
				int count = 0; // To count actual samples considered
				// Adjust step size to evenly distribute samples
				int stepX = 1500 / 3;
				int stepY = 1000 / 3;
				for (int i = (CAM_WIDTH / 2) - 1500; i <= (CAM_WIDTH / 2) + 1500; i += stepX) {
					for (int j = (CAM_HEIGHT / 2) - 1000; j <= (CAM_HEIGHT / 2) + 1000; j += stepY) {
						average_brightness += cam->grayImg.at<uchar>(j, i);
						circle(colorImg, Point(i, j), 30, Scalar(0, 255, 255), -1, 8, 0);
						count++;
					}
				}
				if (count > 0) { // Ensure we avoid division by zero
					average_brightness /= count;
				}
				cam->br_max = (uint8_t)average_brightness; // Correct casting to uint8_t
				rectangle(colorImg, Point(CAM_WIDTH - 250, 250), Point(CAM_WIDTH, 0), CV_RGB(255, 255, 0), 10, CV_AA, 0);
				putText(colorImg, to_string(cam->br_max), Point(CAM_WIDTH - 250 + 25, 155), fontFace, fontScale, Scalar(0, 255, 255), 10);
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
			}

			// wydruk wszystkich znalezionych markerow
			for (i = 0; i < 56; i++) {
				if (cam->coded_markers[i].isSet) {
					circle(colorImg, Point((int)cam->coded_markers[i].x, (int)cam->coded_markers[i].y), 30, Scalar(0, 255, 0, 0), -1, 8, 0);
					if (cam->coded_markers[i].y < CAM_HEIGHT / 2)
						putText(colorImg, to_string(cam->coded_markers[i].code), Point((int)cam->coded_markers[i].x + 40, (int)cam->coded_markers[i].y + 100), fontFace, fontScale, Scalar(0, 255, 255), 10);
					else
						putText(colorImg, to_string(cam->coded_markers[i].code), Point((int)cam->coded_markers[i].x + 40, (int)cam->coded_markers[i].y - 100), fontFace, fontScale, Scalar(0, 255, 255), 10);
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
				putText(colorImg, "CAM 1 - LEFT", Point((int)(CAM_WIDTH) / 2 - 930, 80), fontFace, fontScale, Scalar(255, 255, 0), 2);

				putText(colorImg, "exp s:", Point(40, 150), fontFace, fontScale, Scalar(255, 255, 255), 2);
				putText(colorImg, to_string(cam->s_exp_time), Point(330, 150), fontFace, fontScale, Scalar(255, 255, 255), 2);

				putText(colorImg, "fps:", Point(40, 230), fontFace, fontScale, Scalar(255, 255, 255), 2);
				putText(colorImg, toStringWithPrecision(1 / dTcam, 1), Point(330, 230), fontFace, fontScale, Scalar(255, 255, 255), 2);

				putText(colorImg, "auto exp:", Point(40, 1140), fontFace, fontScale, Scalar(255, 255, 255), 2);
				putText(colorImg, to_string(logicVariables.auto_exp), Point(500, 1140), fontFace, fontScale, Scalar(255, 255, 255), 2);
			}
			else {
				putText(colorImg, "CAM 2 - RIGHT", Point((int)(CAM_WIDTH) / 2 - 930, 80), fontFace, fontScale, Scalar(255, 255, 0), 2);
			}
			imshow(cam->window, hsvImg); // wyswietlenie obrazu
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
		for (k = 0; k < 56; k++) {
			if (cam1.coded_markers_buff[k].isSet && cam2.coded_markers_buff[k].isSet) {
				m3d.isSet[k] = true;
				odprintf("1 [Bufor] kod[%d]	%f	%f\n", cam1.coded_markers_buff[k].code, cam1.coded_markers_buff[k].x, cam1.coded_markers_buff[k].y);
				odprintf("2 [Bufor] kod[%d]	%f	%f\n", cam2.coded_markers_buff[k].code, cam2.coded_markers_buff[k].x, cam2.coded_markers_buff[k].y);
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

		for (i = 0; i < 56; i++) {
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

void findMarkers(Mat& img, Mat& bImg, Marker* coded_markers, uint8 mode, uint8 disp, bool mkr_color)
{
	uint8 idxc = 0, idxu = 0, codeNum;
	float ratio, x, y;

	if (!mkr_color) threshold(img, bImg, BIN_THRESHOLD, 255, THRESH_BINARY); // czarny srodek
	else threshold(img, bImg, BIN_THRESHOLD, 255, THRESH_BINARY_INV); // bialy srodek

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

void findBall(Mat& bgrImg, Mat& colorImg) {
	// Definiowanie zakresu HSV dla koloru pomarañczowego
	Scalar lowerBound(10, 100, 100);
	Scalar upperBound(25, 255, 255);
	Mat hsvImg, mask;

	cvtColor(bgrImg, hsvImg, cv::COLOR_BGR2HSV);
	inRange(hsvImg, lowerBound, upperBound, mask);

	vector<std::vector<cv::Point>> contours;
	findContours(mask, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

	bool ballDetected = false;
	Point2f center;
	float radius = 0;

	for (const auto& contour : contours) {
		double area = cv::contourArea(contour);
		if (area > 100) {
			cv::minEnclosingCircle(contour, center, radius);
			ballDetected = true;
			break;
		}
	}

		// Rysowanie rzeczywistej pozycji pi³eczki
		circle(colorImg, center, static_cast<int>(radius), cv::Scalar(0, 255, 0), 2);
		circle(colorImg, center, 3, cv::Scalar(0, 0, 255), -1); // Rysowanie punktu centralnego
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
	Mat roi((int)(radius * 4.4f) + 2, (int)(radius * 4.4f) + 2, CV_8UC1);
	Mat map = Mat::zeros(2, 3, CV_32FC1);
	Point start((int)(ellipse.center.x - radius * 2.2), (int)(ellipse.center.y - radius * 2.2));
	Point end = start + Point((int)(radius * 4.4f), (int)(radius * 4.4f));
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

static void pylonImageToCvBayerMat(const void* pBuffer, int width, int height, Mat& image)
{
	image = Mat(height, width, CV_8UC1, (uchar*)pBuffer); // tworzenie obiektu Mat Hsv Bayer rgb z danych obrazu Pylon
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