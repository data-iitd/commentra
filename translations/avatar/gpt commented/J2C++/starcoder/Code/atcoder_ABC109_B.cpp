#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the number of strings to be processed
    int N;
    cin >> N;
    
    // Initialize a HashMap to store the strings with their corresponding indices
    map<int, string> map;
    
    // Read N strings from the input and store them in the map
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        map[i] = s;
    }
    
    // Initialize a boolean variable to track if the conditions are met
    bool ans = true;
    
    // Initialize a HashMap to keep track of previously seen strings
    map<int, string> past;
    
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
        past[i] = map[i];
        
        // Check if this is not the first string
        if (i!= 0) {
            // Check if the first character of the current string matches the last character of the previous string
            if (next[0]!= map[i][0]) {
                ans = false; // Set answer to false if the characters do not match
                break;
            }
        }
        
        // Update 'next' to the last character of the current string
        next = map[i].substr(map[i].length() - 1, 1);
    }
    
    // Output the result based on the value of ans
    if (ans) {
        cout << "Yes" << endl; // Print "Yes" if all conditions are satisfied
    } else {
        cout << "No" << endl; // Print "No" if any condition fails
    }
}

