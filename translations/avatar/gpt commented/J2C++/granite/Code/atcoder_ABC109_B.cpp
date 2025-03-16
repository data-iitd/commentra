
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    // Scanner sc(cin);

    // Read the number of strings to be processed
    int N;
    cin >> N;

    // Initialize a unordered_map to store the strings with their corresponding indices
    unordered_map<int, string> map;

    // Read N strings from the input and store them in the map
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        map[i] = s;
    }

    // Initialize a boolean variable to track if the conditions are met
    bool ans = true;

    // Initialize a unordered_map to keep track of previously seen strings
    unordered_map<int, string> past;

    // Variable to hold the last character of the previous string
    string next = "";

    // Iterate through the strings to check the conditions
    for (int i = 0; i < N; i++) {
        // Check if the current string has already been seen
        if (past.count(map[i]) > 0) {
            ans = false; // Set answer to false if a duplicate is found
            break;
        }

        // Store the current string in the past map
        past[map[i]] = map[i];

        // Check if this is not the first string
        if (i!= 0) {
            // Check if the first character of the current string matches the last character of the previous string
            if (next!= map[i].substr(0, 1)) {
                ans = false; // Set answer to false if the characters do not match
                break;
            }
        }

        // Update 'next' to the last character of the current string
        next = map[i].substr(map[i].length() - 1, map[i].length());
    }

    // Output the result based on the value of ans
    if (ans) {
        cout << "Yes" << endl; // Print "Yes" if all conditions are satisfied
    } else {
        cout << "No" << endl; // Print "No" if any condition fails
    }

    return 0;
}
