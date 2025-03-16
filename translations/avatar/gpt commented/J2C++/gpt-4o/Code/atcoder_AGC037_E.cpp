#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
    // Create variables to read input
    int N, K;
    std::cin >> N >> K;

    // Read the initial string
    std::string S;
    std::cin >> S;

    // Flag to check if we are processing the first iteration
    bool firstTime = true;
    // Variable to control the step size for substring extraction
    int step = 1;

    // Loop until K operations are performed
    while (K > 0) {
        // Create a reversed copy of the current string S
        std::string T = S;
        std::reverse(T.begin(), T.end());

        // Create a new string that combines S and its reverse, then reverse it
        std::string revU = S + T;
        std::reverse(revU.begin(), revU.end());

        // Initialize a variable to keep track of the best string found so far
        std::string sDash = S;

        // Iterate through the string revU to find the lexicographically smallest substring
        for (int i = N; i >= 0; i -= step) {
            // Extract a substring from revU
            std::string tmp = revU.substr(i, N);

            // Compare and update sDash if a smaller substring is found
            if (sDash > tmp) {
                sDash = tmp;
            } else {
                // If we are not in the first iteration, break the loop
                if (!firstTime) {
                    break;
                }
            }
        }

        // If this is the first iteration, check if we can print a uniform string
        if (firstTime) {
            firstTime = false;
            // If 2^K is greater than N, print the first character of sDash N times
            if (std::pow(2, K) > N) {
                char c = sDash[0];
                for (int i = 0; i < N; i++) {
                    std::cout << c;
                }
                std::cout << std::endl;
                return 0;
            }
        } else {
            // Increase the step size for the next iteration
            step += step;
        }

        // Decrement K and update S for the next operation
        K--;
        S = sDash;
        std::reverse(S.begin(), S.end());
    }

    // Print the final result after all operations
    std::cout << S << std::endl;

    return 0;
}

// <END-OF-CODE>
