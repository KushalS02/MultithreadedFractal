#include "mandelbrot.h"
#include <stdio.h>

// Max and min values on the complex plain
const double IMAGINARY_END = 1.0;
const double IMAGINARY_START = -1.0;
const double REAL_START = -1.5;
const double REAL_END = 0.5;

const double Z = 0.0; // Initial value of a variable zx and zy in the mandelbrot function

int mandelbrot(int x, int y, int iterations, int imgRes) {
    double xComplex = xConvert(x, imgRes);
    double yComplex = yConvert(y, imgRes);

    return calculateMandelbrot(xComplex, yComplex, iterations, Z, Z);
}

double xConvert (int xPixel, int imageSize)
{
    double xComplex;

    xComplex = REAL_START + (xPixel / ( ((double)imageSize) -1))
	* (REAL_END - REAL_START);

    return xComplex;
}

double yConvert (int yPixel, int imageSize)
{
    double yComplex;

    yComplex = IMAGINARY_END -
            (yPixel / ( ((double)imageSize) -1))
	* (IMAGINARY_END - IMAGINARY_START);

    return yComplex;
}

int calculateMandelbrot(double xComplex, double yComplex, int iterations, double zx, double zy) {
    double temp_zx;
    int counter;
    
    if ((iterations > 0) && ( zx * zx + zy * zy < 4.0))
    {
	temp_zx = zx * zx - zy * zy + xComplex;
	zy = 2.0 * zx * zy + yComplex;
	zx = temp_zx;
	counter = calculateMandelbrot (xComplex, yComplex, iterations -1, zx, zy);
    }
    else
    {
	counter = iterations;
    }
    
    return counter;
}