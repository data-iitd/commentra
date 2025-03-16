
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char S[100001];
    // Read the input string from the user
    scanf("%s", S);

    // Reverse the input string to facilitate checking from the end
    int len = strlen(S);
    for (int i = 0; i < len / 2; ++i) {
        char temp = S[i];
        S[i] = S[len - 1 - i];
        S[len - 1 - i] = temp;
    }

    // Reverse each of the substrings in the divide array for matching
    char *divide[4] = {"dream", "dreamer", "erase", "eraser"};
    for (int i = 0; i < 4; ++i) {
        int dlen = strlen(divide[i]);
        for (int j = 0; j < dlen / 2; ++j) {
            char temp = divide[i][j];
            divide[i][j] = divide[i][dlen - 1 - j];
            divide[i][dlen - 1 - j] = temp;
        }
    }

    // Initialize a flag to determine if the string can be fully divided
    bool can = true;
    // Start checking the string from the beginning
    int i = 0;
    while (i < len) {
        bool can2 = false; // Flag to check if we can divide with any of the substrings
        // Iterate through each substring in the divide array
        for (int j = 0; j < 4; ++j) {
            char *d = divide[j];
            int dlen = strlen(d);
            // Check if the current substring matches the beginning of the remaining string
            if (strncmp(S + i, d, dlen) == 0) { // If we can divide with d
                can2 = true; // Set the flag to true
                i += dlen; // Move the index forward by the length of the matched substring
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

