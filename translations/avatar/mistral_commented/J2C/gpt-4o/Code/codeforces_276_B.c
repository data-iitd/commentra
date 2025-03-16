#include <stdio.h>      // Standard input/output library
#include <stdlib.h>     // Standard library for memory allocation
#include <string.h>     // String manipulation functions
#include <ctype.h>      // Character handling functions

#define MAX_CHAR 256   // Maximum number of different characters

int main() {
    char str[1000];     // Buffer to read the input string
    int charCount[MAX_CHAR] = {0}; // Array to store character counts
    int oddCount = 0;   // Count of odd-valued character counts

    // Read the input string
    fgets(str, sizeof(str), stdin);

    // Iterate through each character in the input string
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i]; // Get the current character

        // Increment the count for the character if it's a valid character
        if (ch >= 0 && ch < MAX_CHAR) {
            charCount[ch]++;
        }
    }

    // Iterate through the character counts to count odd-valued entries
    for (int i = 0; i < MAX_CHAR; i++) {
        if (charCount[i] % 2 != 0) {
            oddCount++; // Increment the odd count
        }
    }

    // Determine the output based on the odd count
    if (oddCount <= 1 || oddCount % 2 != 0) {
        printf("First\n"); // Output "First" if the odd count is 1 or odd
    } else {
        printf("Second\n"); // Output "Second" if the odd count is even
    }

    return 0; // Return success
}

// <END-OF-CODE>
