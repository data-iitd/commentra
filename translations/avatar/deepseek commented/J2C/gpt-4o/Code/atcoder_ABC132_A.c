#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

int main() {
    char s[MAX_CHAR];
    int count[MAX_CHAR] = {0}; // Array to store character counts
    int uniqueChars = 0; // To count unique characters

    // Read the input string
    scanf("%s", s);

    // Count occurrences of each character
    for (int i = 0; s[i] != '\0'; i++) {
        if (count[(unsigned char)s[i]] == 0) {
            uniqueChars++; // New unique character found
        }
        count[(unsigned char)s[i]]++; // Increment the count for the character
    }

    // Check if all characters appear exactly twice
    int ok = 1; // Flag to check the conditions
    for (int i = 0; i < MAX_CHAR; i++) {
        if (count[i] != 0 && count[i] != 2) {
            ok = 0; // If any character count is not 2, set ok to false
            break;
        }
    }

    // Check if there are exactly 2 unique characters
    if (ok && uniqueChars == 2) {
        printf("Yes\n"); // Print "Yes" if the conditions are met
    } else {
        printf("No\n"); // Print "No" otherwise
    }

    return 0;
}

// <END-OF-CODE>
