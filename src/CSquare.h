//*** The sudoku square class, 81 per Sudoku ***//

#ifndef CSQUARE_H
#define CSQUARE_H


struct CSquare {			// An array is used to represend the entire puzzle
	int value;				// The value that the square holds
	bool original;			// Whether the value was one of the original inputs
};


#endif