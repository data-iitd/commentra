#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

int main() {
    // Initialize input buffer
    char str[1000]; // Assuming the input string will not exceed 999 characters
    fgets(str, sizeof(str), stdin); // Read a line of input from the user

    // Create an array to count occurrences of each character
    int count[MAX_CHAR] = {0};
    int oddCount = 0; // Initialize counter for characters with odd occurrences

    // Iterate through each character in the input string
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch != '\n') { // Ignore the newline character
            count[ch]++;
        }
    }

    // Count how many characters have an odd number of occurrences
    for (int i = 0; i < MAX_CHAR; i++) {
        if (count[i] % 2 != 0) {
            oddCount++;
        }
    }

    // Determine the output based on the count of odd occurrences
    if (oddCount <= 1 || oddCount % 2 != 0) {
        printf("First\n"); // Output "First" if conditions are met
    } else {
        printf("Second\n"); // Output "Second" otherwise
    }

    return 0;
}

// <END-OF-CODE>
