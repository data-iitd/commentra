
#include <iostream>
#include <string>

using namespace std;

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
    // Create a string to store the input
    string s; 
    // Get the input from the user
    getline(cin, s); 
    // Initialize a string to construct the output
    string sb = ""; 
    int n = s.length(); // Get the length of the input string
    
    // Append the first character of the input string to the output string
    sb += s[0]; 
    
    // Loop through the input string starting from the second character
    for (int i = 1; i < n; i++) {
        char c = s[i]; // Get the current character
        
        // Check if the current character is a Latin letter
        if (isLatinLetter(c)) {
            // If the previous character is not a Latin letter, append a space
            if (!isLatinLetter(s[i - 1])) {
                sb += ' '; 
            }
            // Append the current Latin letter to the output string
            sb += c; 
        } 
        // Check if the current character is a punctuation mark
        else if (isPunctuation(c)) {
            sb += c; // Append the punctuation mark to the output string
        }
    }
    
    // Print the constructed output string
    cout << sb << endl; 
    return 0;
}

