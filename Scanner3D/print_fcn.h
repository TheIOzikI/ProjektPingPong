#pragma once

#include "main.h"
#include <windows.h>
#include <stdio.h>

#define CDEBUG

void odprintf(const char* format, ...);
void printCvMatFloat(int8*, CvMat*);
void printMatFloat(int8*, Mat);
void printMatDouble(int8*, Mat);
void printArrFloat(int8*, float*, uint32, uint32);
void printPoint4(int8* desc, pPoint4 arr, uint32 len);
void printMatInt8(int8* desc, CvMat* arr);
void printCamParams(pCamera cam);
void printMatMatrix(int8*, Mat);