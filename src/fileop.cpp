#include "fileop.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

using std::ifstream;

void GetGrid (Square grid[]) {
    // Get the filename from user, then fetch the file contents

    ifstream fin;
    char inputFile[60];
    bool fileFail;

    // Get the filename and open the file
    do {

        fileFail = false;

        cout << "Enter the input filename: ";
        cin >> inputFile;

        fin.open(inputFile);

        if (fin.fail()) {
            fileFail = true;
            cout << "The file " << inputFile << " could not be opened..." << endl << endl;
        }

    } while (fileFail);

    // Do the actual reading into the array
    for (int i = 0; i <= 80; ++i) {

        fin >> grid[i].value;

        // Set original; makes the value protected
        grid[i].original = grid[i].value != 0;
    }
}

void ReadFile (Square grid[], char filename[]) {
    // Read the file and put the contents into the array

    ifstream fin;
    fin.open(filename);

    if (fin.fail()) {
        grid[0].value = -1;
        return;
    }

    // Do the actual reading into the array
    for (int i = 0; i < 81; ++i) {

        fin >> grid[i].value;

        // Set original; makes the value protected
        grid[i].original = grid[i].value != 0;
    }
}
