/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 2

File name: memMap.h

Instructor: Marc Schroeder

Purpose:  creates a new file with the specified name, 
allocates a given amount of space for it on disk, and 
maps the file into memory for writing, returning a 
pointer to the mapped memory or NULL in case of errors.

*/

#ifndef MEMMAP_H
#define MEMMAP_H

#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

char* createFileMap(char* filename, int filesize);

#endif
