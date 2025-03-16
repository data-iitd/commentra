#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to read a single string
string scanString() {
    string s;
    cin >> s;
    return s;
}

// Function to read multiple integers
vector<int> scanInts(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

// Function to get the absolute value of an integer
int abs(int a) {
    return (a < 0) ? -a : a;
}

// Function to get the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Main function
int main() {
    // Reading input strings s and t
    string s = scanString();
    string t = scanString();

    // Initializing an empty vector to store answers
    vector<string> ans;

    // Iterating through all possible substrings of s that have the same length as t
    for (size_t i = 0; i <= s.length() - t.length(); i++) {
        // Initializing a copy of string s
        string ss = s;

        // Checking if the current substring matches the pattern t
        bool f = true;
        for (size_t j = 0; j < t.length(); j++) {
            // If the current character of s does not match the current character of t or is not '?'
            if (ss[i + j] != t[j] && ss[i + j] != '?') {
                // Setting flag to false and breaking the loop
                f = false;
                break;
            } else {
                // Replacing the current character of s with the corresponding character of t
                ss[i + j] = t[j];
            }
        }
        // If the current substring matches the pattern t
        if (f) {
            // Replacing all '?' in the modified string with 'a'
            replace(ss.begin(), ss.end(), '?', 'a');
            ans.push_back(ss);
        }
    }
    // Sorting the answer vector in ascending order
    sort(ans.begin(), ans.end());
    // Checking if the answer vector is empty
    if (ans.empty()) {
        // Printing "UNRESTORABLE" if the answer vector is empty
        cout << "UNRESTORABLE" << endl;
    } else {
        // Printing the first element of the answer vector
        cout << ans[0] << endl;
    }

    return 0;
}
// <END-OF-CODE>
