#ifndef MANDELBORT_H
#define MANDELBORT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "const.h"

typedef struct Image {

    int width;
    int height;
    unsigned char* data; // Image data (pixel values)

} Image;

void coordinates(Image* img, int iterations, int xPixel, int yPixel, int imageSize);
void xCoordinates(Image* img, int iterations, int xPixel, int yPixel, int imageSize);
double xConvert(int xPixel, int imageSize);
double yConvert(int yPixel, int imageSize);
int mandelbrot(double xComplex, double yComplex, int iterations, double zx, double zy);
void draw(Image* img, int xPixel, int yPixel, double percentNotUsed);

#endif