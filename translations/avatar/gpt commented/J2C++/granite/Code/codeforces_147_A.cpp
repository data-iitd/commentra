
#include <iostream>
#include <string>

using namespace std;

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
    string s; // Declare a string variable to store the input string
    getline(cin, s); // Read a line of input from the user and store it in the string variable
    
    string result = ""; // Initialize an empty string to store the output
    
    int n = s.length(); // Get the length of the input string
    
    result += s[0]; // Append the first character of the input string to the output string
    
    for (int i = 1; i < n; i++) {
        char c = s[i]; // Get the current character
        
        if (isLatinLetter(c)) { // Check if the current character is a Latin letter
            if (!isLatinLetter(s[i - 1])) { // If the previous character is not a Latin letter, append a space
                result +=''; 
            }
            result += c; // Append the current Latin letter to the output string
        } 
        else if (isPunctuation(c)) {
            result += c; // Append the punctuation mark to the output string
        }
    }
    
    cout << result << endl; // Print the constructed output string
    
    return 0;
}

