#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to check if a character is a Latin letter
bool isLatinLetter(char c) {
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is a punctuation mark
bool isPunctuation(char c) {
    if (c == '.') return true;
    if (c == ',') return true;
    if (c == '!') return true;
    if (c == '?') return true;
    return false;
}

int main() {
    // Create a string to read input from the console
    string s;
    // Read the input string
    getline(cin, s);
    // Create a string to build the output string
    string sb;
    // Get the length of the input string
    int n = s.length();
    // Append the first character of the input string to the string
    sb += s[0];
    // Loop through the input string starting from the second character
    for (int i = 1; i < n; i++) {
        char c = s[i];
        // Check if the character is a Latin letter
        if (isLatinLetter(c)) {
            // If the previous character is not a Latin letter, add a space
            if (!isLatinLetter(s[i - 1])) {
                sb += ' ';
            }
            // Append the current Latin letter to the string
            sb += c;
        }
        // Check if the character is a punctuation mark
        else if (isPunctuation(c)) {
            // Append the punctuation mark to the string
            sb += c;
        }
    }
    // Print the final string with spaces added between Latin letters
    cout << sb << endl;
    return 0;
}

