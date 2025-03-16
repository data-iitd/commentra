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
    return c == '.' || c == ',' || c == '!' || c == '?'; // Returns true if c is a recognized punctuation
}

int main() {
    // Read a line of input from the user
    string s;
    getline(cin, s); // Use getline to read the entire line including spaces

    // Initialize a string to construct the output string
    string result;
    int n = s.length(); // Get the length of the input string

    // Append the first character of the input string to the result
    if (n > 0) {
        result += s[0];
    }

    // Loop through the input string starting from the second character
    for (int i = 1; i < n; i++) {
        char c = s[i]; // Get the current character

        // Check if the current character is a Latin letter
        if (isLatinLetter(c)) {
            // If the previous character is not a Latin letter, append a space
            if (!isLatinLetter(s[i - 1])) {
                result += ' ';
            }
            // Append the current Latin letter to the result
            result += c;
        } 
        // Check if the current character is a punctuation mark
        else if (isPunctuation(c)) {
            result += c; // Append the punctuation mark to the result
        }
    }

    // Print the constructed output string
    cout << result << endl; // Output the result
    return 0; // End of the program
}

// <END-OF-CODE>
