#include "math_fcn.h"
#include "main.h"
#include "print_fcn.h"
#include "graphic_fcn.h"

// Multiplication 4x4 Matrix
void M4x4_SSE(float* src1, float* src2, float* dst) {
	int i;
	__m128 row1 = _mm_load_ps(src2 + 0);
	__m128 row2 = _mm_load_ps(src2 + 4);
	__m128 row3 = _mm_load_ps(src2 + 8);
	__m128 row4 = _mm_load_ps(src2 + 12);
	__m128 brod1, brod2, brod3, brod4, row;

	for (i = 0; i < 16; i += 4) {
		brod1 = _mm_set_ps1(src1[i + 0]);
		brod2 = _mm_set_ps1(src1[i + 1]);
		brod3 = _mm_set_ps1(src1[i + 2]);
		brod4 = _mm_set_ps1(src1[i + 3]);
		row = _mm_add_ps(
			_mm_add_ps(_mm_mul_ps(brod1, row1), _mm_mul_ps(brod2, row2)),
			_mm_add_ps(_mm_mul_ps(brod3, row3), _mm_mul_ps(brod4, row4)));
		_mm_store_ps(dst + i, row);
	}
}

void T4x4_SSE(float* src, float* dst)
{
	__m128 row1 = _mm_load_ps(src + 0);
	__m128 row2 = _mm_load_ps(src + 4);
	__m128 row3 = _mm_load_ps(src + 8);
	__m128 row4 = _mm_load_ps(src + 12);

	_MM_TRANSPOSE4_PS(row1, row2, row3, row4);

	_mm_store_ps(dst + 0, row1);
	_mm_store_ps(dst + 4, row2);
	_mm_store_ps(dst + 8, row3);
	_mm_store_ps(dst + 12, row4);
}

// 3x3 Matrix multiplication by Vector
void M3x1_SSE(float* src3, float* src1, float* dst) {
	algn(16) float	in3[16] = { src3[0], src3[1], src3[2], 0.0f,
								src3[3], src3[4], src3[5], 0.0f,
								src3[6], src3[7], src3[8], 0.0f,
								   0.0f,    0.0f,    0.0f, 0.0f };
	algn(16) float	in1[4] = { src1[0], src1[1], src1[2], 0.0f };
	algn(16) float	out[4];

	M4x1_SSE(in3, in1, out);

	dst[0] = out[0]; dst[1] = out[1]; dst[2] = out[2];
}

// 4x4 Matrix multiplication by Vector
void M4x1_SSE(float* src4, float* src1, float* dst) {

	__m128 row1 = _mm_load_ps(src4);
	__m128 row2 = _mm_load_ps(src4 + 4);
	__m128 row3 = _mm_load_ps(src4 + 8);
	__m128 row4 = _mm_load_ps(src4 + 12);
	__m128 sum;

	_MM_TRANSPOSE4_PS(row1, row2, row3, row4);

	sum = _mm_add_ps(_mm_add_ps(_mm_mul_ps(row1, _mm_set_ps1(src1[0])), _mm_mul_ps(row2, _mm_set_ps1(src1[1]))),
		_mm_add_ps(_mm_mul_ps(row3, _mm_set_ps1(src1[2])), _mm_mul_ps(row4, _mm_set_ps1(src1[3]))));

	_mm_store_ps(dst, sum);
}

