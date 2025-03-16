#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Method to check if a character is a lowercase Latin letter
int isLatinLetter(char c) {
    return c >= 'a' && c <= 'z'; // Returns true if c is between 'a' and 'z'
}

// Method to check if a character is a punctuation mark
int isPunctuation(char c) {
    // Check for specific punctuation characters
    if (c == '.') return 1; 
    if (c == ',') return 1; 
    if (c == '!') return 1; 
    if (c == '?') return 1; 
    return 0; // Returns false if c is not a recognized punctuation
}

int main(int argc, char *argv[]) {
    // Read a line of input from the user
    char s[1000];
    scanf("%s", s);
    int n = strlen(s); // Get the length of the input string
    
    // Initialize a StringBuilder to construct the output string
    char sb[1000];
    sb[0] = s[0];
    
    // Loop through the input string starting from the second character
    for (int i = 1; i < n; i++) {
        char c = s[i]; // Get the current character
        
        // Check if the current character is a Latin letter
        if (isLatinLetter(c)) {
            // If the previous character is not a Latin letter, append a space
            if (!isLatinLetter(s[i - 1])) {
                sb[i] =''; 
            }
            // Append the current Latin letter to the StringBuilder
            sb[i] = c; 
        } 
        // Check if the current character is a punctuation mark
        else if (isPunctuation(c)) {
            sb[i] = c; // Append the punctuation mark to the StringBuilder
        }
    }
    
    // Print the constructed output string
    printf("%s\n", sb); 
    return 0;
}

