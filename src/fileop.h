//*** The file operations ***//

#ifndef FILEOP_H
#define FILEOP_H

#include "CSquare.h"			// Class
#include <iostream>				// Cin / Cout
#include <fstream>				// File input / Output
#include <limits.h>				// INT_MAX / RND_MAX

void GetGrid (CSquare grid[]);							// Get the filename from user, then fetch the file contents
void ReadFile (CSquare grid[], char filename[]);		// Read the file and put the contents into the array

using std::cout;
using std::cin;
using std::endl;

using std::ifstream;

#endif