#include "init_system_fcn.h"
#include "main.h"
#include "print_fcn.h"

wchar_t	errTitle[50] = L"Error";
wchar_t	errDesc[200] = L"An error occured!";

Point4 corners_cam1[4], corners_cam2[4];

extern HANDLE serialHandle;
extern ApplicationWindows appWindows;
extern Camera cam1, cam2;
extern CRITICAL_SECTION cs;
extern xRef RefPattern[54];

__inline void errMsg(wchar_t* title, wchar_t* desc) {
	swprintf_s(errTitle, 50, L"%s", title);
	swprintf_s(errDesc, 200, L"%s", desc);
}

void terminateCameras(HRESULT status)
{
	EnterCriticalSection(&cs);
	if (cam1.status > 1) cam1.status = 1;
	if (cam2.status > 1) cam2.status = 1;
	LeaveCriticalSection(&cs);

	while (cam1.status > 0 || cam2.status > 0) Sleep(10);

	if (status != GENAPI_E_OK)
	{
		int8* errMsg;
		uint64 length;

		// Retrieve the error message
		GenApiGetLastErrorMessage(NULL, &length);
		errMsg = (int8*)malloc(length);
		GenApiGetLastErrorMessage(errMsg, &length);
		odprintf("%s (%#08x).\n", errMsg, status);
		free(errMsg);

		// Retrieve more details about the error.
		GenApiGetLastErrorDetail(nullptr, &length);
		errMsg = (int8*)malloc(length);
		GenApiGetLastErrorDetail(errMsg, &length);
		odprintf("%s\n", errMsg);
		free(errMsg);
	}

	if (cam1.hdl != nullptr) {
		PylonDeviceClose(cam1.hdl);
		PylonDestroyDevice(cam1.hdl);
	}
	if (cam2.hdl != nullptr) {
		PylonDeviceClose(cam2.hdl);
		PylonDestroyDevice(cam2.hdl);
	}
	PylonTerminate();
}

