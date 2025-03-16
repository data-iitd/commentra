
#include <iostream> // Include the necessary header file
#include <string> // Include the necessary header file

using namespace std; // Use the standard namespace

int main() {
    string S, T; // Declare string variables S and T
    getline(cin, S); // Read input string S
    getline(cin, T); // Read input string T

    string A[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}; // Array of all lowercase letters

    bool res = true; // Initialize result as true

    // Loop through each letter in the alphabet
    for (string s : A) {
        int sIdx = S.find(s); // Find the index of the current letter in S
        if (sIdx == string::npos) continue; // If the letter is not in S, continue to the next letter

        string t = string(1, T[sIdx]); // Find the corresponding letter in T

        int idx = 0; // Initialize index for comparison
        while (idx < S.length()) {
            if (S.find(s, idx)!= string::npos) { // If the letter appears in S from the current index
                if (S.find(s, idx)!= T.find(t, idx)) { // Check if the positions match
                    res = false; // If positions do not match, set res to false
                    break; // Break out of the loop
                } else {
                    idx = S.find(s, idx) + 1; // Update index to check the next position
                }
            } else if (T.find(t, idx)!= string::npos) { // If the letter appears in T from the current index
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

