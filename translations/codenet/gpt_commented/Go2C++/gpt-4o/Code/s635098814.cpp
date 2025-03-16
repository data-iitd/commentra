#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Define constants for the program.
const int ALPHABET_NUM = 26;

// Declare memoization array and string variable.
int memo[ALPHABET_NUM] = {0};

int main() {
    string str;

    // Read input until EOF.
    while (getline(cin, str)) {
        // Count occurrences of each letter.
        for (char c : str) {
            if (islower(c)) {
                // Increment count for lowercase letters.
                memo[c - 'a']++;
            } else if (isupper(c)) {
                // Increment count for uppercase letters.
                memo[c - 'A']++;
            } else {
                // Ignore non-alphabet characters.
                continue;
            }
        }
    }

    // Print the count of each letter.
    for (int i = 0; i < ALPHABET_NUM; i++) {
        cout << static_cast<char>(i + 'a') << " : " << memo[i] << endl;
    }

    return 0;
}

// <END-OF-CODE>
