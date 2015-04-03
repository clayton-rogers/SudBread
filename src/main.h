#ifndef MAIN_H
#define MAIN_H

#include <iostream>				// Cin / Cout
#include <limits.h>				// INT_MAX

#include "timer.h"	            // The timerclass
#include "stringop.h"// String FXs
#include "CSquare.h"			// Class CSquare
#include "gridop.h"				// Grid operations
#include "solver.h"				// Functions used to solve the sudoku
#include "timetrial.h"			// Unit test / time trial

// ^ Should not require all these headers - Yes, it does

// Functions
void usage();

// Const
const int MAX = 20;		// The maximum number of sudoku's that can be solved

// Standard in/out
using std::cout;
using std::cin;
using std::endl;

using stringop::give;
using stringop::isSame;
using stringop::copy;

#endif