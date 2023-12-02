/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 2

File name: mandelbrot.c

Instructor: Marc Schroeder

Purpose: source for for mandelbrot functions 

*/

#include "mandelbrot.h"

void coordinates(Image* img, int iterations, int xPixel, int yPixel, int imageSize) {

    if (yPixel < imageSize) {

        xCoordinates(img, iterations, 0, yPixel, imageSize);
        coordinates(img, iterations, 0, yPixel + 1, imageSize);

    }

}

void xCoordinates(Image* img, int iterations, int xPixel, int yPixel, int imageSize) {

    double xComplex;
    double yComplex;
    int iterationsLeft;
    double percentNotUsed;

    yComplex = yConvert(yPixel, imageSize);
    xComplex = xConvert(xPixel, imageSize);

    iterationsLeft = mandelbrot(xComplex, yComplex, iterations, 0.0, 0.0);
    percentNotUsed = iterationsLeft / (double)iterations;
    draw(img, xPixel, yPixel, percentNotUsed);

    if (xPixel < (imageSize - 1)) {
        
        xCoordinates(img, iterations, xPixel + 1, yPixel, imageSize);

    }

}

double xConvert(int xPixel, int imageSize) {

    return -1.5 + (xPixel / (double)(imageSize - 1)) * 2.0;

}

double yConvert(int yPixel, int imageSize) {

    return 1.0 - (yPixel / (double)(imageSize - 1)) * 2.0;

}

int mandelbrot(double xComplex, double yComplex, int iterations, double zx, double zy) {

    double temp_zx;
    int counter;

    if ((iterations > 0) && (zx * zx + zy * zy < 4.0)) {
        // Update the complex values using the Mandelbrot equation
        temp_zx = zx * zx - zy * zy + xComplex;
        zy = 2.0 * zx * zy + yComplex;
        zx = temp_zx;

        // Recursive call with decremented iterations
        counter = mandelbrot(xComplex, yComplex, iterations - 1, zx, zy);

    } else {
        // If the condition is not met or iterations reach 0, return the remaining iterations
        counter = iterations;
    }

    return counter;

}

void draw(Image* img, int xPixel, int yPixel, double percentNotUsed) {

    int index = 3 * (yPixel * img->width + xPixel);

    if (percentNotUsed == 0) {

        img->data[index] = img->data[index + 1] = img->data[index + 2] = 0;

    } else if (percentNotUsed < 0.6) {

        img->data[index] = 188; // MAX_COLOR * 0.74;
        img->data[index + 1] = 74; // MAX_COLOR * 0.29;
        img->data[index + 2] = 82; // MAX_COLOR * 0.32;

    } else if (percentNotUsed < 0.85) {

        img->data[index] = 231; // MAX_COLOR * 0.91;
        img->data[index + 1] = 112; // MAX_COLOR * 0.44;
        img->data[index + 2] = 82; // MAX_COLOR * 0.32;

    } else if (percentNotUsed < 0.92) {

        img->data[index] = 245; // MAX_COLOR * 0.96;
        img->data[index + 1] = 163; // MAX_COLOR * 0.64;
        img->data[index + 2] = 97; // MAX_COLOR * 0.38;

    } else if (percentNotUsed < 0.97) {

        img->data[index] = 231; // MAX_COLOR * 0.91;
        img->data[index + 1] = 196; // MAX_COLOR * 0.77;
        img->data[index + 2] = 107; // MAX_COLOR * 0.42;

    } else if (percentNotUsed < 1) {

        img->data[index] = 41; // MAX_COLOR * 0.16;
        img->data[index + 1] = 158; // MAX_COLOR * 0.62;
        img->data[index + 2] = 143; // MAX_COLOR * 0.56;
        
    }

}
