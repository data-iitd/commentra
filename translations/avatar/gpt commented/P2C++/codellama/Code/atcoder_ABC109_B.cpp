#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Read the number of strings to be processed
    int n;
    cin >> n;

    // Initialize a map to count occurrences of each string
    map<string, int> s;

    // Read n strings into a list
    string l[n];
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    // Initialize a flag to determine if the conditions are met
    string f = "Yes";

    // Initialize an index variable to track the previous string
    int i = -1;

    // Iterate through each string in the list
    for (int j = 0; j < n; j++) {
        // Increment the count for the current string
        s[l[j]] += 1;

        // Check if the current string has appeared more than once
        if (s[l[j]] >= 2) {
            f = "No";  // Set flag to 'No' if a duplicate is found
        }

        // Check if the previous string's last character does not match the current string's first character
        if (i != -1 && l[i][l[i].length() - 1] != l[j][0]) {
            f = "No";  // Set flag to 'No' if the character condition is violated
        }

        // Update the index to the current string's index
        i = j;
    }

    // Print the final result based on the checks
    cout << f << endl;

    return 0;
}

