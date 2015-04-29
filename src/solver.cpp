#include "solver.h"

#include <iostream>
#include <stdexcept>

#include "gridop.h"				// To modify the grids

using std::cout;
using std::endl;

const int MAX_SOLUTIONS = 30;		// The maximum number of solutions before the programs quits

bool IsGridCoherent (Square grid[]) {
    // Checks for any problems with the current grid

    // Set of counter bins
    int x[10] = { };

    // Check horizontal lines for doubles
    for (int line = 0; line != 9; ++line) {
        for (int pos = 0; pos != 9; ++pos) {
            // Add one to the proper bin
            x[grid[line*9 + pos].m_value -1]++;
        }

        // Check if any bin has > 1
        for (int i = 0; i != 9; ++i) {
            if (x[i] > 1) {
                return false;
            }

            // Reset x[i] to zero for the next round
            x[i] = 0;
        }
    }

    // This part checks all the vertical lines for doubles (almost the same as previous)
    for (int pos = 0; pos != 9; ++pos) {
        for (int line = 0; line != 9; ++line) {
            // Add one to the proper bin
            x[grid[line*9 + pos].m_value -1]++;
        }

        // Check if any bin has > 1
        for (int i = 0; i != 9; ++i) {
            if (x[i] > 1) return false;

            // Reset x[i] to zero for the next round
            x[i] = 0;
        }
    }

    // This part checks for any problems in any of the 3x3 squares
    // Note: spos / sline is the 3x3 square position and line, ie. square_pos, square_line
    for (int spos = 0; spos != 3; ++spos) {
        for (int sline = 0; sline != 3; ++sline) {
            // for each of the nine larger squares

            for (int pos = 0; pos != 3; ++pos) {
                for (int line = 0; line != 3; ++line) {
                    // for each of the squares in each 3x3

                    // add one to the appropriate bin
                    x[( grid[ (sline*3+line)*9 + (spos*3+pos) ].m_value)-1]++;

                }
            }

            // Check if any bin has > 1
            for (int i = 0; i != 9; i++) {
                if (x[i] > 1) return false;

                // Reset x[i] to zero for the next round
                x[i] = 0;
            }
        }
    }

    // If all the tests so far have not turned up any problems, then the grid is good
    return true;
}

void Solve (Square grid[]) {
    // The function that does the solving and prints every solution found
    // TODO: Look over solver
    int numSolved = 0;						// The number of numbers there currently are on the grid
    int curSquare = 0;						// The square that we are currently on
    int numSoln = 0;							// The number of solutions found to date
    int firstEmpty = FindFirstEmpty(grid);	// The first empty square

    // Get the number of squares that are prefilled
    numSolved = FindNumSolved(grid);

    // Try to use logic first (add when finished code)
    // Logic(grid);

    // This is the solving algorithm, it keeps doing this loop until it finds a sol'n
    // (is it possible that it never finds a sol'n and gets stuck here?) I don't think so
    while (1) {

        if (grid[curSquare].m_value == 9) {

            if (curSquare == firstEmpty) {
                cout << "End of seaching..." << endl;
                break;
            }

            // We have hit a dead end and must go back
            grid[curSquare].m_value = 0;
            numSolved--;

            // Backup and keep backing up till one that is not original
            do {
                curSquare--;
            } while (grid[curSquare].m_original);

            continue;

        }

        // Check if we've been to this square before
        if (grid[curSquare].m_value == 0) {
            numSolved++;
        }

        // Either way, add one
        grid[curSquare].m_value++;

        // Check the state
        if (!IsGridCoherent(grid)) {
            continue;
        } else {
            // Check if a solution is found
            if (numSolved == 81) {
                PrintGrid(grid);
                cout << endl;
                numSoln++;
                if (numSoln >= MAX_SOLUTIONS) {
                    cout << "ERROR: Too many solutions..." << endl;
                    break;
                }
                // It's impossible for any other value to work
                // so going straight to 9 pevents a few loops
                // (because the value that's there now is a sol'n)
                grid[curSquare].m_value = 9;
                continue;
            }

            // Move to the next non-original square
            do {
                ++curSquare;
            } while (grid[curSquare].m_original);
        }

    } // end while

    cout << "The number of solutions found: " << numSoln << endl << endl;

}

void Logic (Square grid[]) {
    // Uses logic to solve the sudoku

    //TODO: Write logic

    int isThere[10];		// Whether that particular number is there
    int pos; 			// The position out of 81
    int location;
    int sum;
    bool isChange = true;

    while (isChange) {

        isChange = false;

        // For each square
        for (int col = 0; col < 9; ++col) {
            for (int row = 0; row < 9; ++row) {

                for (int i = 0; i != 9; ++i) {
                    isThere[i] = 0;
                }

                pos = row*9 + col;

                if (grid[row*9+col].m_value == 0) {
                    continue;
                }

                // Check the relevant col
                for (int i = 0; i < 9; ++i) {
                    isThere[grid[i*9+col].m_value -1] = 1;
                }

                // Check the relevant rows
                for (int i = 0; i < 9; ++i) {
                    isThere[grid[row*9+i].m_value -1] = 1;
                }

                // Figure out which square the square is in and check those
                location = smallSquare(pos);
                location = fix(location);
                for (int i = 0; i != 3; ++i) {
                    isThere[grid[row*9+i+location].m_value -1] = 1;
                }
                location += 9;
                for (int i = 0; i != 3; ++i) {
                    isThere[grid[row*9+i+location].m_value -1] = 1;
                }
                location += 9;
                for (int i = 0; i != 3; ++i) {
                    isThere[grid[row*9+i+location].m_value -1] = 1;
                }

                // Figure out if we can put a number in this
                sum = 0;
                for (int i = 0; i != 9; ++i) {
                    sum += isThere[i];
                }
                if (sum == 8) {
                    for (int i = 0; i != 9; ++i) {
                        if (isThere[i] == 0) {
                            grid[pos].m_value = i;
                            grid[pos].m_original = true;
                            // We set orig tp true because we are sure of this ans
                        }
                    }
                }
            }
        }
    }

}

int smallSquare(int pos) {
    // Returns which small square the square is in

    int row, col, square;

    col = pos%9;
    row = pos/9;

    square = 0;
    square += col/3;
    square += (row/3)*3;

    return square;
}

int fix(int l) {
    int out = 0;

    if (l < 0 || l > 8) {
        throw new std::invalid_argument("Parameter 'l' in 'fix(int l)' is invalid.");
    }

    if (l == 0)
        out = 0;
    else if (l == 1)
        out = 3;
    else if (l == 2)
        out = 6;
    else if (l == 3)
        out = 27;
    else if (l == 4)
        out = 30;
    else if (l == 5)
        out = 33;
    else if (l == 6)
        out = 54;
    else if (l == 7)
        out = 57;
    else if (l == 8)
        out = 60;

    return out;
}

int FindFirstEmpty (Square grid[]) {
    // Returns the first empty square in the grid

    for (int i = 0; i < 81; ++i) {
        if (grid[i].m_value == 0) return i;
    }

    return 81;
}

int FindNumSolved (Square grid[]) {
    // Finds the number of squares that have been filled out

    int num = 0;

    for (int i = 0; i < 81; ++i) {
        if (grid[i].m_value != 0)
            ++num;
    }

    return num;
}
