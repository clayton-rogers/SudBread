#ifndef SQUARE_H
#define SQUARE_H

//*** The Sudoku square class, 81 per Sudoku ***//
struct Square {			// An array is used to represent the entire puzzle
    int value;				// The value that the square holds
    bool original;			// Whether the value was one of the original inputs
};

#endif