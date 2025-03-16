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
    // Read a line of input from the user
    string s;
    cin >> s;
    // Initialize a string to construct the output string
    string output = "";
    int n = s.length(); // Get the length of the input string
    
    // Append the first character of the input string to the output string
    output += s[0]; 
    
    // Loop through the input string starting from the second character
    for (int i = 1; i < n; i++) {
        char c = s[i]; // Get the current character
        
        // Check if the current character is a Latin letter
        if (isLatinLetter(c)) {
            // If the previous character is not a Latin letter, append a space
            if (!isLatinLetter(s[i - 1])) {
                output +=''; 
            }
            // Append the current Latin letter to the output string
            output += c; 
        } 
        // Check if the current character is a punctuation mark
        else if (isPunctuation(c)) {
            output += c; // Append the punctuation mark to the output string
        }
    }
    
    // Print the constructed output string
    cout << output << endl; 
    return 0;
}

