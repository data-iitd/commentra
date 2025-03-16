

#include <bits/stdc++.h>
// Include necessary libraries

using namespace std;
// Use the "using namespace std" statement to avoid writing "std::" before standard library functions and objects

int main() {
    string s;
    // Declare a string variable to store the input string

    cin >> s;
    // Read the input string from the user

    unordered_map<char, int> map;
    // Initialize an unordered_map to store character counts

    for (char c : s) {
        // Loop through each character in the input string
        if (map.find(c) == map.end()) {
            // If the character is not already in the map, add it with a count of 1
            map[c] = 1;
        } else {
            // If the character is already in the map, increment its count
            map[c]++;
        }
    }

    bool ok = true;
    // Initialize a boolean flag to check the conditions

    for (auto const& [key, value] : map) {
        // Loop through each entry in the map
        if (value!= 2) {
            // If any character count is not 2, set ok to false and break the loop
            ok = false;
            break;
        }
    }

    if (ok && map.size() == 2) {
        // Check if all characters appear exactly twice and there are exactly 2 unique characters
        cout << "Yes" << endl;
        // Print "Yes" if the conditions are met
    } else {
        cout << "No" << endl;
        // Print "No" otherwise
    }

    return 0;
}

