#ifndef TIMETRIAL_H
#define TIMETRIAL_H

void RunUnitTest (int MAX);				// Run the unit test and output the results
                    // Asks the user what base filename and then creates the rest
void GetFilename (char basename[]);
void GetNextFilename (char basename[], int num, char filename[]);	// Loads the required filename

#endif