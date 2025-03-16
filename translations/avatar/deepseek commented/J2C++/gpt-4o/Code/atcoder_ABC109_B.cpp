#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int N; // Step 1: Read the input value N
    cin >> N;

    unordered_map<int, string> map; // Step 2: Initialize a HashMap

    for (int i = 0; i < N; i++) { // Step 3: Read N strings and store them in the HashMap
        string input;
        cin >> input;
        map[i] = input;
    }

    bool ans = true; // Step 4: Initialize a boolean variable 'ans'
    unordered_map<int, string> past; // Step 5: Initialize another HashMap
    string next = ""; // Step 6: Initialize a variable 'next'

    for (int i = 0; i < N; i++) { // Step 7: Loop through the strings
        if (past.count(i) > 0 && past[i] == map[i]) { // Step 8: Check if the current string has been seen before
            ans = false;
            break;
        }
        past[i] = map[i]; // Step 9: Store the current string in the 'past' HashMap

        if (i != 0) { // Step 10: Check if it's not the first string
            if (next != map[i].substr(0, 1)) { // Check if the starting character matches
                ans = false;
                break;
            }
        }
        next = map[i].substr(map[i].length() - 1, 1); // Step 11: Update 'next'
    }

    if (ans) { // Step 12: Check the value of 'ans'
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// <END-OF-CODE>
