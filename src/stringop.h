#ifndef STRINGOP_H
#define STRINGOP_H

namespace stringop {

int get_length(const char *letters);			// Returns the length of a null-terminated string
void add_one(char *letters);				// Adds one to the last character of the string
void give (char* text, const char* value);	// Turns a string literal to an array of char
bool isSame(char* word1, char* word2);		// Tests whether two strings are the same
void copy(char* word1, char* word2);		// Copies string from word2 to word1

}

#endif
