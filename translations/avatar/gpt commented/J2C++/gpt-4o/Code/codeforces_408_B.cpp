#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

bool isValid(const string& s1, const string& s2) {
    unordered_map<char, bool> map;
    
    // Add all characters from the first string to the map
    for (char c : s1) {
        map[c] = true;
    }
    
    // Check if all characters in the second string are present in the first string
    for (char c : s2) {
        if (map.find(c) == map.end()) return false;
    }
    return true; // All characters are valid
}

int main() {
    // Create a Scanner object to read input from the console
    string s1, s2;
    cin >> s1 >> s2;

    // Validate the input strings; if invalid, print -1 and exit
    if (!isValid(s1, s2)) {
        cout << -1 << endl;
    } else {
        // Create unordered_maps to count the frequency of characters in both strings
        unordered_map<char, int> m1, m2;

        // Count the frequency of each character in the first string
        for (char c : s1) {
            m1[c]++;
        }

        // Count the frequency of each character in the second string
        for (char c : s2) {
            m2[c]++;
        }

        // Initialize a variable to hold the result
        int ans = 0;
        // Create an unordered_set to track unique characters from the second string
        unordered_set<char> hs;

        // Calculate the minimum frequency of each character present in both strings
        for (char c : s2) {
            if (hs.find(c) == hs.end()) {
                hs.insert(c);
                int x1 = m1[c]; // Frequency in the first string
                int x2 = m2[c]; // Frequency in the second string
                ans += min(x1, x2); // Take the minimum frequency and add to the result
            }
        }
        // Print the final result
        cout << ans << endl;
    }
    return 0;
}

// <END-OF-CODE>
