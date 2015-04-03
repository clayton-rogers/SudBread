#ifndef SOLVER_H
#define SOLVER_H

#include "CSquare.h"			// Class

//*** Contains all of the functions that actually solve the sudoku puzzle ***//

//*** Sudoku solver functions ***//
bool IsGridCoherent (CSquare grid[]);	// Checks for any problems with the current grid
void Solve (CSquare grid[]);			// The function that does the solving and prints every solution found
void Logic (CSquare grid[]);			// Used logic to solve as much of the Sudoku puzzle as possible
int smallSquare(int pos);				// Returns which small square the square is in
int fix(int);
int FindNumSolved (CSquare grid[]);		// Finds the number of squares that have been filled out
int FindFirstEmpty (CSquare grid[]);	// Returns the first empty square in the grid

#endif