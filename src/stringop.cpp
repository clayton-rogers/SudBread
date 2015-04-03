#include "stringop.h"

namespace stringop {
	int length (char* letters) {
		// Returns the length of a null-terminated string
		
		int num = 0;
		
		while (letters[num] != '\0') {
			num++;
		}
		
		return num;
	}
	
	int length (const char* letters) {
		// Returns the length of a null-terminated string
		
		int num = 0;
		
		while (letters[num] != '\0') {
			num++;
		}
		
		return num;
	}

/*	// Figure this out eventually
	template <typename T>
	int length (T letters) {
		// Returns the length of a null-terminated string
		
		int num = 0;
		
		while (letters[num] != '\0') {
			num++;
		}
		
		return num;
	}
*/
	
	void addone (char* letters) {
		// Adds one to the last character of the string
		
		// Find the end of the string
		int leng = length(letters);
		
		// Good up to 99
		if (letters[leng-1] == '9') {
			if (isNum(letters[leng-2])) {
				letters[leng-2]++;
				letters[leng-1] = '0';
			} else {
				letters[leng-1] = '1';
				letters[leng] = '0';
				letters[leng+1] = '\0';
			}
		} else {
			letters[leng-1]++;
		}
		
		return;
	}
	
	void give(char * text, const char* value) {
		// Turns a string literal to an array of char
		// NOTE: The char * is assumed to be big enough
		
		// Find the length of the input
		int len = length(value);
		
		// Copy the whole thing
		for (int i = 0; i < len; ++i) {
			text[i] = value[i];
		}
		text[len] = '\0';
	}
	
	void cat(char * text, char * text2) {
		// Concatenacates two strings
		
		int len1 = length(text);
		int len2 = length(text2);
		
		for (int i = 0; i < len2; ++i) {
			text[i+len1] = text2[i];
		}
		text[len1+len2] = '\0';
		
	}
	
	bool isNum(char n) {
		// Tests to see if the character is a number
		
		if (n == '0' ||
			n == '1' ||
			n == '2' ||
			n == '3' ||
			n == '4' ||
			n == '5' ||
			n == '6' ||
			n == '7' ||
			n == '8' ||
			n == '9') {
				return true;
		} else {
			return false;
		}
		
	}
	
	bool isSame(char * word1, char * word2) {
		// Tests whether two strings are the same
		
		int len1 = length(word1);
		int len2 = length(word2);
		
		if (len1 != len2) {
			return false;
		}
		
		for (int i = 0; i < len1; ++i) {
			if (word1[i] != word2[i]) {
				return false;
			}
		}
		
		return true;		
	}
	
	void copy (char* word1, char* word2) {
		// Copies string from word2 to word1
		
		int len = length(word2);
		
		for (int i = 0; i < len; ++i) {
			word1[i] = word2[i];
		}
		word1[len] = '\0';
	}
}
