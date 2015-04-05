#ifndef FILEOP_H
#define FILEOP_H

#include "Square.h"

void GetGrid (Square grid[]);							// Get the filename from user, then fetch the file contents
void ReadFile (Square grid[], char filename[]);		// Read the file and put the contents into the array

#endif