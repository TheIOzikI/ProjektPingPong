
// Ping pong tracking project v1 by Oskar Lusiński

#include "init_system_fcn.h"
#include "main_threads.h"
#include "main.h"
#include "print_fcn.h"

#ifdef DEBUG
#pragma comment (lib, "opencv_world348d.lib")
#else
#pragma comment (lib, "opencv_world348.lib")
#endif

// definicje struktur
Camera cam1 = { 0 }, cam2 = { 0 };
LogicalVariables logicVariables; // wszystkie zmienne logiczne i tryby
ApplicationWindows appWindows;

double dT; // wyliczony czas trwania petli głównej

HANDLE serialHandle;
CRITICAL_SECTION cs, cs2;

// main application loop
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ INT nCmdShow)
{
	MSG	msg;
	CvFont font, font2;
	WNDCLASSW wc = { 0 }, rwc = { 0 }, lwc = { 0 }, prj = { 0 }, cwc = { 0 }, ewc = { 0 };
	HBRUSH background = GetSysColorBrush(COLOR_3DFACE);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = L"MainWindow";
	wc.hInstance = hInstance;
	wc.hbrBackground = background;
	wc.lpfnWndProc = (WNDPROC)wndProc;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	RegisterClassW(&wc);

	rwc.lpszClassName = L"Cam1CVImage";
	rwc.hbrBackground = background;
	rwc.lpfnWndProc = (WNDPROC)panelProc;
	rwc.hCursor = LoadCursor(0, IDC_ARROW);
	RegisterClassW(&rwc);

	lwc.lpszClassName = L"Cam2CVImage";
	lwc.hbrBackground = background;
	lwc.lpfnWndProc = (WNDPROC)panelProc;
	lwc.hCursor = LoadCursor(0, IDC_ARROW);
	RegisterClassW(&lwc);

	cwc.style = CS_DBLCLKS;
	cwc.lpszClassName = L"3DCVImage";
	cwc.hbrBackground = background;
	cwc.lpfnWndProc = (WNDPROC)view3DProc;
	cwc.hCursor = LoadCursor(0, IDC_ARROW);
	RegisterClassW(&cwc);

	bool csr = InitializeCriticalSectionAndSpinCount(&cs, 0x00000200);
	bool csr2 = InitializeCriticalSectionAndSpinCount(&cs2, 0x00000300);
	if (csr == 0 || csr2 == 0) odprintf("\n[Info] Error Initialize Critical Section");

	srand((uint32)time(nullptr));

	cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 5, 5, 0.0, 15, CV_AA);
	cvInitFont(&font2, CV_FONT_HERSHEY_SIMPLEX, 6, 6, 0.0, 18, CV_AA);

	appWindows.mainWindow = CreateWindowExW(0UL, wc.lpszClassName, L"PING PONG TRACKING",
		WS_POPUP | WS_VISIBLE, 0, 0, 1920, 1080, nullptr, nullptr, hInstance, nullptr);
	ShowWindow(appWindows.mainWindow, nCmdShow);
	UpdateWindow(appWindows.mainWindow);

	// change GetMessage to PeekMessage for DirectX
	while (1) {
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			// translate the message and dispatch it to WindowProc()
			if (msg.message == WM_QUIT) break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (msg.message == WM_QUIT) break;
	}

	DeleteCriticalSection(&cs);
	DeleteCriticalSection(&cs2);

	cleanD3D();	// clean up DirectX and COM

	return (int32)msg.wParam;
}

