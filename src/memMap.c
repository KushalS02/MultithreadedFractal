/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 2

File name: memMap.c

Instructor: Marc Schroeder

Purpose:  creates a new file with the specified name, 
allocates a given amount of space for it on disk, and 
maps the file into memory for writing, returning a 
pointer to the mapped memory or NULL in case of errors.

*/

#include "memMap.h"


char* createFileMap(char* filename, int filesize) {
    
    int fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, (mode_t)S_IRWXU); //creates file
    if (fd == -1) {
        perror("Error creating file: ");
        return NULL;
    }

    if (fallocate(fd, 0, 0, filesize) == -1) { //allocates disk space to file
        perror("Error allocating space: ");
        return NULL;
    }

    char *fileMap = mmap(NULL, filesize, PROT_WRITE, MAP_SHARED, fd, 0); //maps file to memory
    return fileMap;
}
