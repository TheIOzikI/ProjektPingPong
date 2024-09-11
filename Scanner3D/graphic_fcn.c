#include "graphic_fcn.h"
#include "main.h"

LPDIRECT3DDEVICE9 d3ddev; // the pointer to the device class
LPDIRECT3DVERTEXBUFFER9 v_buffer = NULL;
LPDIRECT3DINDEXBUFFER9 i_buffer = NULL;
LPDIRECT3D9	d3d; // the pointer to our Direct3D interface
LPD3DXMESH sphere_big, sphere_smallest, sphere_small, box_cam, tennis_table, tennis_table_net, pingpong;
ID3DXMesh* Text_L = 0, * Text_R = 0;
float camXat = 0.0f, camYat = 0.0f, camZat = 0.0f, scaleXYZ = 1.0f; // camera look at point

extern Camera cam1, cam2;
extern Marker3D m3d;
extern prevPoints3D prev_points;
extern double dT;
extern LogicalVariables logicVariables;
extern ApplicationWindows appWindows;
extern Point4 corners_cam1[4], corners_cam2[4];
extern MatrixXd prevPointsIn3f;
extern PredictedPoints predicted_point;
extern EstimatedPoints estimated_point;
extern CrossPlanePoints crossplanepoints;
extern polyfitPredictionPoints polyfit_points;
extern NewtonPoints predicted_points_newton;
extern RealPlanePoints realplanepoints;

void initGraphics(void)
{
	// this is the function that puts the 3D models into video RAM
	uint8* pVoid = nullptr, * pVoid2 = nullptr;
	DWORD col = D3DCOLOR_XRGB(0, 0, 0);
	float mn = 0.5;

	// create the vertices using the CUSTOMVERTEX struct
	CUSTOMVERTEX vertices[] = {
		// coordinate lines no. 1 (WORLD)
		{ -0.5f * COORD_LINE_W_LEN,  0.0f,  0.0f }, // x
		{ COORD_LINE_W_LEN,  0.0f,  0.0f },
		{ 0.0f, -0.5f * COORD_LINE_W_LEN,  0.0f }, // y
		{ 0.0f,  COORD_LINE_W_LEN,  0.0f },
		{ 0.0f,  0.0f, -0.5f * COORD_LINE_W_LEN }, // z
		{ 0.0f,  0.0f,  COORD_LINE_W_LEN },

		// coordinate lines no. 2 - camera 1 (RIGHT)
		{ -0.5f * COORD_LINE_CAM * mn,  0.0f,  0.0f }, // x
		{ COORD_LINE_CAM * mn,  0.0f,  0.0f },
		{ 0.0f, -0.5f * COORD_LINE_CAM * mn,  0.0f }, // y
		{ 0.0f,  COORD_LINE_CAM * mn,  0.0f },
		{ 0.0f,  0.0f, -0.5f * COORD_LINE_CAM * mn }, // z
		{ 0.0f,  0.0f,  COORD_LINE_CAM * mn },

		// coordinate lines no. 3 - camera 2 (LEFT)
		{ -0.5f * COORD_LINE_CAM * mn,  0.0f,  0.0f, float(D3DCOLOR_XRGB(255, 0, 0)) }, // x
		{ COORD_LINE_CAM * mn,  0.0f,  0.0f, float(D3DCOLOR_XRGB(255, 0, 0)) },
		{ 0.0f, -0.5f * COORD_LINE_CAM * mn,  0.0f, float(D3DCOLOR_XRGB(0, 255, 0)) }, // y
		{ 0.0f,  COORD_LINE_CAM * mn,  0.0f, float(D3DCOLOR_XRGB(0, 255, 0)) },
		{ 0.0f,  0.0f, -0.5f * COORD_LINE_CAM * mn, float(D3DCOLOR_XRGB(0, 255, 255)) }, // z
		{ 0.0f,  0.0f,  COORD_LINE_CAM * mn, float(D3DCOLOR_XRGB(0, 255, 255)) },

		// camera look no. 1 and no. 2
		{ cam1.T[0], cam1.T[1], cam1.T[2], 1.0, 1.0, 1.0 },
		{ cam1.T[0], cam1.T[1], cam1.T[2], 1.0, 1.0, 1.0 },
		{ cam1.T[0], cam1.T[1], cam1.T[2], 1.0, 1.0, 1.0 },
		{ cam1.T[0], cam1.T[1], cam1.T[2], 1.0, 1.0, 1.0 },
		{ corners_cam1[0].el.x, corners_cam1[0].el.y, corners_cam1[0].el.z, 1.0, 1.0, 1.0 },
		{ corners_cam1[1].el.x, corners_cam1[1].el.y, corners_cam1[1].el.z, 1.0, 1.0, 1.0 },
		{ corners_cam1[2].el.x, corners_cam1[2].el.y, corners_cam1[2].el.z, 1.0, 1.0, 1.0 },
		{ corners_cam1[3].el.x, corners_cam1[3].el.y, corners_cam1[3].el.z, 1.0, 1.0, 1.0 },

		// camera look no. 1 and no. 2
		{ cam2.T[0], cam2.T[1], cam2.T[2], 1.0, 1.0, 1.0 },
		{ cam2.T[0], cam2.T[1], cam2.T[2], 1.0, 1.0, 1.0 },
		{ cam2.T[0], cam2.T[1], cam2.T[2], 1.0, 1.0, 1.0 },
		{ cam2.T[0], cam2.T[1], cam2.T[2], 1.0, 1.0, 1.0 },
		{ corners_cam2[0].el.x, corners_cam2[0].el.y, corners_cam2[0].el.z, 1.0, 1.0, 1.0 },
		{ corners_cam2[1].el.x, corners_cam2[1].el.y, corners_cam2[1].el.z, 1.0, 1.0, 1.0 },
		{ corners_cam2[2].el.x, corners_cam2[2].el.y, corners_cam2[2].el.z, 1.0, 1.0, 1.0 },
		{ corners_cam2[3].el.x, corners_cam2[3].el.y, corners_cam2[3].el.z, 1.0, 1.0, 1.0 },
	};

	// for camera's cones - dla stożków
	short indices[] = {
		0, 1,
		0, 2,
		0, 4,
		1, 3,
		1, 5,
		2, 3,
		2, 6,
		3, 7,
		4, 5,
		4, 6,
		5, 7,
		6, 7,
	};

	// create a vertex buffer interface called v_buffer
	d3ddev->CreateVertexBuffer(20 * sizeof(vertices), 0, CUSTOMFVF, D3DPOOL_DEFAULT, &v_buffer, NULL);

	// lock v_buffer and load the vertices into it
	v_buffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices, sizeof(vertices));
	v_buffer->Unlock();

	d3ddev->CreateIndexBuffer(sizeof(indices), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &i_buffer, NULL);

	// lock i_buffer and load the indices into it
	i_buffer->Lock(0, 0, (void**)&pVoid2, 0);
	memcpy(pVoid2, indices, sizeof(indices));
	i_buffer->Unlock();
}

