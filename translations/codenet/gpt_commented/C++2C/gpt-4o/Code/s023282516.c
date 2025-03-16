#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define the array of substrings to check against
char *divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    char S[100]; // Assuming the input string will not exceed 100 characters
    // Read the input string from the user
    scanf("%s", S);

    // Reverse the input string to facilitate checking from the end
    int len = strlen(S);
    for (int i = 0; i < len / 2; i++) {
        char temp = S[i];
        S[i] = S[len - i - 1];
        S[len - i - 1] = temp;
    }

    // Reverse each of the substrings in the divide array for matching
    for (int i = 0; i < 4; ++i) {
        int d_len = strlen(divide[i]);
        for (int j = 0; j < d_len / 2; j++) {
            char temp = divide[i][j];
            divide[i][j] = divide[i][d_len - j - 1];
            divide[i][d_len - j - 1] = temp;
        }
    }

    // Initialize a flag to determine if the string can be fully divided
    bool can = true;
    // Start checking the string from the beginning
    for (int i = 0; i < len;) {
        bool can2 = false; // Flag to check if we can divide with any of the substrings
        // Iterate through each substring in the divide array
        for (int j = 0; j < 4; ++j) {
            char *d = divide[j];
            int d_len = strlen(d);
            // Check if the current substring matches the beginning of the remaining string
            if (strncmp(S + i, d, d_len) == 0) { // If we can divide with d
                can2 = true; // Set the flag to true
                i += d_len; // Move the index forward by the length of the matched substring
<<<<<<< HEAD
                break; // Break to avoid checking other substrings after a match
=======
                break; // Break the loop since we found a match
>>>>>>> 98c87cb78a (data updated)
            }
        }
        // If no substring matched, set the can flag to false and break the loop
        if (!can2) { // If we couldn't divide the string
            can = false;
            break;
        }
    }

    // Output the result based on whether the string can be fully divided
    if (can) printf("YES\n"); // If it can be divided, print "YES"
    else printf("NO\n"); // Otherwise, print "NO"
}

// <END-OF-CODE>
