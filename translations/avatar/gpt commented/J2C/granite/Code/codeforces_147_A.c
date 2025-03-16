
#include <stdio.h>
#include <stdbool.h>

// Function to check if a character is a lowercase Latin letter
bool isLatinLetter(char c) {
    return c >= 'a' && c <= 'z'; // Returns true if c is between 'a' and 'z'
}

// Function to check if a character is a punctuation mark
bool isPunctuation(char c) {
    // Check for specific punctuation characters
    if (c == '.') return true; 
    if (c == ',') return true; 
    if (c == '!') return true; 
    if (c == '?') return true; 
    return false; // Returns false if c is not a recognized punctuation
}

int main() {
    // Create a BufferedReader to read input from the console
    char s[1000]; // Define an array to store the input string
    fgets(s, 1000, stdin); // Read a line of input from the user
    
    // Initialize a StringBuilder to construct the output string
    char sb[1000]; // Define an array to store the output string
    int n = strlen(s); // Get the length of the input string
    
    // Append the first character of the input string to the StringBuilder
    sb[0] = s[0]; 
    int sb_index = 1; // Initialize the index of the StringBuilder
    
    // Loop through the input string starting from the second character
    for (int i = 1; i < n; i++) {
        char c = s[i]; // Get the current character
        
        // Check if the current character is a Latin letter
        if (isLatinLetter(c)) {
            // If the previous character is not a Latin letter, append a space
            if (!isLatinLetter(s[i - 1])) {
                sb[sb_index] =''; 
                sb_index++; // Increment the index of the StringBuilder
            }
            // Append the current Latin letter to the StringBuilder
            sb[sb_index] = c; 
            sb_index++; // Increment the index of the StringBuilder
        } 
        // Check if the current character is a punctuation mark
        else if (isPunctuation(c)) {
            sb[sb_index] = c; // Append the punctuation mark to the StringBuilder
            sb_index++; // Increment the index of the StringBuilder
        }
    }
    
    // Print the constructed output string
    printf("%s\n", sb); // Print the output string
    
    return 0; // Return 0 to indicate successful execution
}