LRESULT CALLBACK wndProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam)
{
	static HBRUSH HBR_BTN_INFO = CreateSolidBrush(RGB(255, 0, 0));
	COLORREF bgColor = RGB(255, 0, 0);

	// pozycja zapamietywana z suwakow
	LRESULT tmp_s_pos = CAM_EXP_MAX + CAM_EXP_MIN - CAM_EXP_DEFAULT;

	switch (msg)
	{
	case WM_CREATE:]
	{
		HWND control, child, parent;
		HFONT hFont = CreateFontW(22, 0, 0, 0, 600, 0, 0, 0, 0, 1, 1, 2, VARIABLE_PITCH | FF_SWISS, L"Tahoma");
		uint16 pos_x = 2, pos_y = BTN_HEIGHT;
		uint8 i;
		RECT rc;
		GetWindowRect(hwnd, &rc); // center main window

		SetWindowPos(hwnd, 0,
			(GetSystemMetrics(SM_CXSCREEN) - rc.right) / 2, // dla 2 monitorów jest "+" -> wtedy aplikacja otwiera się na drugim monitorze
			(GetSystemMetrics(SM_CYSCREEN) - rc.bottom) / 2,
			0, 0, SWP_NOZORDER | SWP_NOSIZE);

		// generate menu buttons
		for (i = 0; i < MENU_ITEM_NUM; ++i) {
			if (i >= 11 && i <= 13) {
				appWindows.menu_item_handle[i] = CreateWindowExW(0L, L"button", appWindows.NamedButtons.menu_item_names[i], WS_VISIBLE | WS_CHILD | BS_MULTILINE,
					int(80 + CAM_WINDOW_WIDTH + CAM_WINDOW_HEIGHT * 2.5 + 10), 20 + pos_y, BTN_HEIGHT, BTN_HEIGHT, hwnd, (HMENU)i, NULL, NULL);
				SendMessage(appWindows.menu_item_handle[i], WM_SETFONT, (WPARAM)hFont, TRUE);
				pos_y += BTN_HEIGHT + 4;
			}
			else {
				appWindows.menu_item_handle[i] = CreateWindowExW(0L, L"button", appWindows.NamedButtons.menu_item_names[i], WS_VISIBLE | WS_CHILD | BS_MULTILINE,
					155 / 2 + pos_x + 28, 10, BTN_WIDTH, BTN_HEIGHT, hwnd, (HMENU)i, NULL, NULL);
				SendMessage(appWindows.menu_item_handle[i], WM_SETFONT, (WPARAM)hFont, TRUE);
				if (i == 4) pos_x += BTN_WIDTH + 120 - 155 / 2;
				else pos_x += BTN_WIDTH + 4;
			}
			if (!appWindows.NamedButtons.menu_item_enabled[i]) disableButton(i);
		}

		// right cam window
		control = CreateWindowExW(0L, L"Cam1CVImage", NULL, WS_CHILD | WS_VISIBLE,
			80, BTN_HEIGHT + 20, CAM_WINDOW_WIDTH, CAM_WINDOW_HEIGHT,
			hwnd, (HMENU)i++, NULL, NULL);

		cvNamedWindow("Cam1CVImageWindow", CV_WINDOW_NORMAL);
		cvResizeWindow("Cam1CVImageWindow", CAM_WINDOW_WIDTH, CAM_WINDOW_HEIGHT);
		child = (HWND)cvGetWindowHandle("Cam1CVImageWindow");
		parent = GetParent(child);
		SetParent(child, control);
		ShowWindow(parent, SW_HIDE);

		// left cam window
		control = CreateWindowExW(0L, L"Cam2CVImage", NULL, WS_CHILD | WS_VISIBLE,
			80, BTN_HEIGHT + CAM_WINDOW_HEIGHT + 20, CAM_WINDOW_WIDTH, CAM_WINDOW_HEIGHT,
			hwnd, (HMENU)i++, NULL, NULL);

		cvNamedWindow("Cam2CVImageWindow", CV_WINDOW_NORMAL);
		cvResizeWindow("Cam2CVImageWindow", CAM_WINDOW_WIDTH, CAM_WINDOW_HEIGHT);
		child = (HWND)cvGetWindowHandle("Cam2CVImageWindow");
		parent = GetParent(child);
		SetParent(child, control);
		ShowWindow(parent, SW_HIDE);

		// exposure trackbar
		appWindows.s_expTrackbar = CreateWindowExW(0L, TRACKBAR_CLASS, L"Trackbar", WS_CHILD | WS_VISIBLE | TBS_VERT | TBS_AUTOTICKS | TBS_DOWNISLEFT | TBS_REVERSED,
			20, BTN_HEIGHT + 20, 30, CAM_WINDOW_HEIGHT * 2 - 10, hwnd, (HMENU)i++, NULL, NULL);
		SendMessage(appWindows.s_expTrackbar, TBM_SETRANGEMIN, TRUE, CAM_EXP_MIN);
		SendMessage(appWindows.s_expTrackbar, TBM_SETRANGEMAX, TRUE, CAM_EXP_MAX);
		SendMessage(appWindows.s_expTrackbar, TBM_SETPAGESIZE, 0, 1000);
		SendMessage(appWindows.s_expTrackbar, TBM_SETTICFREQ, 1000, 0);
		SendMessage(appWindows.s_expTrackbar, TBM_SETPOS, TRUE, CAM_EXP_MAX + CAM_EXP_MIN - CAM_EXP_DEFAULT);

		// DirectX accelerated 3D view window
		appWindows.panel3D = CreateWindowExW(0L, L"3DCVImage", NULL, WS_CHILD | WS_VISIBLE,
			80 + CAM_WINDOW_WIDTH, BTN_HEIGHT + 20, int(CAM_WINDOW_HEIGHT * 2.5), CAM_WINDOW_HEIGHT * 2,
			hwnd, (HMENU)i++, NULL, NULL);

		// connect preview window with camera struct
		strcpy_s(cam1.window, 32, "Cam1CVImageWindow");
		strcpy_s(cam2.window, 32, "Cam2CVImageWindow");

		_beginthread(tryInitCameras, 0, nullptr);
	}
	break;

	case WM_KEYDOWN:
		PostMessageW(appWindows.panel3D, msg, wParam, lParam);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {

			// przycisk nr 1! - 
		case MNU_EMPTY_1:

			break;

			// przycisk nr 2! - 
		case MNU_EMPTY_2:

			break;

			// przycisk nr 3! - 
		case MNU_EMPTY_3:

			break;

			// przycisk nr 4! - 
		case MNU_EMPTY_4:

			break;

			// przycisk nr 5! - 
		case MNU_EMPTY_5:

			break;

			// przycisk nr 6! - zapis zdjęcia L
		case MNU_SAVE_PIC_1:
			logicVariables.save_img_1 = true;
			break;

			// przycisk nr 7! - zapis zdjęcia R
		case MNU_SAVE_PIC_2:
			logicVariables.save_img_2 = true;
			break;

			// przycisk nr 8! - zmiana koloru markerów
		case MNU_MKR_COLOR:
			logicVariables.mkr_color = !logicVariables.mkr_color;
			break;

			// przycisk nr 9! - autoekspozycja
		case MNU_AUTOEXP:
			logicVariables.auto_exp = !logicVariables.auto_exp;
			break;

			// przycisk nr 10! - wybór wyswietlania obrazu: kolor/binarny
		case MNU_IMG_DISPLAY:
			logicVariables.imdisp++;
			if (logicVariables.imdisp > 1) logicVariables.imdisp = 0;
			break;

			// przycisk nr 11! - wyłączenie systemu
		case MNU_QUIT:
			odprintf("\n[Info] KONIEC PROGRAMU!\n");
			logicVariables.stop_exe = true;
			Sleep(50);
			cam1.mk_lock = true;
			cam2.mk_lock = true;
			Sleep(50);
			terminateCameras(0);
			Sleep(50);
			cvDestroyAllWindows();
			PostQuitMessage(0);
			break;

			// przycisk nr 12! - 
		case MNU_XY:
			appWindows.camZrot = DEFAULT_ROT_Z;
			appWindows.camYrot = DEFAULT_ROT_Y;
			appWindows.camXrot = -PI2;
			logicVariables.view_rotation = 0;
			break;

			// przycisk nr 13! - 
		case MNU_YZ:
			appWindows.camZrot = PI2;
			appWindows.camYrot = DEFAULT_ROT_Y;
			appWindows.camXrot = DEFAULT_ROT_X;
			logicVariables.view_rotation = 1;
			break;

			// przycisk nr 14! -
		case MNU_XZ:
			appWindows.camZrot = DEFAULT_ROT_Z;
			appWindows.camYrot = DEFAULT_ROT_Y;
			appWindows.camXrot = DEFAULT_ROT_X;
			logicVariables.view_rotation = 2;
			break;
		}
		break;

	case WM_DRAWITEM:
		break;

	case WM_CTLCOLORBTN:
		return (LRESULT)CreateSolidBrush(bgColor);
		break;

	case WM_VSCROLL:
		if ((wParam & 0xffff) == 0x0008) {
			LRESULT s_pos = SendMessageW(appWindows.s_expTrackbar, TBM_GETPOS, 0, 0); // dla skanowania
			if (s_pos - tmp_s_pos != 0) { // wykrycie zmiany polozenia
				logicVariables.auto_exp = false;
				cam1.s_exp_time = CAM_EXP_MAX + CAM_EXP_MIN - s_pos;
				cam2.s_exp_time = CAM_EXP_MAX + CAM_EXP_MIN - s_pos;
				setExposure(cam1.s_exp_time, 1);
				setExposure(cam2.s_exp_time, 2);
				//odprintf("[Info] New scanning exposure %lld\n", cam1.s_exp_time);
			}
			tmp_s_pos = s_pos; // zapamietanie poprzedniej pozycji 
		}
		break;

	case WM_DESTROY:
		// Cleanup, Close and release Camera devices.
		terminateCameras(0);
		// Cleanup OpenCV window instances
		cvDestroyAllWindows();
		PostQuitMessage(0);
		break;
	}
	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK panelProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONUP:
		//odprintf("[Info] Left Clicked on Image\n");
		break;
	}
	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK view3DProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam)
{
	HDC	hdc; // handle to device context
	CHAR wheelSign; // zoom in/out
	RECT rcClient; // client area rectangle 
	POINT ptClientUL; // client upper left corner 
	POINT ptClientLR; // client lower right corner
	POINTS delta, end; // points
	static POINTS start; // static points

	switch (msg) {
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
		ClipCursor(NULL);
		ReleaseCapture();
		break;

	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:

		SetCapture(hwnd); // Capture mouse input

		// Retrieve the screen coordinates of the client area, and convert them into client coordinates. 
		GetClientRect(hwnd, &rcClient);
		ptClientUL.x = rcClient.left;
		ptClientUL.y = rcClient.top;

		// Add one to the right and bottom sides, because the coordinates retrieved by GetClientRect do not 
		// include the far left and lowermost pixels. 
		ptClientLR.x = rcClient.right + 1;
		ptClientLR.y = rcClient.bottom + 1;
		ClientToScreen(hwnd, &ptClientUL);
		ClientToScreen(hwnd, &ptClientLR);

		// Copy the client coordinates of the client area to the rcClient structure. Confine the mouse cursor 
		// to the client area by passing the rcClient structure to the ClipCursor function. 
		SetRect(&rcClient, ptClientUL.x, ptClientUL.y, ptClientLR.x, ptClientLR.y);
		ClipCursor(&rcClient);

		// Convert the cursor coordinates into a POINTS structure, which defines the beg
		start = MAKEPOINTS(lParam);
		//odprintf("[Mouse] x: %d, y: %d\n", start.x, start.y);
		break;

	case WM_MOUSEMOVE:
		if (wParam & MK_LBUTTON) { // sterowanie obrotem sceny
			// Retrieve a device context (DC) for the client area. 
			hdc = GetDC(hwnd);
			// Convert the current cursor coordinates to a POINTS structure.
			end = MAKEPOINTS(lParam);
			delta.x = end.x - start.x;
			delta.y = end.y - start.y;
			//odprintf("[Mouse] dx: %d, dy: %d\n", delta.x, delta.y);
			appWindows.camZrot += (float)delta.x / 75.0f;
			appWindows.camXrot -= (float)delta.y / 75.0f;
			if (appWindows.camZrot > 360.0f) appWindows.camZrot -= 360.0f;
			if (appWindows.camXrot > 360.0f) appWindows.camXrot -= 360.0f;
			start.x = end.x;
			start.y = end.y;
			ReleaseDC(hwnd, hdc);
		}
		if (wParam & MK_RBUTTON) { // sterowanie przesuwaniem sceny
			hdc = GetDC(hwnd);
			end = MAKEPOINTS(lParam);
			delta.x = end.x - start.x;
			delta.y = end.y - start.y;
			if (delta.x >= 3) appWindows.transX -= 15.0f;
			else if (delta.x <= -3) appWindows.transX += 15.0f;
			if (delta.y >= 3) appWindows.transZ -= 20.0f;
			else if (delta.y <= -3) appWindows.transZ += 20.0f;
			start.x = end.x;
			start.y = end.y;
			ReleaseDC(hwnd, hdc);
		}
		break;

	case WM_MOUSEWHEEL:
	{
		//odprintf("[Mouse] Wheel: %d\n", (SHORT)HIWORD(wParam));
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hwnd, &pt);
		wheelSign = (int16)HIWORD(wParam) / abs((int16)HIWORD(wParam));
		appWindows.mouse_zoom -= (float)wheelSign * 0.3f; // bylo * pow(2.0f, 0.2f)
		//odprintf("mouse_zoom = %f\n", mouse_zoom);
		if (appWindows.mouse_zoom < 1.0f) appWindows.mouse_zoom = 1.0f;
	}
	break;

	case WM_LBUTTONDBLCLK:
		appWindows.camZrot = DEFAULT_ROT_Z;
		appWindows.camYrot = DEFAULT_ROT_Y;
		appWindows.camXrot = DEFAULT_ROT_X;
		appWindows.camZmov = 0.0;
		appWindows.camXmov = 0.0;
		appWindows.camYmov = DEFAULT_MOV_Y;
		appWindows.transX = 0.0;
		appWindows.transZ = 0.0;
		appWindows.mouse_zoom = 1.0;
		break;
	}
	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void setAllButtons(bool st)
{
	if (st) {
		enableButton(MNU_EMPTY_1);
		enableButton(MNU_EMPTY_2);
		enableButton(MNU_EMPTY_3);
		enableButton(MNU_EMPTY_4);
		enableButton(MNU_EMPTY_5);
		enableButton(MNU_SAVE_PIC_1);
		enableButton(MNU_SAVE_PIC_2);
		enableButton(MNU_MKR_COLOR);
		enableButton(MNU_AUTOEXP);
		enableButton(MNU_IMG_DISPLAY);
		enableButton(MNU_QUIT);
	}
	else {
		disableButton(MNU_EMPTY_1);
		disableButton(MNU_EMPTY_2);
		disableButton(MNU_EMPTY_3);
		disableButton(MNU_EMPTY_4);
		disableButton(MNU_EMPTY_5);
		disableButton(MNU_SAVE_PIC_1);
		disableButton(MNU_SAVE_PIC_2);
		disableButton(MNU_MKR_COLOR);
		disableButton(MNU_AUTOEXP);
		disableButton(MNU_IMG_DISPLAY);
		disableButton(MNU_QUIT);
	}
}