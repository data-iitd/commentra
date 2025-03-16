#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K; // Read the integers N and K
    string S;
    cin >> S; // Read the string S
    bool firstTime = true; // Initialize a flag to check if it's the first time through the loop
    int step = 1; // Initialize the step size

    // Main loop to manipulate the string based on the value of K
    while (K > 0) {
        string T = S; // Create a copy of S
        reverse(T.begin(), T.end()); // Reverse the copy
        string revU = S + T; // Concatenate S with its reverse
        reverse(revU.begin(), revU.end()); // Reverse the concatenated string
        string sDash = S; // Initialize sDash with the original string S

        // Iterate over the reversed concatenated string to find the best substring
        for (int i = N; i >= 0; i -= step) {
            string tmp = revU.substr(i, N); // Get a substring of length N
            if (sDash > tmp) { // Compare lexicographically
                sDash = tmp; // Update sDash if a better substring is found
            } else {
                if (!firstTime) { // If it's not the first time, break the loop
                    break;
                }
            }
        }

        // Check if it's the first time through the loop
        if (firstTime) {
            firstTime = false; // Set the flag to false
            if (pow(2, K) > N) { // Check the power of 2 of K
                char c = sDash[0]; // Get the first character of sDash
                for (int i = 0; i < N; i++) { // Print the character N times
                    cout << c;
                }
                cout << endl; // Print a newline
                return 0; // Exit the program
            }
        } else {
            step += step; // Double the step size
        }
        K--; // Decrement K
        S = sDash; // Update S with the best substring found
        reverse(S.begin(), S.end()); // Reverse S
    }
    reverse(S.begin(), S.end()); // Reverse S before printing
    cout << S << endl; // Print the final reversed string S
    return 0;
}

// <END-OF-CODE>