void M4x1N_SSE(float* src4, float* srcN, float* dst, size_t n) {
	size_t i;
	__m128 row1 = _mm_load_ps(src4);
	__m128 row2 = _mm_load_ps(src4 + 4);
	__m128 row3 = _mm_load_ps(src4 + 8);
	__m128 row4 = _mm_load_ps(src4 + 12);
	__m128 mul1, mul2, mul3, mul4, sum;

	_MM_TRANSPOSE4_PS(row1, row2, row3, row4);

	for (i = 0; i < n; i++) {
		mul1 = _mm_mul_ps(row1, _mm_set_ps1(srcN[i]));
		mul2 = _mm_mul_ps(row2, _mm_set_ps1(srcN[n + i]));
		mul3 = _mm_mul_ps(row3, _mm_set_ps1(srcN[2 * n + i]));
		mul4 = _mm_mul_ps(row4, _mm_set_ps1(srcN[3 * n + i]));
		sum = _mm_add_ps(mul1, mul2);
		sum = _mm_add_ps(sum, mul3);
		sum = _mm_add_ps(sum, mul4);
		_mm_store_ss(dst + i, sum);
		sum = _mm_shuffle_ps(sum, sum, _MM_SHUFFLE(3, 2, 0, 1));
		_mm_store_ss(dst + n + i, sum);
		sum = _mm_movehl_ps(sum, sum);
		_mm_store_ss(dst + 2 * n + i, sum);
		sum = _mm_shuffle_ps(sum, sum, _MM_SHUFFLE(3, 2, 0, 1));
		_mm_store_ss(dst + 3 * n + i, sum);
	}
}

void M4x1NS_SSE(float* src4, float* srcN, float* dst, size_t n) {
	size_t i;
	__m128 row1 = _mm_load_ps(src4);
	__m128 row2 = _mm_load_ps(src4 + 4);
	__m128 row3 = _mm_load_ps(src4 + 8);
	__m128 row4 = _mm_load_ps(src4 + 12);
	__m128 mul1, mul2, mul3, mul4, sum;

	_MM_TRANSPOSE4_PS(row1, row2, row3, row4);

	for (i = 0; i < n * 4; i += 4) {
		mul1 = _mm_mul_ps(row1, _mm_set_ps1(srcN[i + 0]));
		mul2 = _mm_mul_ps(row2, _mm_set_ps1(srcN[i + 1]));
		mul3 = _mm_mul_ps(row3, _mm_set_ps1(srcN[i + 2]));
		mul4 = _mm_mul_ps(row4, _mm_set_ps1(srcN[i + 3]));
		sum = _mm_add_ps(mul1, mul2);
		sum = _mm_add_ps(sum, mul3);
		sum = _mm_add_ps(sum, mul4);
		_mm_store_ps(dst + i, sum);
	}
}

// Multiplication 3x3 x 4xN
void M3x14N_SSE(float* src3, float* srcN, float* dst, size_t n) {
	float	in[16] = {
		src3[0], src3[1], src3[2], 0.0f,
		src3[3], src3[4], src3[5], 0.0f,
		src3[6], src3[7], src3[8], 0.0f,
		   0.0f,    0.0f,    0.0f, 1.0f };

	M4x1NS_SSE(in, srcN, dst, n);
}

