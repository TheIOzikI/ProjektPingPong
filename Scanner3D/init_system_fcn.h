#pragma once

#include "main.h"
#include "graphic_fcn.h"
#include "main_threads.h"

__inline void errMsg(wchar_t*, wchar_t*);
void terminateCameras(HRESULT);
bool initCameras(void);
void InitCOMPort(void);
void tryInitCameras(void*);
bool loadCamParams(int8*, pCamera);

///////////// obsluga kamer /////////////
#define pylonCheck(errCode) if (errCode != GENAPI_E_OK) { terminateCameras(errCode); errMsg(L"Camera init problem", L"There was a problem with\ncamera device initialization"); return false; }