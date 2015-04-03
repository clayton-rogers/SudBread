#ifndef FILEOP_H
#define FILEOP_H

#include "CSquare.h"			// Class

void GetGrid (CSquare grid[]);							// Get the filename from user, then fetch the file contents
void ReadFile (CSquare grid[], char filename[]);		// Read the file and put the contents into the array

#endif