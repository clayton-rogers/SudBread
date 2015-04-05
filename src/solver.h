#ifndef SOLVER_H
#define SOLVER_H

#include "Square.h"

//*** Contains all of the functions that actually solve the sudoku puzzle ***//

//*** Sudoku solver functions ***//
bool IsGridCoherent (Square grid[]);	// Checks for any problems with the current grid
void Solve (Square grid[]);			// The function that does the solving and prints every solution found
void Logic (Square grid[]);			// Used logic to solve as much of the Sudoku puzzle as possible
int smallSquare(int pos);				// Returns which small square the square is in
int fix(int);
int FindNumSolved (Square grid[]);		// Finds the number of squares that have been filled out
int FindFirstEmpty (Square grid[]);	// Returns the first empty square in the grid

#endif