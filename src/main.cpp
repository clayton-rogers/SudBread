#include <iostream>				// Cin / Cout
#include <limits.h>				// INT_MAX

#include "timer.h"	            // The timerclass
#include "stringop.h"           // String FXs
#include "CSquare.h"			// Class CSquare
#include "gridop.h"				// Grid operations
#include "solver.h"				// Functions used to solve the sudoku
#include "timetrial.h"			// Unit test / time trial
#include "fileop.h"

// ^ Should not require all these headers - Yes, it does


// Standard in/out
using std::cout;
using std::cin;
using std::endl;

using stringop::give;
using stringop::isSame;
using stringop::copy;

// Functions
void usage();

// Const
const int MAX = 20;		// The maximum number of Sudokus that can be solved

int main(int argc, char **argv)
{

    // Parse the command line arguments
    if (argc > 1) {
        char * arg;
        char * filename = new char[100];
        char * test = new char[100];
        CSquare grid[81];
        CTimer timer;

        arg = argv[1];
        if (arg[0] != '-') {
            usage();
            return 1;
        }

        for (int i = 1; i < argc; ++i) {
            arg = argv[i];

            if (arg[0] != '-') {
                continue;
            }
            if (arg[1] == '-') {
                // Full argument
                give(test, "--help");
                if (isSame(arg, test)) {
                    usage();
                    return 0;
                }
                give(test, "--file");
                if (isSame(arg, test)) {
                    copy(filename, argv[i+1]);
                    cout << filename << endl;
                }

            } else {
                // Short argument
                if (arg[1] == 'h') {
                    usage();
                    return 0;
                }
                if (arg[1] == 'f') {
                    copy(filename, argv[i+1]);
                    cout << filename << endl;
                }

            }

            // Load the Sudoku puzzle from file
            ReadFile (grid, filename);
            if (grid[0].value == -1) {
                cout << "The file " << filename << " could not be opened..." << endl;
                return 1;
            }

            if (!IsGridCoherent(grid)) {
                cout << "This Sudoku is not solvable..." << endl;
                return 1;
            }

            // Solve the puzzle
            timer.startTimer();
            Solve(grid);
            timer.stopTimer();

            cout << "This solution took: " << timer.readTimer()
                 << " ms." << endl << endl;
        }

        delete [] filename;
        delete [] test;

        return 0;
    }


    //*** Start of Program ***//

    bool benchmark;				// Whether we are doing a test or a regular run
    char ans;					// An answer box

    // Determine the type of run to be done
    cout << "Would you like to run (R)egular or (B)enchmark? ";
    cin >> ans;

    // If the input fails assume regular
    if (cin.fail()) {
        benchmark = false;
    } else {
        // Otherwise set based on answer
        benchmark = toupper(ans) == 'B';
    }

    // Make sure the input is completely clear
    cin.clear();
    cin.ignore(INT_MAX, '\n');


    // Do the run
    if (benchmark) {

        int ans_num;

        while (1) {
            // Ask the user how many tests should be run
            cout << "How many Sudoku's should be solved (0 to exit): ";
            cin >> ans_num;

            // In case input cannot be interpreted as an integer or other error
            if (cin.fail() || ans_num < 0) {
                // Make sure the input is completely clear
                cin.clear();
                cin.ignore(INT_MAX);
                continue;
            }

            // In case the user wants to exit
            if (ans_num == 0) {
                cout << "The program will now exit." << endl;
                return 0;
            }

            // Catch excessive sized test
            if (ans_num > MAX) {
                cout << "That's too many runs..." << endl;
                cin.clear();
                cin.ignore(INT_MAX);
                continue;
            }

            // Make sure the input is completely clear
            cin.clear();
            cin.ignore(INT_MAX, '\n');

            break;

        }

        // Run the unit test
        RunUnitTest(ans_num);

    } else {
        // Execute the program as normal

        CSquare grid[81];			// Where we are holding the current sudoku puzzle
        CTimer timer;				// Timer object

        // Ask the user where the sudoku is and retrieve it
        GetGrid (grid);

        // Display the grid that has been obtained from file
        cout << endl;
        PrintGrid(grid);
        cout << endl;

        // Check to make sure the grid loaded is in fact good
        if (!IsGridCoherent(grid)) {
            cout << endl << "This Sudoku is not solvable..." << endl;
            return 1;
        }

        // Start the timer and solve
        cout << endl << "The Solutions Found are:" << endl << endl;
        timer.startTimer();
        Solve(grid);
        timer.stopTimer();

        // Output the time that it took
        cout << "Finding all the solutions took: " << timer.readTimer()
            << " ms." << endl << endl;
    }

    return 0;
}


void usage() {
    cout << "usage: SudBread [OPTION]" << endl
         << "Solves Sudoku puzzles" << endl
         << "	OPTIONS:" << endl
         << " 		-f, --file FILE" << endl
         << " 			Solves the Sudoku puzzle contained in FILE" << endl
         << "		-h, --help" << endl
         << "			Displays this help." << endl
         << endl;
}