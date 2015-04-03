#include <ctype.h>
#include "stringop.h"

namespace stringop {
    int get_length(const char *letters) {
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

    void add_one(char *letters) {
        // Adds one to the last character of the string

        // Find the end of the string
        int length = get_length(letters);

        // Good up to 99
        if (letters[length -1] == '9') {
            if (isdigit(letters[length -2])) {
                letters[length -2]++;
                letters[length -1] = '0';
            } else {
                letters[length -1] = '1';
                letters[length] = '0';
                letters[length +1] = '\0';
            }
        } else {
            letters[length -1]++;
        }

        return;
    }

    void give(char * text, const char* value) {
        // Turns a string literal to an array of char
        // NOTE: The char * is assumed to be big enough

        // Find the length of the input
        int len = get_length(value);

        // Copy the whole thing
        for (int i = 0; i < len; ++i) {
            text[i] = value[i];
        }
        text[len] = '\0';
    }

    bool isSame(char * word1, char * word2) {
        // Tests whether two strings are the same

        int len1 = get_length(word1);
        int len2 = get_length(word2);

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

        int len = get_length(word2);

        for (int i = 0; i < len; ++i) {
            word1[i] = word2[i];
        }
        word1[len] = '\0';
    }
}
