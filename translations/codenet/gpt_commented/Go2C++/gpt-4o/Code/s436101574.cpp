#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to read a single string from input
string scanString() {
    string s;
    cin >> s;
    return s;
}

// Function to replace '?' with 'a' in a string
string replaceQuestionMarks(string s) {
    for (char &c : s) {
        if (c == '?') {
            c = 'a';
        }
    }
    return s;
}

// Main function where the program execution begins
int main() {
    // Read the first string (s)
    string s = scanString();
    // Read the second string (t)
    string t = scanString();

    // Initialize a vector to hold possible answers
    vector<string> ans;

    // Iterate through the first string to find occurrences of the second string
    for (size_t i = 0; i <= s.length() - t.length(); i++) {
        bool f = true; // Flag to check if the current position is valid
        string ss = s; // Create a copy of the original string

        // Check if the substring of s can match t
        for (size_t j = 0; j < t.length(); j++) {
            // If characters do not match and are not '?', set flag to false
            if (s[i + j] != t[j] && s[i + j] != '?') {
                f = false;
                break;
            } else {
                // Replace '?' with the corresponding character from t
                ss[i + j] = t[j];
            }
        }
        // If the substring matched, replace remaining '?' with 'a' and store the result
        if (f) {
            ans.push_back(replaceQuestionMarks(ss));
        }
    }

    // Sort the possible answers
    sort(ans.begin(), ans.end());

    // Output the result: either the first valid answer or "UNRESTORABLE"
    if (ans.empty()) {
        cout << "UNRESTORABLE" << endl;
    } else {
        cout << ans[0] << endl;
    }

    return 0;
}
// <END-OF-CODE>
