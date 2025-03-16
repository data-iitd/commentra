#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Define the array of substrings to check against
string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    string S;
    // Read the input string from the user
    cin >> S;

    // Reverse the input string to facilitate checking from the end
    reverse(S.begin(), S.end());
    // Reverse each of the substrings in the divide array for matching
    for (int i = 0; i < 4; ++i) reverse(divide[i].begin(), divide[i].end());

    // Initialize a flag to determine if the string can be fully divided
    bool can = true;
    // Start checking the string from the beginning
    for (int i = 0; i < S.size();) {
        bool can2 = false; // Flag to check if we can divide with any of the substrings
        // Iterate through each substring in the divide array
        for (int j = 0; j < 4; ++j) {
            string d = divide[j];
            // Check if the current substring matches the beginning of the remaining string
            if (S.substr(i, d.size()) == d) { // If we can divide with d
                can2 = true; // Set the flag to true
                i += d.size(); // Move the index forward by the length of the matched substring
            }
        }
        // If no substring matched, set the can flag to false and break the loop
        if (!can2) { // If we couldn't divide the string
            can = false;
            break;
        }
    }

    // Output the result based on whether the string can be fully divided
    if (can) cout << "YES" << endl; // If it can be divided, print "YES"
    else cout << "NO" << endl; // Otherwise, print "NO"
}
