#pragma once

#include "main.h"
#include <emmintrin.h>
#include <windows.h>

constexpr float pi = 3.141592653589793f;
constexpr float pi_div3 = 1.047197551196598f;
constexpr float pi_mul2 = 6.283185307179586f;

#define PI2			pi/2.0f
#define RAD2DEG		180.0f/pi
#define DEG2RAD		pi/180.0f

#define algn(x) __declspec(align(x))

void M4x4_SSE(float* src1, float* src2, float* dst);
void T4x4_SSE(float* src, float* dst);
void M3x1_SSE(float* src3, float* src1, float* dst);
void M4x1_SSE(float* src4, float* src1, float* dst);
void M4x1N_SSE(float* src4, float* srcN, float* dst, size_t n);
void M3x14N_SSE(float* src3, float* srcN, float* dst, size_t n);
void M4x1NS_SSE(float* src4, float* srcN, float* dst, size_t n);
void I3x3_SSE(float* src, float* dst);
void I4x4_SSE(float* src, float* dst);
void cumSumSSE(float* dst, size_t n, size_t step);
void M3x3(float a[][3], float b[][3], float result[][3]);
wchar_t* convertCharArrayToLPCWSTR(const char* charArray);
void crossProduct(float* vp1, float* vp2, float* VCR);
__inline void quat2Mat(float* q, float* m);