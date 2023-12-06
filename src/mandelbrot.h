#ifndef MANDELBROT_H
#define MANDELBROT_H

int mandelbrot(int x, int y, int iterations, int imgRes);
double xConvert (int xPixel, int imageSize);
double yConvert (int yPixel, int imageSize);
int calculateMandelbrot(double xComplex, double yComplex, int iterations, double zx, double zy);

#endif