void cleanD3D(void)
{
	// this is the function that cleans up Direct3D and COM
	i_buffer->Release();
	v_buffer->Release(); // close and release the vertex buffer
	d3ddev->Release(); // close and release the 3D device
	d3d->Release(); // close and release Direct3D

	// bryły
	sphere_big->Release();
	sphere_small->Release();
	sphere_smallest->Release();
	box_cam->Release();
	tennis_table->Release();
	tennis_table_net->Release();
	pingpong->Release();
	Text_L->Release();
	Text_R->Release();
}

void initLight(void)
{
	// this is the function that sets up the lights and materials
	D3DLIGHT9 light; // create the light struct
	D3DMATERIAL9 material; // create the material struct

	ZeroMemory(&light, sizeof(light)); // clear out the light struct for use
	light.Type = D3DLIGHT_DIRECTIONAL; // make the light type 'directional light'
	light.Diffuse = D3DXCOLOR(0.5, 0.5, 0.5, 1.0);
	light.Direction = D3DXVECTOR3(0.0, -0.5, -1.0);

	d3ddev->SetLight(0, &light); // send the light struct properties to light #0
	d3ddev->LightEnable(0, TRUE); // turn on light #0

	ZeroMemory(&material, sizeof(D3DMATERIAL9)); // clear out the struct for use
	material.Diffuse = D3DXCOLOR(1.0, 1.0, 1.0, 1.0);
	material.Ambient = D3DXCOLOR(1.0, 1.0, 1.0, 1.0);
	d3ddev->SetMaterial(&material); // set the globably-used material to &material
}

