#include "timetrial.h"

#include <iostream>

#include "timer.h"	            // Timer object
#include "stringop.h"           // String manipulation
#include "CSquare.h"			// Class CSquare
#include "solver.h"				// Functions used to solve the sudoku
#include "fileop.h"				// File operations
#include "gridop.h"				// Grid operations

using stringop::length;
using stringop::addone;

using std::cout;
using std::cin;
using std::endl;

void RunUnitTest (int MAX) {
    // Run the unit test and output the results

    CSquare grid[81];		// Spot to hold the current Sudoku puzzle
    CTimer timer;			// To time the runs

    double totalTime = 0;
    int runs = 0;

    char filename[50];		// Memory is cheap.

    // Get the basename from the user
    GetFilename(filename);

    for (int i = 1; i <= MAX; ++i) {

        // Increment the filename
        addone(filename);
        cout << endl << "Filename: " << filename << endl;

        // Put the contents of the file into the grid
        ReadFile(grid, filename);

        // Check for errors reading the file
        if (grid[0].value == -1) {
            cout << "The file " << filename << " could not be opened..." << endl;
            continue;
        }

        // Print the grid that was obtained
        PrintGrid(grid);
        cout << endl;

        // Check whether the grid is viable
        if (!IsGridCoherent(grid)) {
            cout << "This Sudoku is not solvable..." << endl;
            continue;
        }

        // Solve the sudoku and record the time
        timer.startTimer();
        Solve(grid);
        timer.stopTimer();

        // Output some stats
        cout << "Time taken: " << timer.readTimer() << " ms" << endl;

        // Update the statistics
        totalTime += timer.readTimer();
        runs ++;
    }

    // Output the results from the tests
    cout << endl << endl
         << "A total of " << runs << " tests were conducted." << endl;
    if (runs > 0) {
        cout << "The average time per run was " << totalTime / double(runs) << " ms." << endl;
    }

}

void GetFilename (char basename[]) {
    // Asks the user what basefilename and then creates the rest

    int len;

    // Get the base filename
    cout << "Enter the base filename: ";
    cin >> basename;

    // Append a one to the end of the basename
    len = length(basename);
    basename[len] = '0';
    basename[len+1] = '\0';

    return;
}
