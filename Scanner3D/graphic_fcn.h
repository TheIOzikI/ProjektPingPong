#pragma once

#include "main.h"

// DirectX
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

// D3D functions prototypes
void initGraphics(void); // specified parametrs of 3D scene
void cleanD3D(void); // closes Direct3D and releases memory
void initLight(void); // light settings of 3D scene
void setColor(float, float, float, float, float, float, float, float); // function for coloring objects
void createBlocks(void); // create and define 3D elements
void refresh3Dobjects(pCamera); // refresh objects using RT matrix
void dxInit(HWND); // sets up and initializes Direct3D
void dxRenderFrame(void); // renders a single frame
void drawCoordinateSystem(Vec3i, Scalar, Scalar, Scalar);

struct CUSTOMVERTEX { FLOAT X, Y, Z; D3DVECTOR NORMAL; };
#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_NORMAL)

struct CUSTOMVERTEX_COLOR { float X, Y, Z; uint32 COLOR; };
#define CUSTOMFVF222 (D3DFVF_XYZ | D3DFVF_DIFFUSE)