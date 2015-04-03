/*
Copyright 2011 Clayton Rogers

This file is part of BFint.

BFint is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

BFint is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with BFint.  If not, see <http://www.gnu.org/licenses/>.
*/



/* NOTE: These are functions which are mostly the same as the functions included
 * with <cstring> but I didn't realize it when I wrote it
 */

#ifndef STRINGOP_H
#define STRINGOP_H

#include <iostream>

namespace stringop {

int length (char* letters);					// Returns the length of a null-terminated string
int length (const char* letters);			// Same ^
void addone (char* letters);				// Adds one to the last character of the string
void give (char* text, const char* value);	// Turns a string literal to an array of char
void cat(char * text1, char * text2);		// Concatenates two strings
bool isNum(char );							// Tests to see if the character is a number
bool isSame(char* word1, char* word2);		// Tests whether two strings are the same
void copy(char* word1, char* word2);		// Copies string from word2 to word1

}

#endif
