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
    if (imgRes > MAX_RESOLUTION || imgRes < 1)
    {
        printf("Invalid resolution\n");
        invalidArgValue = TRUE;
    }
    else if (threadCount > imgRes || threadCount < 1)
    {
        printf("Invalid thread count\n");
        invalidArgValue = TRUE;
    }
    if (iterations > MAX_ITERATIONS || iterations < 1)
    {
        printf("Invalid iterations\n");
        invalidArgValue = TRUE;
    }
    if (invalidArgValue)
    {
        return 0;
    }

    unsigned int imgSize = (imgRes << 1) * BYTES_PER_PIXEL; // size of image data
    unsigned int filesize = calculateFilesize(imgRes);    // size of image data + header

    char *bmpFile = createFileMap(filename, filesize);
    writeHeader(bmpFile, imgRes, filesize, imgSize);
    coordinateRange *ranges = divideCoordinates(threadCount, imgRes);

    pthread_t threads[threadCount];

    for (int i = 0; i < threadCount; i++) {
        struct renderRangeParams *params = malloc(sizeof(struct renderRangeParams));
        if (params == NULL) {
            // Handle memory allocation failure
            exit(EXIT_FAILURE);
        }

        params->iterations = iterations;
        params->imgRes = imgRes;
        params->bmpFile = bmpFile;
        params->range = &ranges[i];

        if (pthread_create(&threads[i], NULL, renderRange, params) != 0) {
            // Handle thread creation failure
            free(params);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete before exiting
    for (int i = 0; i < threadCount; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            // Handle thread joining failure
            exit(EXIT_FAILURE);
        }
    }

    printf("DONE\n");
    return 0;
}

    void *renderRange(void *args)
    {
        renderRangeParams *params = (renderRangeParams *)args;
        coordinateRange *range = params->range;
        int iterations = params->iterations;
        int imgRes = params->imgRes;
        char *imgData = params->bmpFile;

        int x = range->xStart;
        int y = range->yStart;
        char done = FALSE;
        int iterationsRemaining; // number of iterations not used
        float percentRemaining;  // percent of iterations not used
        while (!done)
        {
            while (!done && x < imgRes)
            {
                iterationsRemaining = mandelbrot(x, y, iterations, imgRes);
                percentRemaining = iterationsRemaining / (float)iterations;
                drawPixel(x, y, imgRes, percentRemaining, imgData);

                if (x == range->xEnd && y == range->yEnd)
                {
                    done = TRUE;
                }
                x++;
            }
            y++;
            x = 0;
        }
        return 0;
    }

    void drawPixel(int x, int y, unsigned int imgRes, float percentNotUsed, char *imgData)
    {
        RGBColour colour;
        if (percentNotUsed == 0)
        {
            colour = BLACK;
        }
        else if (percentNotUsed < 0.85)
        {
            colour = SUNSET_RED;
        }
        else if (percentNotUsed < 0.92)
        {
            colour = RED_ORANGE;
        }
        else if (percentNotUsed < 0.97)
        {
            colour = LIGHT_ORANGE;
        }
        else if (percentNotUsed < 1)
        {
            colour = CYAN_TEAL;
        }

        writePixel(x, y, imgRes, &colour, imgData);
        return;
    }