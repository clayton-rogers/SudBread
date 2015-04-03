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