bool initCameras(void)
{
	bool result = true;
	double d = 0;
	uint64 size;
	int8 serial[16];
	uint64 numCams = 0;
	_Bool isAvail = true;
	PYLON_WAITOBJECTS_HANDLE wos;
	PYLON_DEVICE_HANDLE	hCam1, hCam2;
	PYLON_WAITOBJECT_HANDLE woTimer; /* Timer wait object. */
	HANDLE hTimer; /* Grab timer. */

	/* Macro to check for errors */
#define CHECK(errc) if (GENAPI_E_OK != errc) printErrorAndExit(errc);
	GENAPIC_RESULT errRes = GENAPI_E_OK; /* Return value of pylon methods */

	// Before using any methods, the runtime must be initialized
	PylonInitialize();

	errRes = PylonEnumerateDevices(&numCams); pylonCheck(errRes);
	odprintf("[Info] Found %d GigE devices\n", numCams);
	if (numCams < 2) {
		odprintf("[Error] Less than 2 devices found!\n");
		PylonTerminate();
		errMsg(L"Not enough devices", L"Less than 2 devices found!\nConnect missing devices and try again or exit.");
		return false;
	}

	/* Create wait objects (must be done outside of the loop). */
	errRes = PylonWaitObjectsCreate(&wos);
	pylonCheck(errRes);

	/* Create a Windows timer, wrap it in a pylon C wait object, and add it to the wait object set. */
	hTimer = CreateWaitableTimer(NULL, TRUE, NULL);
	if (hTimer == NULL)
	{
		fprintf(stderr, "CreateWaitableTimer() failed.\n");
		PylonTerminate();
		return false;
	}
	errRes = PylonWaitObjectFromW32(hTimer, 0, &woTimer);
	pylonCheck(errRes);

	errRes = PylonWaitObjectsAdd(wos, woTimer, NULL);
	pylonCheck(errRes);

	// Get a handle for the devices found
	errRes = PylonCreateDeviceByIndex(0, &hCam1);	pylonCheck(errRes);
	errRes = PylonCreateDeviceByIndex(1, &hCam2);	pylonCheck(errRes);
	// Before using the device, it must be opened
	// Open it for configuring parameters (CONTROL) and for grabbing images (STREAM)
	errRes = PylonDeviceOpen(hCam1, PYLONC_ACCESS_MODE_CONTROL | PYLONC_ACCESS_MODE_STREAM);	pylonCheck(errRes);
	errRes = PylonDeviceOpen(hCam2, PYLONC_ACCESS_MODE_CONTROL | PYLONC_ACCESS_MODE_STREAM);	pylonCheck(errRes);

	char buf[256]; size_t siz = sizeof(buf); _Bool isReadable;

	isReadable = PylonDeviceFeatureIsReadable(hCam1, "DeviceModelName");
	if (isReadable)
	{
		errRes = PylonDeviceFeatureToString(hCam1, "DeviceModelName", buf, &siz);
		pylonCheck(errRes);
		odprintf("[Info] Using camera no. 1: '%s'\n", buf);
	}
	isReadable = PylonDeviceFeatureIsReadable(hCam2, "DeviceModelName");
	if (isReadable)
	{
		errRes = PylonDeviceFeatureToString(hCam2, "DeviceModelName", buf, &siz);
		pylonCheck(errRes);
		odprintf("[Info] Using camera no. 2: '%s'\n", buf);
	}

	isAvail = PylonDeviceFeatureIsWritable(hCam1, "MaxBufferSize");
	isAvail &= PylonDeviceFeatureIsWritable(hCam2, "MaxBufferSize");
	if (isAvail) {
		errRes = PylonDeviceSetIntegerFeature(hCam1, "MaxBufferSize", 11520000);	pylonCheck(errRes);
		errRes = PylonDeviceSetIntegerFeature(hCam2, "MaxBufferSize", 11520000);	pylonCheck(errRes);
	}
	
	errRes = PylonDeviceFeatureFromString(hCam1, "PixelFormat", "BayerRG8");		pylonCheck(errRes);
	errRes = PylonDeviceFeatureFromString(hCam2, "PixelFormat", "BayerRG8");		pylonCheck(errRes);


	////////////////// ustawienie rozdzielczo�ci //////////////////
	isAvail = PylonDeviceFeatureIsWritable(hCam1, "Width");
	isAvail &= PylonDeviceFeatureIsWritable(hCam2, "Height");
	if (isAvail) {
		errRes = PylonDeviceSetIntegerFeature(hCam1, "Width", CAM_WIDTH);		pylonCheck(errRes);
		errRes = PylonDeviceSetIntegerFeature(hCam2, "Width", CAM_WIDTH);		pylonCheck(errRes);
		errRes = PylonDeviceSetIntegerFeature(hCam1, "Height", CAM_HEIGHT);		pylonCheck(errRes);
		errRes = PylonDeviceSetIntegerFeature(hCam2, "Height", CAM_HEIGHT);		pylonCheck(errRes);
		odprintf("[Info] Set Width and Height\n");
	}

	////////////////// ustawienie gaina //////////////////
	/* Set the "raw" gain value to specified value */
	errRes = PylonDeviceSetFloatFeature(hCam1, "Gain", CAM_GAIN_DEFAULT);
	errRes = PylonDeviceSetFloatFeature(hCam2, "Gain", CAM_GAIN_DEFAULT);
	odprintf("[Info] Set Gain\n");

	////////////////////gamma/////////////////////////////
	errRes = PylonDeviceSetFloatFeature(hCam1, "Gamma", CAM_GAMMA);
	errRes = PylonDeviceSetFloatFeature(hCam2, "Gamma", CAM_GAMMA);
	odprintf("[Info] Set Gamma\n");

	////////////////////////////////light source/////////////////
	/* Set the light source preset for daylight (at about 6500K) */
	errRes = PylonDeviceFeatureFromString(hCam1, "LightSourcePreset", "Daylight6500K");	pylonCheck(errRes);
	errRes = PylonDeviceFeatureFromString(hCam2, "LightSourcePreset", "Daylight6500K");	pylonCheck(errRes);


	errRes = PylonDeviceSetBooleanFeature(hCam1, "AcquisitionFrameRateEnable", 1); pylonCheck(errRes);
	errRes = PylonDeviceSetBooleanFeature(hCam2, "AcquisitionFrameRateEnable", 1); pylonCheck(errRes);
	errRes = PylonDeviceSetFloatFeature(hCam1, "AcquisitionFrameRate", 100.0);pylonCheck(errRes);
	errRes = PylonDeviceSetFloatFeature(hCam2, "AcquisitionFrameRate", 100.0); pylonCheck(errRes);

	////////////////// ustawienie ekspozycji //////////////////
	/* Determine the current exposure time */
	errRes = PylonDeviceGetFloatFeature(hCam1, "ExposureTime", &d);
	errRes = PylonDeviceGetFloatFeature(hCam2, "ExposureTime", &d);
	/* Set the exposure time mode to Standard */
	errRes = PylonDeviceFeatureFromString(hCam1, "ExposureTimeMode", "Standard");
	errRes = PylonDeviceFeatureFromString(hCam2, "ExposureTimeMode", "Standard");
	/* Set the exposure time to specified value [microseconds] */
	errRes = PylonDeviceSetFloatFeature(hCam1, "ExposureTime", (float)CAM_EXP_DEFAULT);
	errRes = PylonDeviceSetFloatFeature(hCam2, "ExposureTime", (float)CAM_EXP_DEFAULT);
	odprintf("[Info] Set ExposureTime\n");

	////////////////// obr�cenie obraz�w //////////////////
	/* Enable Reverse X, if available */
	errRes = PylonDeviceSetBooleanFeature(hCam1, "ReverseX", 1);
	errRes = PylonDeviceSetBooleanFeature(hCam2, "ReverseX", 0);
	/* Enable Reverse Y, if available */
	errRes = PylonDeviceSetBooleanFeature(hCam1, "ReverseY", 1);
	errRes = PylonDeviceSetBooleanFeature(hCam2, "ReverseY", 0);

	////////////////// sprawdzenie kamer po ID //////////////////
	size = 16;
	errRes = PylonDeviceFeatureToString(hCam1, "DeviceModelName", serial, &size); pylonCheck(errRes);
	cam1.hdl = strcmp(serial, CAM_LEFT_SERIAL) == 0 ? hCam1 : hCam2;
	cam1.hdl = hCam1;
	size = 16;
	errRes = PylonDeviceFeatureToString(hCam2, "DeviceModelName", serial, &size); pylonCheck(errRes);
	cam2.hdl = strcmp(serial, CAM_RIGHT_SERIAL) == 0 ? hCam2 : hCam1;
	cam2.hdl = hCam2;

	////////////////// ustawienie trybu akwizycji obraz�w //////////////////
	errRes = PylonDeviceFeatureFromString(hCam1, "TriggerSelector", "FrameStart");
	errRes = PylonDeviceFeatureFromString(hCam1, "TriggerMode", "On");
	errRes = PylonDeviceFeatureFromString(hCam1, "TriggerSource", "Software");
	errRes = PylonDeviceFeatureFromString(hCam2, "TriggerSelector", "FrameStart");
	errRes = PylonDeviceFeatureFromString(hCam2, "TriggerMode", "On");
	errRes = PylonDeviceFeatureFromString(hCam2, "TriggerSource", "Software");

	return true;
}

