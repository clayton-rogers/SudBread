#ifndef CSQUARE_H
#define CSQUARE_H

//*** The Sudoku square class, 81 per Sudoku ***//
struct CSquare {			// An array is used to represent the entire puzzle
    int value;				// The value that the square holds
    bool original;			// Whether the value was one of the original inputs
};

#endif // SUDBREAD_CSQUARE_H