#include <iostream>
#include <string>

using namespace std;

int main() {
    // Reading two lines of input: S and T
    string S, T;
    getline(cin, S);
    getline(cin, T);
    
    // Defining an array of lowercase letters from 'a' to 'z'
    string A[] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
    
    // Initializing a boolean variable to track the result
    bool res = true;
    
    // Iterating through each letter in the array A
    for (string s : A) {
        // Finding the index of the current letter in string S
        int sIdx = S.find(s);
        
        // If the letter is not found in S, continue to the next letter
        if (sIdx < 0) continue;
        
        // Getting the corresponding character from T at the same index
        string t = T[sIdx];
        int idx = 0; // Initializing index for searching
        
        // Loop to check the correspondence of characters in S and T
        while (idx < S.length()) {
            // If the current letter s is found in S starting from idx
            if (S.find(s, idx) >= 0) {
                // Check if the index of s in S matches the index of t in T
                if (S.find(s, idx)!= T.find(t, idx)) {
                    // If they do not match, set res to false and break
                    res = false;
                    break;
                } else {
                    // If they match, move the index to the next position
                    idx = S.find(s, idx) + 1;
                }
            } 
            // If the character t is found in T but s is not found in S
            else if (T.find(t, idx) >= 0) {
                // Set res to false and break
                res = false;
                break;
            } else {
                // Break the loop if neither character is found
                break;
            }
        }
        // If a mismatch was found, break out of the outer loop
        if (!res) break;
    }
    
    // Output the result based on the value of res
    if (res) 
        cout << "Yes" << endl; // If res is true, print "Yes"
    else 
        cout << "No" << endl; // If res is false, print "No"
    
    return 0;
}

