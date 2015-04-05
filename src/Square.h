#ifndef SQUARE_H
#define SQUARE_H

//*** The Sudoku square class, 81 per Sudoku ***//
struct Square {			// An array is used to represent the entire puzzle
    int m_value;				// The value that the square holds
    bool m_original;			// Whether the value was one of the original inputs
    Square(int value = 0, bool is_original = false)
            : m_value(value), m_original(is_original) {};
};

#endif