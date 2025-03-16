#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a character is a lowercase Latin letter
bool isLatinLetter(char c) {
    return c >= 'a' && c <= 'z'; // Returns true if c is between 'a' and 'z'
}

// Function to check if a character is a punctuation mark
bool isPunctuation(char c) {
    // Check for specific punctuation characters
    return c == '.' || c == ',' || c == '!' || c == '?'; // Returns true if c is a recognized punctuation
}

int main() {
    // Create a buffer to read input
    char s[1000]; // Assuming the input will not exceed 999 characters
    // Read a line of input from the user
    fgets(s, sizeof(s), stdin);
    
    // Initialize a buffer to construct the output string
    char output[2000]; // Assuming the output will not exceed 1999 characters
    int j = 0; // Index for output buffer
    int n = strlen(s); // Get the length of the input string
    
    // Append the first character of the input string to the output buffer
    output[j++] = s[0];
    
    // Loop through the input string starting from the second character
    for (int i = 1; i < n; i++) {
        char c = s[i]; // Get the current character
        
        // Check if the current character is a Latin letter
        if (isLatinLetter(c)) {
            // If the previous character is not a Latin letter, append a space
            if (!isLatinLetter(s[i - 1])) {
                output[j++] = ' ';
            }
            // Append the current Latin letter to the output buffer
            output[j++] = c;
        } 
        // Check if the current character is a punctuation mark
        else if (isPunctuation(c)) {
            output[j++] = c; // Append the punctuation mark to the output buffer
        }
    }
    
    // Null-terminate the output string
    output[j] = '\0';
    
    // Print the constructed output string
    printf("%s\n", output);
    
    return 0; // Return success
}

// <END-OF-CODE>
