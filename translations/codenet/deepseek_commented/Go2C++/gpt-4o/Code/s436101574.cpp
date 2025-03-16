#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to read a string from input.
string scanString() {
    string s;
    cin >> s;
    return s;
}

// Main function where the program execution begins.
int main() {
    string s = scanString(); // Reads the first string.
    string t = scanString(); // Reads the second string.

    vector<string> ans; // Vector to store possible valid strings.
    for (size_t i = 0; i <= s.length() - t.length(); i++) {
        bool f = true; // Flag to check if the current position is valid.
        string ss = s; // Temporary string to hold the modified string.

        for (size_t j = 0; j < t.length(); j++) {
            if (s[i + j] != t[j] && s[i + j] != '?') { // Checks if there's a mismatch.
                f = false;
                break;
            } else {
                ss[i + j] = t[j]; // Replaces the character in the temporary string.
            }
        }
        if (f) {
            replace(ss.begin(), ss.end(), '?', 'a'); // Replaces '?' with 'a'.
            ans.push_back(ss); // Adds the valid string to the answer vector.
        }
    }
    
    sort(ans.begin(), ans.end()); // Sorts the answer vector.
    if (ans.empty()) {
        cout << "UNRESTORABLE" << endl; // Prints "UNRESTORABLE" if no valid string is found.
    } else {
        cout << ans[0] << endl; // Prints the smallest valid string.
    }

    return 0;
}
