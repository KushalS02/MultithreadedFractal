#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Incorrect number of arguements");
    } else {
        int imgRes = atoi(argv[1]);
        int iterations = atoi(argv[2]);
        char *filename = argv[3];
    }

    

    return 0;
}