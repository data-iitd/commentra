#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if a character is a Latin letter
int isLatinLetter(char c) {
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is a punctuation mark
int isPunctuation(char c) {
    if (c == '.') return 1;
    if (c == ',') return 1;
    if (c == '!') return 1;
    if (c == '?') return 1;
    return 0;
}

int main() {
    // Create a buffer to read input from the console
    char s[1000];
    // Read the input string
    fgets(s, sizeof(s), stdin);
    // Get the length of the input string
    int n = strlen(s);
    // Create a buffer to build the output string
    char sb[2000];
    int sbIndex = 0;
    // Append the first character of the input string to the buffer
    sb[sbIndex++] = s[0];
    // Loop through the input string starting from the second character
    for (int i = 1; i < n; i++) {
        char c = s[i];
        // Check if the character is a Latin letter
        if (isLatinLetter(c)) {
            // If the previous character is not a Latin letter, add a space
            if (!isLatinLetter(s[i - 1])) {
                sb[sbIndex++] = ' ';
            }
            // Append the current Latin letter to the buffer
            sb[sbIndex++] = c;
        }
        // Check if the character is a punctuation mark
        else if (isPunctuation(c)) {
            // Append the punctuation mark to the buffer
            sb[sbIndex++] = c;
        }
    }
    // Print the final string with spaces added between Latin letters
    sb[sbIndex] = '\0';
    printf("%s\n", sb);
    return 0;
}
