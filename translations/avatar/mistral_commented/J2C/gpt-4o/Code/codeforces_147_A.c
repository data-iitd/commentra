// Importing necessary C libraries for reading input and writing output
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a character is a Latin letter
bool isLatinLetter(char c) {
    // Check if the character falls within the ASCII range of Latin letters
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is a punctuation mark
bool isPunctuation(char c) {
    // Check if the character is a dot, comma, exclamation mark, or question mark
    return c == '.' || c == ',' || c == '!' || c == '?';
}

int main() {
    // Creating a buffer to read input
    char s[1000]; // Assuming the input string will not exceed 999 characters
    fgets(s, sizeof(s), stdin); // Reading a line of input

    // Creating a buffer to store the output
    char sb[2000]; // Assuming the output will not exceed 1999 characters
    int index = 0; // Index for the output buffer

    // Finding the length of the input string
    int n = strlen(s);

    // Appending the first character of the input string to the output buffer
    sb[index++] = s[0];

    // Iterating through the rest of the characters in the input string
    for (int i = 1; i < n; i++) {
        // Getting the current character from the input string
        char c = s[i];

        // If the current character is a Latin letter
        if (isLatinLetter(c)) {
            // Append it to the output buffer with a space before it if the previous character was not a Latin letter
            if (!isLatinLetter(s[i - 1])) {
                sb[index++] = ' ';
            }
            sb[index++] = c; // Append the Latin letter
        }
        // If the current character is a punctuation mark
        else if (isPunctuation(c)) {
            sb[index++] = c; // Append the punctuation mark directly
        }
    }

    // Null-terminate the output string
    sb[index] = '\0';

    // Writing the output to the console
    printf("%s\n", sb);
    return 0;
}

// <END-OF-CODE>