// 4x4 Matrix Inversion
void I4x4_SSE(float* src, float* dst) {

	algn(16) const float _Sign_PNNP[4] = { 0.0f, -0.0f, -0.0f, 0.0f };

	// Load the full matrix into registers
	__m128 row1 = _mm_load_ps(src);
	__m128 row2 = _mm_load_ps(src + 4);
	__m128 row3 = _mm_load_ps(src + 8);
	__m128 row4 = _mm_load_ps(src + 12);
	// the four sub-matrices
	__m128 A, B, C, D;
	// partial inverse of the sub-matrices
	__m128 iA, iB, iC, iD, DC, AB;
	// determinant of the sub-matrices
	__m128 dA, dB, dC, dD;
	__m128 det, d, d1, d2;
	// reciprocal of the determinant
	__m128 rd;

	A = _mm_unpacklo_ps(row1, row2);
	B = _mm_unpacklo_ps(row3, row4);
	C = _mm_unpackhi_ps(row1, row2);
	D = _mm_unpackhi_ps(row3, row4);

	//  AB = A# * B
	AB = _mm_mul_ps(_mm_shuffle_ps(A, A, 0x0F), B);
	AB = _mm_sub_ps(AB, _mm_mul_ps(_mm_shuffle_ps(A, A, 0xA5), _mm_shuffle_ps(B, B, 0x4E)));
	//  DC = D# * C
	DC = _mm_mul_ps(_mm_shuffle_ps(D, D, 0x0F), C);
	DC = _mm_sub_ps(DC, _mm_mul_ps(_mm_shuffle_ps(D, D, 0xA5), _mm_shuffle_ps(C, C, 0x4E)));
	//  dA = |A|
	dA = _mm_mul_ps(_mm_shuffle_ps(A, A, 0x5F), A);
	dA = _mm_sub_ss(dA, _mm_movehl_ps(dA, dA));
	//  dB = |B|
	dB = _mm_mul_ps(_mm_shuffle_ps(B, B, 0x5F), B);
	dB = _mm_sub_ss(dB, _mm_movehl_ps(dB, dB));
	//  dC = |C|
	dC = _mm_mul_ps(_mm_shuffle_ps(C, C, 0x5F), C);
	dC = _mm_sub_ss(dC, _mm_movehl_ps(dC, dC));
	//  dD = |D|
	dD = _mm_mul_ps(_mm_shuffle_ps(D, D, 0x5F), D);
	dD = _mm_sub_ss(dD, _mm_movehl_ps(dD, dD));
	//  d = trace(AB*DC) = trace(A#*B*D#*C)
	d = _mm_mul_ps(_mm_shuffle_ps(DC, DC, 0xD8), AB);
	//  iD = C*A#*B
	iD = _mm_mul_ps(_mm_shuffle_ps(C, C, 0xA0), _mm_movelh_ps(AB, AB));
	iD = _mm_add_ps(iD, _mm_mul_ps(_mm_shuffle_ps(C, C, 0xF5), _mm_movehl_ps(AB, AB)));
	//  iA = B*D#*C
	iA = _mm_mul_ps(_mm_shuffle_ps(B, B, 0xA0), _mm_movelh_ps(DC, DC));
	iA = _mm_add_ps(iA, _mm_mul_ps(_mm_shuffle_ps(B, B, 0xF5), _mm_movehl_ps(DC, DC)));

	//  d = trace(AB*DC) = trace(A#*B*D#*C) [continue]
	d = _mm_add_ps(d, _mm_movehl_ps(d, d));
	d = _mm_add_ss(d, _mm_shuffle_ps(d, d, 1));
	d1 = _mm_mul_ss(dA, dD);
	d2 = _mm_mul_ss(dB, dC);

	//  iD = D*|A| - C*A#*B
	iD = _mm_sub_ps(_mm_mul_ps(D, _mm_shuffle_ps(dA, dA, 0)), iD);
	//  iA = A*|D| - B*D#*C;
	iA = _mm_sub_ps(_mm_mul_ps(A, _mm_shuffle_ps(dD, dD, 0)), iA);
	//  det = |A|*|D| + |B|*|C| - trace(A#*B*D#*C)
	det = _mm_sub_ss(_mm_add_ss(d1, d2), d);
	rd = _mm_div_ss(_mm_set_ss(1.0f), det);
	//  iB = D * (A#B)# = D*B#*A
	iB = _mm_mul_ps(D, _mm_shuffle_ps(AB, AB, 0x33));
	iB = _mm_sub_ps(iB, _mm_mul_ps(_mm_shuffle_ps(D, D, 0xB1), _mm_shuffle_ps(AB, AB, 0x66)));
	//  iC = A * (D#C)# = A*C#*D
	iC = _mm_mul_ps(A, _mm_shuffle_ps(DC, DC, 0x33));
	iC = _mm_sub_ps(iC, _mm_mul_ps(_mm_shuffle_ps(A, A, 0xB1), _mm_shuffle_ps(DC, DC, 0x66)));

	rd = _mm_shuffle_ps(rd, rd, 0);
	rd = _mm_xor_ps(rd, _mm_load_ps(_Sign_PNNP));

	//  iB = C*|B| - D*B#*A
	iB = _mm_sub_ps(_mm_mul_ps(C, _mm_shuffle_ps(dB, dB, 0)), iB);
	//  iC = B*|C| - A*C#*D;
	iC = _mm_sub_ps(_mm_mul_ps(B, _mm_shuffle_ps(dC, dC, 0)), iC);

	//  iX = iX / det
	iA = _mm_mul_ps(rd, iA);
	iB = _mm_mul_ps(rd, iB);
	iC = _mm_mul_ps(rd, iC);
	iD = _mm_mul_ps(rd, iD);

	_mm_store_ps(dst, _mm_shuffle_ps(iA, iC, 0xBB));
	_mm_store_ps(dst + 4, _mm_shuffle_ps(iA, iC, 0x11));
	_mm_store_ps(dst + 8, _mm_shuffle_ps(iB, iD, 0xBB));
	_mm_store_ps(dst + 12, _mm_shuffle_ps(iB, iD, 0x11));
}