void tryInitCameras(void* param)
{
	int32 id;
	float scale = 500.0;
	UNREFERENCED_PARAMETER(param);

	// camera numbers
	cam1.cam_num = 1; // LEWA CAMERA
	cam2.cam_num = 2; // PRAWA CAMERA
	// globalny dostep do ustawionych ekspozycji
	cam1.s_exp_time = CAM_EXP_DEFAULT;
	cam2.s_exp_time = CAM_EXP_DEFAULT;

	// nawiazanie komunikacji z kamerami
	if (!initCameras()) {
		id = MessageBox(NULL, errDesc, errTitle, MB_ICONEXCLAMATION | MB_OK | MB_DEFBUTTON1);
		switch (id) {
		case IDOK:
			PostMessage(appWindows.mainWindow, WM_DESTROY, 0, 0);
			return; break;
		default:
			return;
		}
	}

	///////////////////////////////////////
	//:::Wszytskie funkcje INICJUJ�CE :::::

	//  model wzorca 3D do pozycjonowania kamery
	//vector<Point3f> refPattern = {
	//	Point3f(-0.079021, -147.427491, -12.049359),	//marker nr 19
	//	Point3f(671.605864, -1277.323964, -1.870671),	//marker nr 17
	//	Point3f(0.629395, -1286.330403, 0.199855),		//marker nr 16
	//	Point3f(-671.607597, -1286.770799, 2.383148),	//marker nr 8
	//	Point3f(-679.344107, 141.059130, -12.397022),	//marker nr 18
	//	Point3f(-671.136300, 1281.687343, 0.199886),	//marker nr 23
	//	Point3f(5.348128, 1281.746822, 0.211561),		//marker nr 22
	//	Point3f(671.136168, 1282.407420, 0.199931),		//marker nr 21
	//	Point3f(671.905068, 147.375353, -12.695638) };	//marker nr 20

	RefPattern[18].code = 19;
	RefPattern[18].x = -0.079021;
	RefPattern[18].y = -147.427491;
	RefPattern[18].z = -12.049359;

	RefPattern[16].code = 17;
	RefPattern[16].x = 671.605864;
	RefPattern[16].y = -1277.323964;
	RefPattern[16].z = -1.870671;

	RefPattern[15].code = 16;
	RefPattern[15].x = 0.629395;
	RefPattern[15].y = -1286.330403;
	RefPattern[15].z = 0.199855;

	RefPattern[7].code = 8;
	RefPattern[7].x = -671.607597;
	RefPattern[7].y = -1286.330403;
	RefPattern[7].z = 2.383148;

	RefPattern[17].code = 18;
	RefPattern[17].x = -679.344107;
	RefPattern[17].y = 141.059130;
	RefPattern[17].z = -12.397022;

	RefPattern[22].code = 23;
	RefPattern[22].x = -671.136300;
	RefPattern[22].y = 1281.687343;
	RefPattern[22].z = 0.199886;

	RefPattern[21].code = 22;
	RefPattern[21].x = 5.348128;
	RefPattern[21].y = 1281.746822;
	RefPattern[21].z = 0.211561;

	RefPattern[20].code = 21;
	RefPattern[20].x = 671.136168;
	RefPattern[20].y = 1282.407420;
	RefPattern[20].z = 0.199931;

	RefPattern[19].code = 20;
	RefPattern[19].x = 671.905068;
	RefPattern[19].y = 147.375353;
	RefPattern[19].z = -12.695638;

	// parametry wewnetrzne i zewnetrzne kamer z kalibracji
	loadCamParams(CAM_LEFT_PARAM_FILE, &cam1);
	loadCamParams(CAM_RIGHT_PARAM_FILE, &cam2);

	// przygotowanie sto�k�w kamer
	// kamera lewa (cam1)
	corners_cam1[0].el.x = (float)CAM_WIDTH;
	corners_cam1[0].el.y = 0.0;
	corners_cam1[0].el.z = 1.0;
	corners_cam1[0].el.w = 1.0;

	corners_cam1[1].el.x = 0.0;
	corners_cam1[1].el.y = 0.0;
	corners_cam1[1].el.z = 1.0;
	corners_cam1[1].el.w = 1.0;

	corners_cam1[2].el.x = (float)CAM_WIDTH;
	corners_cam1[2].el.y = (float)CAM_HEIGHT;
	corners_cam1[2].el.z = 1.0;
	corners_cam1[2].el.w = 1.0;

	corners_cam1[3].el.x = 0.0;
	corners_cam1[3].el.y = (float)CAM_HEIGHT;
	corners_cam1[3].el.z = 1.0;
	corners_cam1[3].el.w = 1.0;

	M4x1NS_SSE(cam1.Ainv, corners_cam1[0].raw, corners_cam1[0].raw, 4);
	for (size_t i = 0; i < 4; i++) {
		corners_cam1[i].el.x *= scale / corners_cam1[i].el.z;
		corners_cam1[i].el.y *= scale / corners_cam1[i].el.z;
		corners_cam1[i].el.z = scale;
	}
	M4x1NS_SSE(cam1.RT, corners_cam1[0].raw, corners_cam1[0].raw, 4);

	// kamera prawa (cam2)
	corners_cam2[0].el.x = (float)CAM_WIDTH;
	corners_cam2[0].el.y = 0.0;
	corners_cam2[0].el.z = 1.0;
	corners_cam2[0].el.w = 1.0;

	corners_cam2[1].el.x = 0.0;
	corners_cam2[1].el.y = 0.0;
	corners_cam2[1].el.z = 1.0;
	corners_cam2[1].el.w = 1.0;

	corners_cam2[2].el.x = (float)CAM_WIDTH;
	corners_cam2[2].el.y = (float)CAM_HEIGHT;
	corners_cam2[2].el.z = 1.0;
	corners_cam2[2].el.w = 1.0;

	corners_cam2[3].el.x = 0.0;
	corners_cam2[3].el.y = (float)CAM_HEIGHT;
	corners_cam2[3].el.z = 1.0;
	corners_cam2[3].el.w = 1.0;

	M4x1NS_SSE(cam2.Ainv, corners_cam2[0].raw, corners_cam2[0].raw, 4);
	for (size_t i = 0; i < 4; i++) {
		corners_cam2[i].el.x *= scale / corners_cam2[i].el.z;
		corners_cam2[i].el.y *= scale / corners_cam2[i].el.z;
		corners_cam2[i].el.z = scale;
	}
	M4x1NS_SSE(cam2.RT, corners_cam2[0].raw, corners_cam2[0].raw, 4);

	// do wizualizacji
	refresh3Dobjects(&cam1);
	refresh3Dobjects(&cam2);

	odprintf("\n[INFO] Wczytano stare parametry kamer z plikow\n");

	// watki nieskonczone

	_beginthread(liveFeed, 0, (void*)&cam1); // cam L
	_beginthread(liveFeed, 0, (void*)&cam2); // cam P
	Sleep(200);
	_beginthread(liveDataProcessing, 0, nullptr);

}

