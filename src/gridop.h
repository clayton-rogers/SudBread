//*** Contains the functions that handle the grid operations ***//

#ifndef GRIDOP_H
#define GRIDOP_H

#include <iostream>
#include "CSquare.h"

void PrintGrid (CSquare grid[]);						// Prints the grid on the screen
void MoveGrid (CSquare grid1[], CSquare grid2[]);		// Move the values from grid 1 to 2
void SwapGrid (CSquare grid1[], CSquare grid2[]);		// Swaps the grids

#endif