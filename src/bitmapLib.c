#include "bitmapLib.h"

void writeHeader(char* header, unsigned int res, unsigned int filesize, unsigned int imgSize) {
    
    // Bitmap signature
    header[0] = 'B';
    header[1] = 'M';

    *((unsigned int*)(header + 2)) = filesize;
    // skip 4 bytes (reserved)
    *((unsigned int*)(header + 10)) = IMAGE_DATA_OFFSET; 
    *((unsigned int*)(header + 14)) = HEADER_SIZE;
    *((unsigned int*)(header + 18)) = res; // width
    *((unsigned int*)(header + 18)) = res; // height
    *((unsigned short*)(header + 26)) = PLANES;
    *((unsigned short*)(header + 28)) = BITS_PER_PIZEL;
    *((unsigned int*)(header + 30)) = COMPRESSION;
    *((unsigned int*)(header + 34)) = imgSize;
    *((unsigned int*)(header + 38)) = X_PIXELS_PER_METER;
    *((unsigned int*)(header + 42)) = Y_PIXELS_PER_METER;
    *((unsigned int*)(header + 46)) = TOTAL_COLORS;
    *((unsigned int*)(header + 50)) = IMPORTANT_COLORS;
}