bool loadCamParams(int8* fileName, pCamera cam)
{
	// load camera parameters from binary file
	CamData	cd = { 0 };
	FILE* file = nullptr;
	uint32	fLen = 0;
	errno_t	ferr = 0;

	char workingDir[200];
	if (_getcwd(workingDir, sizeof(workingDir)) != NULL) {
		odprintf("[Info] Working dir: %s\n", workingDir);
		odprintf("[Info] Relative file path: %s\n", fileName);
	}
	else {
		perror("getcwd() error");
	}

	// Binary read paramaters from file into struct
	ferr = fopen_s(&file, fileName, "rb");
	if (file != NULL && !ferr) {
		fseek(file, 0, SEEK_END);
		fLen = ftell(file);
		fseek(file, 0, SEEK_SET);
		if (fLen < sizeof(CamData)) {
			if (file != NULL) fclose(file);
			return false;
		}
		else fread(&cd, sizeof(CamData), 1, file);
		fclose(file);
	}
	else return false;

	// Set 1.0 in last elements
	cam->A[15] = 1.0f; cam->RT[15] = 1.0f; cam->R[15] = 1.0f; cam->RTinv[15] = 1.0f;

	cam->Ac = Mat::zeros(3, 3, CV_32F);
	cam->Kc = Mat::zeros(5, 1, CV_32F);
	// Set camera matrix
	cam->A[0] = cd.a11;
	cam->A[1] = cd.a12;
	cam->A[2] = cd.a13;
	cam->A[4] = cd.a21;
	cam->A[5] = cd.a22;
	cam->A[6] = cd.a23;
	cam->A[8] = cd.a31;
	cam->A[9] = cd.a32;
	cam->A[10] = cd.a33;

	I4x4_SSE(cam->A, cam->Ainv);

	// Set distortion coefficients
	cam->K[0] = cd.k1;
	cam->K[1] = cd.k2;
	cam->K[2] = cd.k3;
	cam->K[3] = cd.k4;
	cam->K[4] = cd.k5;

	// camera matrices for Undistort()
	cam->Ac.at<float>(0) = cd.a11;
	cam->Ac.at<float>(1) = cd.a12;
	cam->Ac.at<float>(2) = cd.a13;
	cam->Ac.at<float>(3) = cd.a21;
	cam->Ac.at<float>(4) = cd.a22;
	cam->Ac.at<float>(5) = cd.a23;
	cam->Ac.at<float>(6) = cd.a31;
	cam->Ac.at<float>(7) = cd.a32;
	cam->Ac.at<float>(8) = cd.a33;
	cam->Kc.at<float>(0) = cd.k1;
	cam->Kc.at<float>(1) = cd.k2;
	cam->Kc.at<float>(2) = cd.k3;
	cam->Kc.at<float>(3) = cd.k4;
	cam->Kc.at<float>(4) = cd.k5;
	printMatFloat("Ac(undist)", cam->Ac);
	printMatFloat("Kc(undist)", cam->Kc);

	cam->RT[0] = cam->R[0] = cd.r11;
	cam->RT[1] = cam->R[1] = cd.r12;
	cam->RT[2] = cam->R[2] = cd.r13;
	cam->RT[4] = cam->R[4] = cd.r21;
	cam->RT[5] = cam->R[5] = cd.r22;
	cam->RT[6] = cam->R[6] = cd.r23;
	cam->RT[8] = cam->R[8] = cd.r31;
	cam->RT[9] = cam->R[9] = cd.r32;
	cam->RT[10] = cam->R[10] = cd.r33;

	I4x4_SSE(cam->RT, cam->RTinv);
	cam->RT[3] = cd.t11; cam->RT[7] = cd.t21; cam->RT[11] = cd.t31;

	cam->T[0] = -cd.t11;
	cam->T[1] = -cd.t21; // (-T)
	cam->T[2] = -cd.t31;
	cam->T[3] = 1.0;

	M4x1_SSE(cam->RTinv, cam->T, cam->Tinv); // Tinv = Rinv*-T

	cam->T[0] = cd.t11;
	cam->T[1] = cd.t21; // T
	cam->T[2] = cd.t31;
	cam->T[3] = 1.0;

	cam->RTinv[3] = cam->Tinv[0];
	cam->RTinv[7] = cam->Tinv[1];
	cam->RTinv[11] = cam->Tinv[2];

	printCamParams(cam);

	return true;
}