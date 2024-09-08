#pragma once

#include "math_fcn.h"
#include <d3dx9.h>
#include <direct.h>
#include <pylonc/PylonC.h>
#include <fstream>
#include <iomanip>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <commctrl.h> // wykorzystane do trackbara
#include <crtdefs.h>
#include <process.h>
#include <Eigen/Dense>
#include <vector>
#include <cmath>

using namespace cv;
using namespace std;
using namespace Eigen;

#define null				((void *)0)
#define true				1
#define false				0

typedef char				int8;
typedef short				int16;
typedef long				int32;
typedef long long			int64;

typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned long		uint32;
typedef unsigned long long	uint64;

#define enableButton(itm)	EnableWindow(appWindows.menu_item_handle[(itm)], 1);
#define disableButton(itm)	EnableWindow(appWindows.menu_item_handle[(itm)], 0);

#define D3DGRAY(v)			D3DCOLOR_ARGB(0xff,v,v,v)

// files options
#define CAM_LEFT_PARAM_FILE  "config\\LEFT_cam_param.bin" // actual camera parameters
#define CAM_RIGHT_PARAM_FILE "config\\RIGHT_cam_param.bin" // actual camera parameters

// camera parameters
#define NUM_BUFFERS			1
#define CAM_LEFT_SERIAL		"21858830" // duze baslery USB
#define CAM_RIGHT_SERIAL	"21562281" // duze baslery USB
#define CAM_WIDTH			1920U
#define CAM_HEIGHT		    1200U
#define CAM_WIDTH2			CAM_WIDTH/2.0f
#define CAM_HEIGHT2		    CAM_HEIGHT/2.0f
#define MIN_SCALE			4U  //musi byc dzielnikiem bez reszty dla rozdzielczosci kamery
#define MIN_SCALE3			3*MIN_SCALE
#define MIN_SCALEW			MIN_SCALE*CAM_WIDTH
#define MIN_SCALE3W			3*MIN_SCALE*CAM_WIDTH
#define H_PX				(CAM_HEIGHT/MIN_SCALE - 1U)   
#define W_PX				(CAM_WIDTH/MIN_SCALE - 1U) 
#define CAM_PIX				CAM_WIDTH*CAM_HEIGHT

//////////zmienione na logicvariable guziki
//#define DT					100.0f // 80 [ms] czas trwania petli w watku glównym 25FPS
//#define DT					25.0f // 25 [ms] czas trwania petli w watku glównym 40FPS
#define PREDICTION_TIME		2 //ile sekund wyprzedzić predykcje


// exposure parameters
#define CAM_EXP_MIN			1000U		
#define CAM_EXP_MAX			20000U		
#define CAM_EXP_DEFAULT		2000U		
#define CAM_GAIN_DEFAULT	5
#define CAM_GAMMA			1.5

// markers parameters
#define TR_MARKER			15U
#define BIN_THRESHOLD		60 // binarization threshold for markers // 60
#define MKR_PIX_ERR		    1.0 // blad centrycznosci pol markera
#define MKR_MIN_RATIO       0.4 // stosunki srednic
#define MKR_MAX_RATIO       0.7
#define MKR_RECON_ERR		100.0 // duzy blad ustawiony!!!!!!!!
#define MKR_COLOR			1 // 0=czarny srodek, 1=bialy srodek
#define MIN_RECT_RATIO		0.7/1.0
#define MAX_RECT_RATIO		1.0/0.7
#define MIN_CODE			0
#define MAX_CODE			56
#define CODE_AREA			6

// windows parameters
#define CAM_WINDOW_HEIGHT	450U
#define CAM_WINDOW_WIDTH	(uint32)((float)CAM_WIDTH/((float)CAM_HEIGHT/(float)CAM_WINDOW_HEIGHT))
#define BTN_WIDTH			155
#define BTN_HEIGHT			80
#define DEFAULT_ROT_X		0.0
#define DEFAULT_ROT_Y		0.0
#define DEFAULT_ROT_Z		3.141592653589793f
#define DEFAULT_MOV_Y		1000.0
#define FAR_VIEW_PLANE		15.0 * DEFAULT_MOV_Y
#define COORD_LINE_W_LEN	(DEFAULT_MOV_Y/2.5)
#define COORD_LINE_CAM		500.0f
#define COORD_LINE_CALIB	500.0f

// menu parameters
#define MENU_ITEM_NUM		14

#define MNU_EMPTY_1			0
#define MNU_EMPTY_2			1
#define MNU_EMPTY_3			2
#define MNU_EMPTY_4			3
#define MNU_EMPTY_5			4
#define MNU_SAVE_PIC_1		5
#define MNU_SAVE_PIC_2		6
#define MNU_MKR_COLOR		7
#define MNU_AUTOEXP			8
#define MNU_IMG_DISPLAY 	9
#define MNU_QUIT			10
#define MNU_XY				11
#define MNU_YZ				12
#define MNU_XZ				13

struct ApplicationWindows {

	struct NamedButtons {
		wchar_t* menu_item_names[14];
		bool menu_item_enabled[14];
	} NamedButtons = {
		{ // inicjalizacja tablicy appWindows.menu_buttons.named_buttons.menu_item_names
			L"Kalibracja par. zewnętrznych", L"Typ predykcji", L"Rysowanie trajektorii", L"-5 FPS", L"+5 FPS", L"Zapis zdjęcia CAM L", L"Zapis zdjęcia CAM R", L"Zmiana koloru markera", 
			L"Autoekspozycja", L"Typ obrazów",L"Zakończ pracę",  L"widok XY", L"widok YZ", L"widok XZ"
		},
		{ // inicjalizacja tablicy menu_item_enabled -> status przycisków (1 - aktywny, 0 - nieaktywny)
			true, true, true, true, true, true, true, true, true, true, true, true, true, true
		}
	};

