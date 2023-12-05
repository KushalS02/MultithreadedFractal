#include "main.h"

int main(int argc, char *argv[])
{

    if (argc != 5)
    {
        printf("Invalid number of arguements\n");
        return 0;
    }

    unsigned int imgRes = atoi(argv[1]);
    unsigned int iterations = atoi(argv[2]);
    unsigned int threadCount = atoi(argv[3]);
    char *filename = argv[4];

    char invalidArgValue = FALSE;    
    if (imgRes > MAX_RESOLUTION || imgRes < 1) {
        printf("Invalid resolution\n");
        invalidArgValue = TRUE;
    } else if (threadCount > imgRes || threadCount < 1) {
        printf("Invalid thread count\n");
        invalidArgValue = TRUE;
    }
    if (iterations > MAX_ITERATIONS || iterations < 1){
        printf("Invalid iterations\n");
        invalidArgValue = TRUE;
    }
    if (invalidArgValue) {
        return 0;
    }

    unsigned int imgSize = (imgRes << 1) * BYTES_PER_PIXEL; // size of image data
    unsigned int filesize = imgSize + IMAGE_DATA_OFFSET; // size of image data + header

    char *bmpFile = createFileMap(filename, filesize);
    writeHeader(bmpFile, imgRes, filesize, imgSize);
    coordinateRange *ranges = divideCoordinates(threadCount, imgRes);

    for(int i = 0; i < threadCount; i++) {
        
    }
    free(ranges);
    return 0;
}

void renderRange(coordinateRange* range) {
    int x = range->xStart;
    int y = range->yStart;
    while(!(x == range->xEnd && y == range->yEnd)) {
        
    }
}