#ifndef COORDINATE_DIVIDER_H
#define COORDINATE_DIVIDER_H

#include <stdlib.h>

typedef struct coordinateRange {
    int xStart;
    int yStart;
    int xEnd;
    int yEnd;
} coordinateRange;

struct coordinateRange* divideCoordinates(int threadCount, int resolution);
void testDivideCoordinates(int threadCount, int resolution);

#endif