	float camXrot = DEFAULT_ROT_X, // camera rotation
		camYrot = DEFAULT_ROT_Y,
		camZrot = DEFAULT_ROT_Z,
		camXmov = 0.0f, // camera position
		camYmov = DEFAULT_MOV_Y,
		camZmov = 0.0f,
		transX = 0.0f,
		transZ = 0.0f,
		mouse_zoom = 1.0f;

	HWND menu_item_handle[MENU_ITEM_NUM], mainWindow, // glowne okno aplikacji
		static_axis_box, static_val_box, panel3D, // okno 3D
		static_val_box_0, static_name_box_0, static_name_box_1,
		static_name_box_2, static_name_box_3, readEncodersWindow,
		projWindow, s_expTrackbar = nullptr; // ekran projektora
	HFONT hFont_static_1 = CreateFontW(35, 0, 0, 0, 700, 0, 0, 0, 0, 1, 1, 2, VARIABLE_PITCH | FF_SWISS, L"Tahoma"),
		hFont_static_2 = CreateFontW(25, 0, 0, 0, 700, 0, 0, 0, 0, 1, 1, 2, VARIABLE_PITCH | FF_SWISS, L"Tahoma"),
		hFont_txt = CreateFontW(35, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, VARIABLE_PITCH | FF_SWISS, L"Tahoma");
};

struct LogicalVariables {
	uint8 view_rotation = 2, imdisp = 0, // zmienna wybierająca sposob wyswietlania obrazów
		fps = 40, prediction = 0; // zmiana fps, przełączanie typu predykcji
	bool stop_exe = false, save_img_1 = false, save_img_2 = false,
		auto_exp = false, mkr_color = false, // 0 (false) = czarny srodek  1 (true) = bialy srodek
		trajectory = true; // wyświetlanie trajektorii
};

// strukura dla markerow plaskich na obrazie
typedef struct _Marker {
	bool isSet{};
	uint8 code{};
	float x{}, y{};
	CvBox2D elypse{};
} Marker, FAR* lpMarker, * pMarker;

// strukturka przechowujaca markery po rekonstrukcji
typedef struct _Marker3D {
	bool isSet[56];
	uint8 code[56];
	float x[56], y[56], z[56], err[56];
} Marker3D, far* lpMarker3D, * pMarker3D;

// struktura dla rekonstrukcji markerów
typedef union _Point4 {
	float raw[4];
	struct {
		float x, y, z, w;
	} el;
} Point4, far* lpPoint4, * pPoint4;

//struktura dla przechowywania punktów trajektorii piłki
struct prevPoints3D {
	vector<float> x;
	vector<float> y;
	vector<float> z;
	int cycles;
};

//struktura przechowująca punkty przecinające płaszczyzne Y
struct CrossPlanePoints {
	vector<float> x;
	vector<float> y;
	vector<float> z;
};

struct EstimatedPoints {
	vector<double> x;
	vector<double> y;
	vector<double> z;
};

struct PredictedPoints {
	vector<vector<double>> x;
	vector<vector<double>> y;
	vector<vector<double>> z;
};

// Struktura dla markerów xreferencyjnych z krzyża kalibracyjnego
struct xRef {
	unsigned long code;
	float x, y, z;
};

// struktura kamery
typedef struct _Camera {
	int8 id[16], cam_num, window[32];
	uint8 br_max, br_max_buff;
	bool mk_lock;
	double Ti;
	float A[16], Ainv[16], // algn(16)
		R[16], RT[16], RTinv[16],
		T[4], Tinv[4],
		K[5], W1[16], W2[16];
	float vMap[CAM_PIX], hMap[CAM_PIX], calib_err_2D, calib_err_3D;
	PYLON_DEVICE_HANDLE hdl;
	PYLON_STREAMGRABBER_HANDLE stream;
	PYLON_WAITOBJECT_HANDLE	wait;
	PYLON_STREAMBUFFER_HANDLE streamBuff[NUM_BUFFERS];
	uint8 status, * grabBuff[NUM_BUFFERS], * buffer;
	Mat Kc, Ac, grayImg, colorImg;
	Point2f ballCenter;
	uint64 s_exp_time, savedExp;
	Marker coded_markers[56] = { 0 };
	Marker coded_markers_buff[56] = { 0 };
	D3DXMATRIX rotation; // DirectX
} Camera, far* lpCamera, * pCamera;

typedef struct _CamData {
	float a11, a12, a13, a21, a22, a23, a31, a32, a33,
		k1, k2, k3, k4, k5,
		r11, r12, r13, r21, r22, r23, r31, r32, r33,
		t11, t21, t31;
} CamData, FAR* lpCamData, * pCamData;

// const indices for fast 3x3 -> 4x4 conversion
static const int ind9to16[9] = { 0, 1, 2, 4, 5, 6, 8, 9, 10 };

// WinAPI callbacks
LRESULT CALLBACK wndProc(HWND, uint32, WPARAM, LPARAM); // main window message callback
LRESULT CALLBACK panelProc(HWND, uint32, WPARAM, LPARAM); // cameras preview callback
LRESULT CALLBACK view3DProc(HWND, uint32, WPARAM, LPARAM); // 3D view window callback

// function prototypes
void setAllButtons(int);