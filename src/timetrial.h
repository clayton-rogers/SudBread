//*** Runs the time trial, testing the speed of the algorithm ***//

#ifndef TIMETRIAL_H
#define TIMETRIAL_H

#include <iostream>
#include <limits.h>				// INT_MAX / RND_MAX

#include "timer.h"	            // Timer object
#include "stringop.h"           // String manipulation
#include "CSquare.h"			// Class CSquare
#include "solver.h"				// Functions used to solve the sudoku
#include "fileop.h"				// File operations
#include "gridop.h"				// Grid operations

void RunUnitTest (int MAX);				// Run the unit test and output the results
					// Asks the user what basefilename and then creates the rest
void GetFilename (char basename[]);
void GetNextFilename (char basename[], int num, char filename[]);	// Loads the required filename

using stringop::length;
using stringop::addone;

using std::cout;
using std::cin;
using std::endl;

#endif