#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);
    
    int count[MAX_CHAR] = {0}; // Array to count occurrences of each character
    int uniqueChars = 0; // To count unique characters

    for (int i = 0; s[i] != '\0'; i++) {
        if (count[(unsigned char)s[i]] == 0) {
            uniqueChars++; // New unique character found
        }
        count[(unsigned char)s[i]]++; // Increment the count for the character
    }

    // Check if there are exactly 2 unique characters and both appear exactly 2 times
    int ok = 1; // Assume it's valid
    if (uniqueChars == 2) {
        for (int i = 0; i < MAX_CHAR; i++) {
            if (count[i] != 0 && count[i] != 2) {
                ok = 0; // Found a character that does not appear exactly 2 times
                break;
            }
        }
    } else {
        ok = 0; // Not exactly 2 unique characters
    }

    if (ok) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
