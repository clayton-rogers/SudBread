#include "gridop.h"

#include <iostream>

using namespace std;

void PrintGrid (Square grid[]) {
    // Prints the grid on the screen

    // Prints '-' when the value is not known
    for (int line = 0; line <= 8; ++line) {
        for (int pos = 0; pos <= 8; ++pos) {
            if (grid[line*9 + pos].value != 0) {
                cout << grid[line*9 + pos].value << " ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
}

void MoveGrid (Square grid1[], Square grid2[]) {
    // Move the values from grid 1 to 2

    for (int i = 0; i <= 80; ++i) {
        grid2[i].value = grid1[i].value;
        grid2[i].original = grid1[i].original;
    }
}

void SwapGrid (Square grid1[], Square grid2[]) {
    // Swaps the grids

    // Create a temp holding
    Square tmp[81];

    // Do the move operations
    MoveGrid(grid2, tmp);
    MoveGrid(grid1, grid2);
    MoveGrid(tmp, grid1);
}