void setColor(float diffuse_r, float diffuse_g, float diffuse_b, float diffuse_a, float ambient_r, float ambient_g, float ambient_b, float ambient_a)
{
	D3DMATERIAL9 material; // create the material struct
	ZeroMemory(&material, sizeof(D3DMATERIAL9)); // clear out the struct for use
	material.Diffuse = D3DXCOLOR(diffuse_r, diffuse_g, diffuse_b, diffuse_a);
	material.Ambient = D3DXCOLOR(ambient_r, ambient_g, ambient_b, ambient_a);
	d3ddev->SetMaterial(&material);
}

void createBlocks(void)
{
	D3DXCreateSphere(d3ddev, 20, 100, 100, &sphere_big, NULL); // markery duże - sfery
	D3DXCreateSphere(d3ddev, 10.0, 100, 100, &sphere_small, NULL); // markery małe - sfery
	D3DXCreateSphere(d3ddev, 2.0, 100, 100, &sphere_smallest, NULL); // markery tablica kalibracyjna - sfery
	D3DXCreateBox(d3ddev, 50.0, 50.0, 50.0, &box_cam, NULL); // kamera
	////////pingpong///////////////
	D3DXCreateBox(d3ddev, 1525.0f, 2740.0f, 2.0f, &tennis_table, NULL); // stół pingpongowy
	D3DXCreateBox(d3ddev, 1525.0f, 20.0f, 152.5f, &tennis_table_net, NULL); // siatka stół pingpongowy
	D3DXCreateSphere(d3ddev, 20.0f, 100, 100, &pingpong, NULL); // piłeczka pingpongowa 4cm srednicy
	///////////////////////////////

	HDC hdc = CreateCompatibleDC(0);
	LOGFONT lf;
	ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 25;
	lf.lfWidth = 12;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = 500;
	lf.lfItalic = false;
	lf.lfUnderline = false;
	lf.lfStrikeOut = false;
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfOutPrecision = 0;
	lf.lfClipPrecision = 0;
	lf.lfQuality = 0;
	lf.lfPitchAndFamily = 0;
	lf.lfFaceName, TEXT("Times New Roman");

	HFONT hFont2 = CreateFontIndirect(&lf), hFontOld = (HFONT)SelectObject(hdc, hFont2);

	D3DXCreateText(d3ddev, hdc, L"L", 0.001f, 50.5, &Text_L, 0, 0); // lewa kamera
	D3DXCreateText(d3ddev, hdc, L"R", 0.001f, 50.5, &Text_R, 0, 0); // prawa kamera

	SelectObject(hdc, hFontOld);
	DeleteObject(hFont2);
	DeleteObject(hFontOld);
	DeleteObject(hdc);
}

void refresh3Dobjects(Camera* cam)
{
	// do wizualizacji 3D odswiezenie macierzy D3D
	cam->rotation._11 = cam->RT[0];
	cam->rotation._12 = cam->RT[1];
	cam->rotation._13 = cam->RT[2];
	cam->rotation._14 = cam->RT[3];
	cam->rotation._21 = cam->RT[4];
	cam->rotation._22 = cam->RT[5];
	cam->rotation._23 = cam->RT[6];
	cam->rotation._24 = cam->RT[7];
	cam->rotation._31 = cam->RT[8];
	cam->rotation._32 = cam->RT[9];
	cam->rotation._33 = cam->RT[10];
	cam->rotation._34 = cam->RT[11];
	cam->rotation._41 = 0.0;
	cam->rotation._42 = 0.0;
	cam->rotation._43 = 0.0;
	cam->rotation._44 = 1.0;
	D3DXMatrixTranspose(&cam->rotation, &cam->rotation);
}

void dxInit(HWND hWnd)
{
	D3DPRESENT_PARAMETERS d3dpp; // create a struct to hold various device information
	d3d = Direct3DCreate9(D3D_SDK_VERSION); // create the Direct3D interface												

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = UINT(CAM_WINDOW_HEIGHT * 2.5f);
	d3dpp.BackBufferHeight = UINT(CAM_WINDOW_HEIGHT * 2.0f);
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	// create a device class using this information and information from the d3dpp stuct
	d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);

	createBlocks(); // set dimensions of D3DX objects
	initGraphics(); // call the function to initialize the triangle
	initLight(); // call the function to initialize the light and material

	d3ddev->SetRenderState(D3DRS_LIGHTING, TRUE); // turn on the 3D lighting
	d3ddev->SetRenderState(D3DRS_ZENABLE, TRUE); // turn on the z-buffer
	d3ddev->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(200, 200, 200)); // ambient light
	d3ddev->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
	d3ddev->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	d3ddev->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	d3ddev->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	d3ddev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	d3ddev->SetRenderState(D3DRS_AMBIENTMATERIALSOURCE, D3DMCS_COLOR1); // use the diffuse vertex color
}

