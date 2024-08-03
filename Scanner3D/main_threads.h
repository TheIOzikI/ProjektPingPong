#pragma once

#include "main.h"
#include "graphic_fcn.h"

void liveFeed(void*);
void liveDataProcessing(void*);
void liveFeedRestore(void*);
void setExposure(uint64, int = 0);
void reconstructMarkers3D(void);
void findMarkers(Mat&, Mat&, Marker*, uint8, uint8, bool);
void cleanBorder(Mat&);
float alignRadians(Mat&, float, Point2f);
uint8_t readCode(Mat&, RotatedRect);
static string toStringWithPrecision(double, int);
static void pylonImageToCvMat(const void*, int, int, Mat&);
vector<Point2f> undistortPointsMG(pCamera, vector<Point2f>);

// tablica podmiany kodów markerów na ich numery (zgodne z wydrukiem)
static const uint8 codesLUT[] = {
	1,   2,   3,   4,   5,   6,   255, 7,   8,   9,   10,  11,  255, 255, 255, 12,
	13,  14,  15,  16,  17,  18,  255, 19,  255, 255, 255, 255, 255, 255, 255, 20,
	21,  22,  23,  24,  25,  26,  255, 27,  28,  29,  30,  31,  255, 255, 255, 32,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 33,
	34,  35,  36,  37,  38,  39,  255, 40,  41,  42,  43,  44,  255, 255, 255, 45,
	46,  47,  48,  49,  50,  51,  255, 52,  255, 255, 255, 255, 255, 255, 255, 53,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 54
};