// 3x3 Matrix Inversion
void I3x3_SSE(float* src, float* dst) {
	float	in[16] = { src[0], src[1], src[2], 0.0f,
						src[3], src[4], src[5], 0.0f,
						src[6], src[7], src[8], 0.0f,
						  0.0f,   0.0f,   0.0f, 1.0f }, out[16];
	I4x4_SSE(in, out);
	dst[0] = out[0]; dst[1] = out[1]; dst[2] = out[2];
	dst[3] = out[4]; dst[4] = out[5]; dst[5] = out[6];
	dst[6] = out[8]; dst[7] = out[9]; dst[8] = out[10];
}

// Cumulative sum from vector
void cumSumSSE(float* dst, size_t n, size_t step) {
	size_t i = 0, x = 1;
	__m128 addx = _mm_set_ps(0.0f, 0.0f, 0.0f, 1.0f);
	__m128 addy = _mm_set_ps(0.0f, 0.0f, 1.0f, 0.0f);
	__m128 out = _mm_set_ps(1.0f, 1.0f, 1.0f, 0.0f);
	do {
		out = _mm_add_ss(out, addx);
		_mm_store_ps(dst + 4 * i, out);

		if (x++ == step) {
			x = 1;
			out = _mm_sub_ss(out, out);
			out = _mm_add_ps(out, addy);
		}
	} while (++i < n);
}

// Multiplication 3x3 Matrix
void M3x3(float a[][3], float b[][3], float result[][3])
{
	int i, j, k;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

wchar_t* convertCharArrayToLPCWSTR(const char* charArray)
{
	wchar_t* wString = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}

void crossProduct(float* vp1, float* vp2, float* VCR)
{
	VCR[0] = vp1[1] * vp2[2] - vp2[1] * vp1[2];
	VCR[1] = vp2[0] * vp1[2] - vp2[2] * vp1[0];
	VCR[2] = vp1[0] * vp2[1] - vp2[0] * vp1[1];
}

__inline void quat2Mat(float* q, float* m)
{
	m[0] = q[0] * q[0] + q[1] * q[1] - q[2] * q[2] - q[3] * q[3];
	m[1] = 2 * (q[1] * q[2] - q[0] * q[3]);
	m[2] = 2 * (q[1] * q[3] + q[0] * q[2]);

	m[3] = 2 * (q[1] * q[2] + q[0] * q[3]);
	m[4] = q[0] * q[0] - q[1] * q[1] + q[2] * q[2] - q[3] * q[3];
	m[5] = 2 * (q[2] * q[3] - q[0] * q[1]);

	m[6] = 2 * (q[1] * q[3] - q[0] * q[2]);
	m[7] = 2 * (q[2] * q[3] + q[0] * q[1]);
	m[8] = q[0] * q[0] - q[1] * q[1] - q[2] * q[2] + q[3] * q[3];
}