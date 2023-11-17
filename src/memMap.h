
#ifndef MEMMAP_H
#define MEMMAP_H

#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

char* createFileMap(char* filename, int filesize);

#endif