#define BYTES_PER_PIXEL 3
#define BITS_PER_PIZEL 24
#define IMAGE_DATA_OFFSET 54
#define HEADER_SIZE 40
#define PLANES 1
#define COMPRESSION 0
#define X_PIXELS_PER_METER 0
#define Y_PIXELS_PER_METER 0
#define TOTAL_COLORS 0
#define IMPORTANT_COLORS 0

void writeHeader(char* header, unsigned int res, unsigned int filesize, unsigned int imgSize);