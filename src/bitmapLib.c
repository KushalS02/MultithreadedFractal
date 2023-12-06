#include "bitmapLib.h"

unsigned int calculateFilesize(unsigned int imgRes) {
    unsigned int rowDataSize = imgRes * BYTES_PER_PIXEL;
    unsigned int rowPaddingSize = (4 - (rowDataSize % 4)) % 4;
    unsigned int pixelDataSize = (rowPaddingSize + rowDataSize) * imgRes;

    return pixelDataSize + IMAGE_DATA_OFFSET;
}

void writeHeader(char *header, unsigned int res, unsigned int filesize, unsigned int imgSize)
{

    // Bitmap signature
    header[0] = 'B';
    header[1] = 'M';

    *((unsigned int *)(header + 2)) = filesize;
    // skip 4 bytes (reserved)
    *((unsigned int *)(header + 10)) = IMAGE_DATA_OFFSET;
    *((unsigned int *)(header + 14)) = HEADER_SIZE;
    *((unsigned int *)(header + 18)) = res; // width
    *((unsigned int *)(header + 22)) = res; // height
    *((unsigned short *)(header + 26)) = PLANES;
    *((unsigned short *)(header + 28)) = BITS_PER_PIXEL;
    *((unsigned int *)(header + 30)) = COMPRESSION;
    *((unsigned int *)(header + 34)) = imgSize;
    *((unsigned int *)(header + 38)) = X_PIXELS_PER_METER;
    *((unsigned int *)(header + 42)) = Y_PIXELS_PER_METER;
    *((unsigned int *)(header + 46)) = TOTAL_COLORS;
    *((unsigned int *)(header + 50)) = IMPORTANT_COLORS;
    return;
}

void writePixel(unsigned int x, unsigned int y, unsigned int imgRes, RGBColour *colour, char *bmpFile)
{
    int rowDataSize = imgRes * BYTES_PER_PIXEL;
    int rowPaddingSize = (4 - (rowDataSize % 4)) % 4;
    int rowSize = rowPaddingSize + rowDataSize;

    int pixelOffset = (y * rowSize + x * BYTES_PER_PIXEL) + IMAGE_DATA_OFFSET;

    bmpFile[pixelOffset + 0] = colour->b; // Blue component
    bmpFile[pixelOffset + 1] = colour->g; // Green component
    bmpFile[pixelOffset + 2] = colour->r; // Red component

    // Calculate padding needed for this row
    int bytesWrittenThisRow = (x + 1) * BYTES_PER_PIXEL;
    if (bytesWrittenThisRow == rowDataSize)
    {
        for (int i = 0; i < rowPaddingSize; i++)
        {
            bmpFile[pixelOffset + BYTES_PER_PIXEL + i] = 0x00; // Padding with zeros
        }
    }
    return;
}
