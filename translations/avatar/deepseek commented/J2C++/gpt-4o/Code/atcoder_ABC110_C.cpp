#include <iostream> // Include iostream for input and output
#include <string>   // Include string for string manipulation
#include <vector>   // Include vector for using dynamic arrays

using namespace std;

int main() {
    string S, T; // Declare strings S and T
    getline(cin, S); // Read input string S
    getline(cin, T); // Read input string T

    vector<string> A = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}; // Vector of all lowercase letters

    bool res = true; // Initialize result as true

    // Loop through each letter in the alphabet
    for (const string& s : A) {
        size_t sIdx = S.find(s); // Find the index of the current letter in S
        if (sIdx == string::npos) continue; // If the letter is not in S, continue to the next letter

        char t = T[sIdx]; // Find the corresponding letter in T

        size_t idx = 0; // Initialize index for comparison
        while (idx < S.length()) {
            if (S.find(s, idx) != string::npos) { // If the letter appears in S from the current index
                if (S.find(s, idx) != T.find(t, idx)) { // Check if the positions match
                    res = false; // If positions do not match, set res to false
                    break; // Break out of the loop
                } else {
                    idx = S.find(s, idx) + 1; // Update index to check the next position
                }
            } else if (T.find(t, idx) != string::npos) { // If the letter appears in T from the current index
                res = false; // If positions do not match, set res to false
                break; // Break out of the loop
            } else {
                break; // If neither letter appears, break out of the loop
            }
        }
        if (!res) break; // If res is false, break out of the outer loop
    }

    if (res) {
        cout << "Yes" << endl; // If res is true, print "Yes"
    } else {
        cout << "No" << endl; // If res is false, print "No"
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
