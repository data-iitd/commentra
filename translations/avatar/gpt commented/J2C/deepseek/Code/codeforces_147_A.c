#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if a character is a lowercase Latin letter
int isLatinLetter(char c) {
    return c >= 'a' && c <= 'z'; // Returns 1 if c is between 'a' and 'z', 0 otherwise
}

// Function to check if a character is a punctuation mark
int isPunctuation(char c) {
    // Check for specific punctuation characters
    if (c == '.') return 1; 
    if (c == ',') return 1; 
    if (c == '!') return 1; 
    if (c == '?') return 1; 
    return 0; // Returns 0 if c is not a recognized punctuation
}

int main() {
    // Create a buffer to read input from the console
    char buffer[1024];
    // Read a line of input from the user
    fgets(buffer, sizeof(buffer), stdin);
    // Remove the newline character if present
    buffer[strcspn(buffer, "\n")] = 0;
    
    // Initialize a string to construct the output string
    char output[2048] = "";
    int n = strlen(buffer); // Get the length of the input string
    
    // Append the first character of the input string to the output string
    char firstChar[2] = {buffer[0], '\0'};
    strcat(output, firstChar);
    
    // Loop through the input string starting from the second character
    for (int i = 1; i < n; i++) {
        char c = buffer[i]; // Get the current character
        
        // Check if the current character is a Latin letter
        if (isLatinLetter(c)) {
            // If the previous character is not a Latin letter, append a space
            if (!isLatinLetter(buffer[i - 1])) {
                strcat(output, " ");
            }
            // Append the current Latin letter to the output string
            char charStr[2] = {c, '\0'};
            strcat(output, charStr);
        } 
        // Check if the current character is a punctuation mark
        else if (isPunctuation(c)) {
            char charStr[2] = {c, '\0'};
            strcat(output, charStr); // Append the punctuation mark to the output string
        }
    }
    
    // Print the constructed output string
    printf("%s\n", output);
    
    return 0;
}
