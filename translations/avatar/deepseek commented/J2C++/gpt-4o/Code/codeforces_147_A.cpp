#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Method to check if a character is a Latin letter
bool isLatinLetter(char c) {
    return c >= 'a' && c <= 'z';
}

// Method to check if a character is a punctuation mark
bool isPunctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?';
}

// Main method: Entry point of the program
int main() {
    // Read the input string
    string s;
    getline(cin, s);
    
    // Create a string to build the output string
    string result;
    
    // Get the length of the input string
    int n = s.length();
    
    // Append the first character of the input string to the result
    if (n > 0) {
        result += s[0];
    }
    
    // Loop through the input string starting from the second character
    for (int i = 1; i < n; i++) {
        char c = s[i];
        // Check if the character is a Latin letter
        if (isLatinLetter(c)) {
            // If the previous character is not a Latin letter, add a space
            if (!isLatinLetter(s[i - 1])) {
                result += ' ';
            }
            // Append the current Latin letter to the result
            result += c;
        }
        // Check if the character is a punctuation mark
        else if (isPunctuation(c)) {
            // Append the punctuation mark to the result
            result += c;
        }
    }
    
    // Print the final string with spaces added between Latin letters
    cout << result << endl;
    
    return 0;
}

// <END-OF-CODE>
