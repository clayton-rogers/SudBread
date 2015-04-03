#ifndef FILEOP_H
#define FILEOP_H

#include "CSquare.h"

void GetGrid (CSquare grid[]);							// Get the filename from user, then fetch the file contents
void ReadFile (CSquare grid[], char filename[]);		// Read the file and put the contents into the array

#endif