#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// Main function that executes the program logic.
int main() {
    // Read the input string.
    string s;
    cin >> s;

    // Initialize a set to keep track of characters in the string.
    unordered_set<char> charSet(s.begin(), s.end());

    // Iterate through the alphabet to find the first missing character.
    for (char c = 'a'; c <= 'z'; ++c) {
        if (charSet.find(c) == charSet.end()) {
            cout << c << endl;
            return 0;
        }
    }

    // If no missing character is found, print "None".
    cout << "None" << endl;

    return 0;
}

// <END-OF-CODE>
