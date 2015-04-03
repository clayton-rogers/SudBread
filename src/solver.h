//*** Contains all of the functions that actually solve the sudoku puzzle ***//

#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>

#include "gridop.h"				// To modify the grids
#include "CSquare.h"			// Class

//*** Sudoku solver functions ***//
bool IsGridCoherent (CSquare grid[]);	// Checks for any problems with the current grid
void Solve (CSquare grid[]);			// The function that does the solving and prints every solution found
void Logic (CSquare grid[]);			// Used logic to solve as much of the SUdoku puzzle as posible
int smallSquare(int pos);				// Returns which small square the square is in
int fix(int);
int FindNumSolved (CSquare grid[]);		// Finds the number of squares that have been filled out
int FindFirstEmpty (CSquare grid[]);	// Returns the first empty square in the grid

using std::cout;
using std::endl;

const int MAX_SOLN = 30;		// The maximum number of solutions before the programs quits

#endif