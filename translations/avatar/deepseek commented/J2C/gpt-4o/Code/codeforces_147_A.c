#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a character is a Latin letter
bool isLatinLetter(char c) {
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is a punctuation mark
bool isPunctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?';
}

// Main function: Entry point of the program
int main() {
    // Create a buffer to read the input string
    char s[1000]; // Assuming the input string will not exceed 999 characters
    fgets(s, sizeof(s), stdin); // Read the input string

    // Create a buffer to build the output string
    char sb[2000]; // Output buffer, assuming it can hold enough characters
    int j = 0; // Index for the output buffer

    // Get the length of the input string
    int n = strlen(s);

    // Append the first character of the input string to the output buffer
    if (n > 0) {
        sb[j++] = s[0];
    }

    // Loop through the input string starting from the second character
    for (int i = 1; i < n; i++) {
        char c = s[i];

        // Check if the character is a Latin letter
        if (isLatinLetter(c)) {
            // If the previous character is not a Latin letter, add a space
            if (!isLatinLetter(s[i - 1])) {
                sb[j++] = ' ';
            }
            // Append the current Latin letter to the output buffer
            sb[j++] = c;
        }
        // Check if the character is a punctuation mark
        else if (isPunctuation(c)) {
            // Append the punctuation mark to the output buffer
            sb[j++] = c;
        }
    }

    // Null-terminate the output string
    sb[j] = '\0';

    // Print the final string with spaces added between Latin letters
    printf("%s\n", sb);

    return 0;
}

// <END-OF-CODE>
