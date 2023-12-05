/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 2

File name: mandelbrot.h

Instructor: Marc Schroeder

Purpose: mandelbrot fractal functions that compute the image

*/

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

/*
Function: coordinates

Purpose: increments yPixel and calls functions to create the fractal image

Input: 
 
     iterations - an int which specifies the max number of iterations that can
                  be performed on the mandelbrot equation

     xPixel - an int which specifies the x-coordinates on the image

     yPixel - an int which specifies the y-coordinates on the image

     imageSize - an int which specifies the dimensions of the image

Output:

     img - an image on which the mandelbrot fractal will be drawn

Details: 

     Recursively increments yPixel while it is in the bounds of the image.
     Calls xCoordinates before each increment.
 */
void coordinates(Image* img, int iterations, int xPixel, int yPixel, int imageSize);

/*
Function: xCoordinates

Purpose: increments xPixel and call other functions to create fractal image

Inputs:

     iterations - an int which specifies the max number of iterations that
                  can be performed on the mandelbrot equation

     xPixel - an int which specifies the x-coordinates on the image

     yPixel - an int which specifies the y-coordinates on the image

     imageSize - an int which specifies the dimensions of the image

Output:

     img - an image on which the mandelbrot fractal will be drawn

Details:

     Recusively increments xPixel while it is in the bounds of the image
     
     Calls functions to convert image coordinates to complex coordinates. The
     mandelbrot function is then called to find how many iterations were
     performed on the equation with the inputted complex coordinates. With this
     information, the draw function is called and the image coordinate painted.
 */
void xCoordinates(Image* img, int iterations, int xPixel, int yPixel, int imageSize);

/*
Function: xConvert

Purpose: converts image x-coordinate to complex x-coordinate

Inputs:

     xPixel - an int which specifies the x-coordinates on the image

Return:

     double - the complex x-coordinate
 */
double xConvert(int xPixel, int imageSize);

/*
Function: yConvert

Purpose: converts image y-coordinate to complex y-coordinate

Inputs:

     yPixel - an int which specifies the y-coordinates on the image

Return:

     double - the complex y-coordinate
 */
double yConvert(int yPixel, int imageSize);

/*
Function: mandelbrot

Purpose: returns the number iterations that were not used on the mandelbrot
         equation

Input:

     xComplex - a double that is a x-coordinate on the complex plane

     yComplex - a double that is a y-coordinate on the complex plane

     iterations - an int which specifies the max number of iterations which
                  can be performed

     zx - a double which is the real part of the mandelbrot equation

     zy - a double which is the imaginary part of the mandelbrot equation

Return:

     int - the number of iterations that were not used

Details:

     Recursively iterates the mandelbrot function until the equation evaluates
     to a distance that is more that 2 from the origin
     AND
     while the number of iterations left is greater than zero
 */
int mandelbrot(double xComplex, double yComplex, int iterations, double zx, double zy);

/*
Function: draw

Purpose: Paints the location of the given coordinates a specific colour
         depending on percentNotUsed

Inputs:

     xPixel - an int which specifies the x-coordinates on the image

     yPixel - an int which specifies the y-coordinates on the image

     percentNotUsed - a double which specifies what percentage of iterations,
                      out of the max, were no used

Outputs:

     img: the image on which the fractal is drawn

Details:

     Paints the coordinates one of 6 colours depending on how many iterations
     were performed on these coordinates in the mandelbrot function
     If the coordinates are in the mandelbrot set, the location is coloured 
     black
 */
void draw(Image* img, int xPixel, int yPixel, double percentNotUsed);

#endif
