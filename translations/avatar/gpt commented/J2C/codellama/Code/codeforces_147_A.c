#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Method to check if a character is a lowercase Latin letter
bool isLatinLetter(char c) {
    return c >= 'a' && c <= 'z'; // Returns true if c is between 'a' and 'z'
}

// Method to check if a character is a punctuation mark
bool isPunctuation(char c) {
    // Check for specific punctuation characters
    if (c == '.') return true; 
    if (c == ',') return true; 
    if (c == '!') return true; 
    if (c == '?') return true; 
    return false; // Returns false if c is not a recognized punctuation
}

int main() {
    // Create a buffer to read input from the console
    char s[1000]; 
    // Create a buffer to construct the output string
    char sb[1000]; 
    int n; // Get the length of the input string
    
    // Read a line of input from the user
    fgets(s, 1000, stdin); 
    // Initialize the output string
    strcpy(sb, ""); 
    n = strlen(s); // Get the length of the input string
    
    // Append the first character of the input string to the output string
    strncat(sb, s, 1); 
    
    // Loop through the input string starting from the second character
    for (int i = 1; i < n; i++) {
        char c = s[i]; // Get the current character
        
        // Check if the current character is a Latin letter
        if (isLatinLetter(c)) {
            // If the previous character is not a Latin letter, append a space
            if (!isLatinLetter(s[i - 1])) {
                strncat(sb, " ", 1); 
            }
            // Append the current Latin letter to the output string
            strncat(sb, &c, 1); 
        } 
        // Check if the current character is a punctuation mark
        else if (isPunctuation(c)) {
            strncat(sb, &c, 1); // Append the punctuation mark to the output string
        }
    }
    
    // Print the constructed output string
    printf("%s\n", sb); 
    
    return 0;
}

