#include "print_fcn.h"

// debug print routine
#ifdef CDEBUG
void odprintf(const char* format, ...)
{
	char buf[4096];
	va_list	args;
	va_start(args, format);
	int n = _vsnprintf_s(buf, sizeof buf, 4096, format, args);
	va_end(args);
	OutputDebugStringA(buf);
}
#else
__inline void odprintf(const char* format, ...) {};
#endif

///////////////////// rozne funkcje wydruków danych w konsoli //////////////////////////////
void printCvMatFloat(int8* desc, CvMat* arr)
{
	uint32	i = 0, pos = 0, len = arr->rows * arr->cols;

	odprintf("%s%s%s", "\n", desc, "\n\n");

	for (; i < len; ++i) {
		odprintf("%13.6f", arr->data.fl[i]);
		if ((i + 1) % arr->cols == 0) odprintf("\n");
	}
}

void printMatFloat(int8* desc, Mat arr)
{
	uint32	i = 0, pos = 0, len = arr.rows * arr.cols;

	odprintf("%s%s%s", "\n", desc, "\n\n");

	for (; i < len; ++i) {
		odprintf("%13.6f", arr.at<float>(i));
		if ((i + 1) % arr.cols == 0) odprintf("\n");
	}
}

void printMatDouble(int8* desc, Mat arr)
{
	uint32	i = 0, pos = 0, len = arr.rows * arr.cols;

	odprintf("%s%s%s", "\n", desc, "\n\n");

	for (; i < len; ++i) {
		odprintf("%13.6f", arr.at<double>(i));
		if ((i + 1) % arr.cols == 0) odprintf("\n");
	}
}

void printArrFloat(int8* desc, float* arr, uint32 rows, uint32 cols)
{
	uint32 i = 0, pos = 0, len = rows * cols;

	odprintf("%s%s%s", "\n", desc, "\n\n");

	for (; i < len; ++i) {
		odprintf("%13.6f", arr[i]);
		if ((i + 1) % cols == 0) odprintf("\n");
	}
}

void printPoint4(int8* desc, pPoint4 arr, uint32 len)
{
	uint32	i = 0;

	odprintf("%s%s%s", "\n", desc, "\n\n");

	for (; i < len; ++i) {
		odprintf("%13.6f%13.6f%13.6f%13.6f\n",
			arr[i].el.x, arr[i].el.y, arr[i].el.z, arr[i].el.w);
	}
}

void printMatInt8(int8* desc, CvMat* arr)
{
	uint32	i = 0, pos = 0, len = arr->rows * arr->cols;

	odprintf("%s%s%s", "\n", desc, "\n\n");

	for (; i < len; ++i) {
		odprintf("%6d", arr->data.ptr[i]);
		if ((i + 1) % arr->cols == 0) odprintf("\n");
	}
}

void printCamParams(pCamera cam)
{
	odprintf("--------------------------------\nCamera ID: %s\n", cam->id);
	printArrFloat("Camera matrix", cam->A, 4, 4);
	printArrFloat("RTcam matrix", cam->RT, 4, 4);
	odprintf("\n");
}

void printMatMatrix(int8* desc, Mat matrix)
{
	odprintf("%s%s%s", "\n", desc, "\n\n");
	for (int i = 0; i < matrix.rows; ++i) {
		for (int j = 0; j < matrix.cols; ++j) {
			odprintf("%f ", matrix.at<float>(i, j));
		}
		odprintf("\n");
	}
}

// nazwakomputera/admin
// dok07