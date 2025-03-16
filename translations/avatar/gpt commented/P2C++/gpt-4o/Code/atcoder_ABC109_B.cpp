#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Read the number of strings to be processed
    int n;
    cin >> n;

    // Initialize an unordered_map to count occurrences of each string
    unordered_map<string, int> s;

    // Read n strings into a vector
    vector<string> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    // Initialize a flag to determine if the conditions are met
    string f = "Yes";

    // Initialize an index variable to track the previous string
    int i = -1;

    // Iterate through each string in the vector
    for (const auto& v : l) {
        // Increment the count for the current string
        s[v]++;

        // Check if the current string has appeared more than once
        if (s[v] >= 2) {
            f = "No";  // Set flag to 'No' if a duplicate is found
        }

        // Check if the previous string's last character does not match the current string's first character
        if (i != -1 && l[i].back() != v.front()) {
            f = "No";  // Set flag to 'No' if the character condition is violated
        }

        // Update the index to the current string's index
        i++;
    }

    // Print the final result based on the checks
    cout << f << endl;

    return 0;
}

// <END-OF-CODE>
