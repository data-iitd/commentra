// Importing necessary C++ libraries for reading input and writing output
#include <iostream>
#include <string>

using namespace std;

// Function to check if a character is a Latin letter
bool isLatinLetter(char c) {
    // Check if the character falls within the ASCII range of Latin letters
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is a punctuation mark
bool isPunctuation(char c) {
    // Check if the character is a dot, comma, exclamation mark, or question mark
    return c == '.' || c == ',' || c == '!' || c == '?';
}

int main() {
    // Reading a line of input from the console
    string s;
    getline(cin, s);

    // Creating a string to store the output
    string result;

    // Finding the length of the input string
    int n = s.length();

    // Appending the first character of the input string to the result
    result += s[0];

    // Iterating through the rest of the characters in the input string
    for (int i = 1; i < n; i++) {
        // Getting the current character from the input string
        char c = s[i];

        // If the current character is a Latin letter, append it to the result with a space before it if the previous character was not a Latin letter
        if (isLatinLetter(c)) {
            if (!isLatinLetter(s[i - 1])) {
                result += ' ';
            }
            result += c;
        }
        // If the current character is a punctuation mark, append it directly to the result without a space
        else if (isPunctuation(c)) {
            result += c;
        }
    }

    // Writing the output to the console
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
