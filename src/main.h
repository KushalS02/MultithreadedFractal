#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "memMap.h"
#include "bitmapLib.h"
#include "coordinateDivider.h"
#include "mandelbrot.h"

#define MAX_FILESIZE 192000054 // = 192.000054 MB
// #define MAX_FILESIZE (MAX_RESOLUTION << 1)3 + 54
#define MAX_RESOLUTION ((MAX_FILESIZE - IMAGE_DATA_OFFSET)/3) >> 1  //8000
#define MAX_ITERATIONS 4294967295 // unsgined int max

#define TRUE 1
#define FALSE 0

typedef struct renderRangeParams {
    coordinateRange* range;
    unsigned int iterations;
    unsigned int imgRes;
    char* bmpFile;
} renderRangeParams;

void* renderRange(void* args);
void drawPixel(int x, int y, unsigned int imgRes, float percentNotUsed, char *imgData);

#endif