void dxRenderFrame(void)
{
	// this is the function used to render a single frame
	int ras = 1500;
	float scaleXYZ_2 = 100.0;
	Point3f line_vertices[2]{};

	if (d3ddev) {

		D3DXMATRIX
			matProjection, // the projection transform matrix
			matView, // the view transform matrix
			matTrans, // cam translation
			matRotZ, // cam rotation matrix, Z axis
			matRotY, // cam rotation matrix, Y axis
			matRotX, // cam rotation matrix, X axis
			matWorldRot, // cam rotation matric composite
			matScale, //scale factor
			matWorldRT, // cam world rotation and translation
			matWorldRotINV, // cam world rotation and translation
			temp, // operacyjna macierz
			matCamRT;

		D3DXVECTOR3
			camPos = { appWindows.camXmov, appWindows.camYmov, appWindows.camZmov, }, // the camera position
			lookAtPos = { camXat, camYat, camZat },	// the look-at position
			upDir = { 0.0, 0.0, 1.0 }; // the up direction

		// clear the window to background color
		d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0, 0); // kolor sceny (tła)!
		d3ddev->Clear(0, NULL, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0, 0);

		// ------- begins the 3D scene
		d3ddev->BeginScene();
		// select which vertex format we are using
		d3ddev->SetFVF(CUSTOMFVF222);

		// set the projection transform - widok sceny
		D3DXMatrixOrthoRH(&matProjection, CAM_WINDOW_HEIGHT * 2.5 * 2, CAM_WINDOW_HEIGHT * 2 * 2, -FAR_VIEW_PLANE, FAR_VIEW_PLANE);
		d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);

		// set the view transform to matView - wybor pozycji kamer, punktu na który patrzymy i kierunku do góry
		D3DXMatrixLookAtRH(&matView, &camPos, &lookAtPos, &upDir);
		d3ddev->SetTransform(D3DTS_VIEW, &matView);

		// set the world rotation and translation
		D3DXMatrixTranslation(&matTrans, camXat, camYat, camZat); // punkt obrotu sceny
		D3DXMatrixRotationZ(&matRotZ, appWindows.camZrot); // potrzebne do obrotu myszka
		D3DXMatrixRotationX(&matRotX, appWindows.camXrot); // potrzebne do obrotu myszka
		D3DXMatrixMultiply(&matWorldRot, &matRotZ, &matRotX);
		D3DXMatrixInverse(&matWorldRotINV, NULL, &matWorldRot); // inwersja rotacji świata!
		D3DXMatrixMultiply(&matWorldRT, &matTrans, &matWorldRot); // tu mozna by juz skonczyc, bo scena juz rotuje, ale jest jeszcze:
		// skalowanie
		D3DXMatrixScaling(&matScale, appWindows.mouse_zoom, appWindows.mouse_zoom, appWindows.mouse_zoom);
		D3DXMatrixMultiply(&matWorldRT, &matScale, &matWorldRT);
		// przesuwanie sceny myszką, zoom
		D3DXMatrixTranslation(&matTrans, appWindows.transX, 0.0, appWindows.transZ);
		// i połączenie w całość
		D3DXMatrixMultiply(&matWorldRT, &matWorldRT, &matTrans);
		// na koniec zaimplementowana ostateczna transformacja
		d3ddev->SetTransform(D3DTS_WORLD, &matWorldRT);

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// SOLID OBJECTS
		d3ddev->SetFVF(CUSTOMFVF);
		d3ddev->SetStreamSource(0, v_buffer, 0, sizeof(CUSTOMVERTEX));
		d3ddev->SetIndices(i_buffer);
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////// RYSOWANE UKŁADY WSPÓŁRZĘDNYCH (ŚWIATA I KAMER) oraz STOŻKI KAMER ///////

		// draw the WORLD coordinate system - układ współrzędnych świata, czyli punkt maszynowy
		drawCoordinateSystem(Vec3i(0, 2, 4), Scalar(1.0f, 0.0f, 0.0f, 1.0f), Scalar(0.0f, 1.0f, 0.0f, 1.0f), Scalar(0.0f, 0.0f, 1.0f, 1.0f));

		// draw the cameras cone no. 1 - stożek kamery lewej
		setColor(0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.5f, 0.5f, 1.0f); // Diffuse RGBA, Ambient RGBA
		d3ddev->DrawIndexedPrimitive(D3DPT_LINELIST, 18, 0, 26, 0, 12);

		// draw the cameras cone no. 2 - stożek kamery prawej
		setColor(0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.5f, 0.5f, 1.0f); // Diffuse RGBA, Ambient RGBA
		d3ddev->DrawIndexedPrimitive(D3DPT_LINELIST, 26, 0, 34, 0, 12);

		// transformacja układu prawej kamery względem świata
		D3DXMatrixMultiply(&matCamRT, &cam1.rotation, &matWorldRT);
		d3ddev->SetTransform(D3DTS_WORLD, &matCamRT);

		// coordinates lines no. 2 (camera right) - układ współrzędnych kamery prawej
		drawCoordinateSystem(Vec3i(6, 8, 10), Scalar(1.0f, 0.0f, 0.0f, 1.0f), Scalar(0.0f, 1.0f, 0.0f, 1.0f), Scalar(0.0f, 0.0f, 1.0f, 1.0f));

		// transformacja układu lewej kamery względem świata
		D3DXMatrixMultiply(&matCamRT, &cam2.rotation, &matWorldRT);
		d3ddev->SetTransform(D3DTS_WORLD, &matCamRT);

		// coordinates lines no. 3 (camera left) - układ współrzędnych kamery lewej
		drawCoordinateSystem(Vec3i(12, 14, 16), Scalar(1.0f, 0.0f, 0.0f, 1.0f), Scalar(0.0f, 1.0f, 0.0f, 1.0f), Scalar(0.0f, 0.0f, 1.0f, 1.0f));

		// do tej pory obiekty były rysowane na podstawie struktury CUSTOMVERTEX,
		// natomiast poniżej robione to jest inną, szybszą i wygodniejszą metodą

		// sparametryzowana podłoga
		setColor(0.3f, 0.3f, 0.0f, 1.0f, 0.3f, 0.3f, 0.0f, 1.0f); // Diffuse RGBA, Ambient RGBA
		D3DXMatrixTranslation(&matTrans, 0.0f, 0.0f, 0.0f);
		D3DXMatrixMultiply(&temp, &matTrans, &matWorldRT); // matRotX* &matTrans* obiekt
		d3ddev->SetTransform(D3DTS_WORLD, &temp);
		for (int i = -ras; i <= ras; i += 100) {
			for (int j = -ras; j <= ras; j += 100) {
				line_vertices[0].x = float(i);
				line_vertices[0].y = -float(ras);
				line_vertices[0].z = -760.0 - 1.0;
				line_vertices[1].x = float(i);
				line_vertices[1].y = float(ras);
				line_vertices[1].z = -760.0 - 1.0;
				d3ddev->DrawPrimitiveUP(D3DPT_LINESTRIP, 1, line_vertices, sizeof(Point3f));

				line_vertices[0].x = -float(ras);
				line_vertices[0].y = float(j);
				line_vertices[0].z = -760.0 - 1.0;
				line_vertices[1].x = float(ras);
				line_vertices[1].y = float(j);
				line_vertices[1].z = -760.0 - 1.0;
				d3ddev->DrawPrimitiveUP(D3DPT_LINESTRIP, 1, line_vertices, sizeof(Point3f));
			}
		}

		///////// ::: KAMERA LEWA ::: ///////
		D3DXMatrixScaling(&matScale, scaleXYZ_2, scaleXYZ_2, 0.2f); // podpis
		D3DXMatrixRotationY(&matRotY, pi);
		D3DXMatrixRotationX(&matRotX, pi);
		D3DXMatrixMultiply(&temp, &matScale, &matRotY);
		D3DXMatrixMultiply(&temp, &temp, &matRotX);
		D3DXMatrixTranslation(&matTrans, 40.0, -150.0, 0.0);
		D3DXMatrixMultiply(&temp, &temp, &matTrans);
		D3DXMatrixMultiply(&temp, &temp, &cam1.rotation);
		D3DXMatrixMultiply(&temp, &temp, &matWorldRT);
		d3ddev->SetTransform(D3DTS_WORLD, &temp);
		setColor(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f); // Diffuse RGBA, Ambient RGBA
		Text_L->DrawSubset(0);

		d3ddev->SetTransform(D3DTS_WORLD, &matWorldRT);
		setColor(0.2f, 0.2f, 0.2f, 1.0f, 0.2f, 0.2f, 0.2f, 1.0f); // Diffuse RGBA, Ambient RGBA
		tennis_table->DrawSubset(0);
		setColor(0.2f, 0.2f, 0.2f, 1.0f, 0.2f, 0.2f, 0.2f, 1.0f); // Diffuse RGBA, Ambient RGBA
		tennis_table_net->DrawSubset(0);


		///////// ::: KAMERA PRAWA ::: ///////
		D3DXMatrixScaling(&matScale, scaleXYZ_2, scaleXYZ_2, 0.2f); // podpis
		D3DXMatrixRotationY(&matRotY, pi);
		D3DXMatrixRotationX(&matRotX, pi);
		D3DXMatrixMultiply(&temp, &matScale, &matRotY);
		D3DXMatrixMultiply(&temp, &temp, &matRotX);
		D3DXMatrixTranslation(&matTrans, 40.0, -150.0, 0.0);
		D3DXMatrixMultiply(&temp, &temp, &matTrans);
		D3DXMatrixMultiply(&temp, &temp, &cam2.rotation);
		D3DXMatrixMultiply(&temp, &temp, &matWorldRT);
		d3ddev->SetTransform(D3DTS_WORLD, &temp);
		setColor(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f); // Diffuse RGBA, Ambient RGBA
		Text_R->DrawSubset(0);

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////// wydruk wszystkich znalezionych markerow //////////////////////////////////////
		//rysowanie piłeczki pingpongowej
		if (m3d.isSet[0]) {
			D3DXMatrixTranslation(&matTrans, m3d.x[0], m3d.y[0], m3d.z[0]);
			D3DXMatrixMultiply(&temp, &matTrans, &matWorldRT);
			d3ddev->SetTransform(D3DTS_WORLD, &temp);
			setColor(0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f); // Diffuse RGBA, Ambient RGBA
			pingpong->DrawSubset(0);
		}
		//rysowanie markery
		for (uint8 k = 1; k < 56; k++) {
			if (m3d.isSet[k]) {
				D3DXMatrixTranslation(&matTrans, m3d.x[k], m3d.y[k], m3d.z[k]);
				D3DXMatrixMultiply(&temp, &matTrans, &matWorldRT);
				d3ddev->SetTransform(D3DTS_WORLD, &temp);
				setColor(1.0f, 0.5f, 0.0f, 1.0f, 1.0f, 0.5f, 0.0f, 1.0f); // Diffuse RGBA, Ambient RGBA
				sphere_small->DrawSubset(0);
			}
		}
		//rysowanie trajektoria 
		if (logicVariables.trajectory == true && prev_points.x.size()>0) {
			for (uint8 k = 0; k < prev_points.x.size(); k++) {
				// Rysowanie punktów (sfery)
				D3DXMatrixTranslation(&matTrans, prev_points.x[k], prev_points.y[k], prev_points.z[k]);
				D3DXMatrixMultiply(&temp, &matTrans, &matWorldRT);
				d3ddev->SetTransform(D3DTS_WORLD, &temp);
				setColor(1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f); //czerwony
				sphere_small->DrawSubset(0);
			}
		}

		//rysowanie predykcja kalman
		if (logicVariables.prediction == 1 && prev_points.x.size()>0 && estimated_point.x.size()>0) {

			int n = estimated_point.x.size();  // liczba pomiarów
			int n_future = predicted_point.x.size();  // liczba kroków do przodu

			for (uint8 k = 0; k < n; ++k) {
				//rysowanie punktów estymowanych
				D3DXMatrixTranslation(&matTrans, estimated_point.x[k], estimated_point.y[k], estimated_point.z[k]);
				D3DXMatrixMultiply(&temp, &matTrans, &matWorldRT);
				d3ddev->SetTransform(D3DTS_WORLD, &temp);
				setColor(0.5f, 1.0f, 0.0f, 1.0f, 0.5f, 1.0f, 0.0f, 1.0f);
				sphere_small->DrawSubset(0);
				for (uint8 j = 0; j < n_future; ++j) {
					//rysowanie punktów predykcji
					D3DXMatrixTranslation(&matTrans, predicted_point.x[j], predicted_point.y[j], predicted_point.z[j]);
					D3DXMatrixMultiply(&temp, &matTrans, &matWorldRT);
					d3ddev->SetTransform(D3DTS_WORLD, &temp);
					setColor(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
					sphere_small->DrawSubset(0);

				}
			}
		}

		//rysowanie predykcja wielomian
		if (logicVariables.prediction == 2 && prev_points.x.size()>0 && polyfit_points.x.size()>0) {

			for (uint8 i = 0; i <= polyfit_points.x.size(); ++i) {
				//rysowanie punktów predykcji
				D3DXMatrixTranslation(&matTrans, polyfit_points.x[i], polyfit_points.y[i], polyfit_points.z[i]);
				D3DXMatrixMultiply(&temp, &matTrans, &matWorldRT);
				d3ddev->SetTransform(D3DTS_WORLD, &temp);
				setColor(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
				sphere_small->DrawSubset(0);

			}
			for (uint8 i = 0; i <= polyfit_points.xpred.size(); ++i) {
				D3DXMatrixTranslation(&matTrans, polyfit_points.xpred[i], polyfit_points.ypred[i], polyfit_points.zpred[i]);
				D3DXMatrixMultiply(&temp, &matTrans, &matWorldRT);
				d3ddev->SetTransform(D3DTS_WORLD, &temp);
				setColor(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
				sphere_small->DrawSubset(0);
			}

		}
		
		//Rysowanie predykcja równania ruchu
		if (logicVariables.prediction == 3 && prev_points.x.size()>0 && predicted_points_newton.x.size()>0) {

			for (uint8 i = 0; i <= predicted_points_newton.x.size(); ++i) {
				//rysowanie punktów predykcji
				D3DXMatrixTranslation(&matTrans, predicted_points_newton.x[i], predicted_points_newton.y[i], predicted_points_newton.z[i]);
				D3DXMatrixMultiply(&temp, &matTrans, &matWorldRT);
				d3ddev->SetTransform(D3DTS_WORLD, &temp);
				setColor(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
				sphere_small->DrawSubset(0);
			}
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////// KONIEC RYSOWANIA BRYŁ //////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////   TEKSTY 2D   ////////////////////////
		ID3DXFont* g_font = NULL, * g_font2 = NULL;
		D3DXCreateFont(d3ddev, int(40 / 1.5), int(12 / 1.5), FW_NORMAL, 1, false, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Courier", &g_font);
		D3DXCreateFont(d3ddev, 40, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
			ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial", &g_font2);
		RECT font_rect;

		// czas trwania trzeciego wątku
		wchar_t codeTxt1[100];
		swprintf(codeTxt1, 100, L"dT: %.1f", 1 / dT);
		SetRect(&font_rect, 10, 870, 200, 200);
		if (g_font != nullptr) g_font->DrawText(NULL, codeTxt1, -1, &font_rect, DT_LEFT | DT_NOCLIP, 0xFFAAAAAA);
		
		//typ predykcji
		SetRect(&font_rect, 0, 0, int(CAM_WINDOW_HEIGHT * 2.5 - 800), 200); // pierwszy - szerokość, drugi - wysokość

		wchar_t strikePoint[200];
		wchar_t realPoint[200];
		wchar_t distancebetweenpoints[200];
		if (logicVariables.prediction == 0 && g_font2 != nullptr) g_font2->DrawText(NULL, L"Typ predykcji: BRAK", -1, &font_rect, DT_LEFT | DT_NOCLIP | DT_VCENTER, 0xFFFFFFFF);
		if (logicVariables.prediction == 1 && g_font2 != nullptr) g_font2->DrawText(NULL, L"Typ predykcji: Kalman", -1, &font_rect, DT_LEFT | DT_NOCLIP | DT_VCENTER, 0xFFFFFFFF);
		if (logicVariables.prediction == 2 && g_font2 != nullptr) g_font2->DrawText(NULL, L"Typ predykcji: Ap. Wielomianowa", -1, &font_rect, DT_LEFT | DT_NOCLIP | DT_VCENTER, 0xFFFFFFFF);
		if (logicVariables.prediction == 3 && g_font2 != nullptr) g_font2->DrawText(NULL, L"Typ predykcji: Równania ruchu", -1, &font_rect, DT_LEFT | DT_NOCLIP | DT_VCENTER, 0xFFFFFFFF);
		swprintf(strikePoint, 200, L"PredStrkPoint X: %.1f  Z: %.1f", crossplanepoints.x, crossplanepoints.z);
		SetRect(&font_rect, 0, 550, 0, 0);
		if (g_font != nullptr) g_font->DrawText(NULL, strikePoint, -1, &font_rect, DT_LEFT | DT_NOCLIP, 0xFFAAAAAA);
		
		//trajektoria realplanepoints
		SetRect(&font_rect, 0, 0, int(CAM_WINDOW_HEIGHT * 2.5 - 800), 50); // pierwszy - szerokość, drugi - wysokość
		if (logicVariables.trajectory == true && g_font2 != nullptr) g_font2->DrawText(NULL, L"Rysowanie trajektorii: ON", -1, &font_rect, DT_LEFT | DT_NOCLIP | DT_VCENTER, 0xFFFFFFFF);
		else if (logicVariables.trajectory == false && g_font2 != nullptr) g_font2->DrawText(NULL, L"Rysowanie trajektorii: OFF", -1, &font_rect, DT_LEFT | DT_NOCLIP | DT_VCENTER, 0xFFFFFFFF);
		swprintf(realPoint, 200, L"RealCrossPoint X: %.1f  Z: %.1f", realplanepoints.x, realplanepoints.z);
		SetRect(&font_rect, 0, 500, 0, 0);
		if (g_font != nullptr) g_font->DrawText(NULL, realPoint, -1, &font_rect, DT_LEFT | DT_NOCLIP, 0xFFAAAAAA);
		swprintf(distancebetweenpoints, 200, L"Distance: %.1f cm", realplanepoints.distance/10);
		SetRect(&font_rect, 0, 450, 0, 0);
		if (g_font != nullptr) g_font->DrawText(NULL, distancebetweenpoints, -1, &font_rect, DT_LEFT | DT_NOCLIP, 0xFFAAAAAA);
		//////////////   KOMUNIKATY   //////////////////////
		SetRect(&font_rect, 0, 0, int(CAM_WINDOW_HEIGHT * 2.5), 100); // pierwszy - szerokość, drugi - wysokość
		if (g_font2 != nullptr) g_font2->DrawText(NULL, L"WIZUALIZACJA 3D", -1, &font_rect, DT_CENTER | DT_NOCLIP | DT_VCENTER, 0xFFFFFF00);

		if ((appWindows.camXrot == DEFAULT_ROT_X || appWindows.camXrot == -PI2) && appWindows.camYrot == DEFAULT_ROT_Y && (appWindows.camZrot == DEFAULT_ROT_Z || appWindows.camZrot == PI2)) {
			SetRect(&font_rect, 0, 0, int(CAM_WINDOW_HEIGHT * 2.5 + 900), 100); // pierwszy - szerokość, drugi - wysokość
			if (logicVariables.view_rotation == 0 && g_font2 != nullptr) g_font2->DrawText(NULL, L"widok: XY", -1, &font_rect, DT_CENTER | DT_NOCLIP | DT_VCENTER, 0xFFFFFFFF);
			else if (logicVariables.view_rotation == 1 && g_font2 != nullptr) g_font2->DrawText(NULL, L"widok: YZ", -1, &font_rect, DT_CENTER | DT_NOCLIP | DT_VCENTER, 0xFFFFFFFF);
			else if (logicVariables.view_rotation == 2 && g_font2 != nullptr) g_font2->DrawText(NULL, L"widok: XZ", -1, &font_rect, DT_CENTER | DT_NOCLIP | DT_VCENTER, 0xFFFFFFFF);
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////
		// memory release - zwolnienie pamięci -> bardzo ważne!
		if (g_font) {
			g_font->Release();
			g_font = NULL;
		}
		if (g_font2) {
			g_font2->Release();
			g_font2 = NULL;
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////
		d3ddev->EndScene();	// ends the 3D scene
		d3ddev->Present(NULL, NULL, NULL, NULL); // displays the created frame
	}
	return;
}

void drawCoordinateSystem(Vec3i pos, Scalar c1, Scalar c2, Scalar c3)
{
	// ustawienie kolorów i rysowanie linii
	setColor((float)c1(0), (float)c1(1), (float)c1(2), (float)c1(3), (float)c1(0), (float)c1(1), (float)c1(2), (float)c1(3)); // Diffuse RGBA, Ambient RGBA
	d3ddev->DrawPrimitive(D3DPT_LINELIST, pos(0), 1);
	setColor((float)c2(0), (float)c2(1), (float)c2(2), (float)c2(3), (float)c2(0), (float)c2(1), (float)c2(2), (float)c2(3)); // Diffuse RGBA, Ambient RGBA
	d3ddev->DrawPrimitive(D3DPT_LINELIST, pos(1), 1);
	setColor((float)c3(0), (float)c3(1), (float)c3(2), (float)c3(3), (float)c3(0), (float)c3(1), (float)c3(2), (float)c3(3)); // Diffuse RGBA, Ambient RGBA
	d3ddev->DrawPrimitive(D3DPT_LINELIST, pos(2), 1);
}