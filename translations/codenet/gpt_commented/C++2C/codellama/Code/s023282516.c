#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define the array of substrings to check against
char divide[4][10] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    char S[100];
    // Read the input string from the user
    scanf("%s", S);

    // Reverse the input string to facilitate checking from the end
    reverse(S);
    // Reverse each of the substrings in the divide array for matching
    for (int i = 0; i < 4; ++i) reverse(divide[i]);

    // Initialize a flag to determine if the string can be fully divided
    bool can = true;
    // Start checking the string from the beginning
    for (int i = 0; i < strlen(S);) {
        bool can2 = false; // Flag to check if we can divide with any of the substrings
        // Iterate through each substring in the divide array
        for (int j = 0; j < 4; ++j) {
            char d[10];
            strcpy(d, divide[j]);
            // Check if the current substring matches the beginning of the remaining string
            if (strncmp(S + i, d, strlen(d)) == 0) { // If we can divide with d
                can2 = true; // Set the flag to true
                i += strlen(d); // Move the index forward by the length of the matched substring
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

void reverse(char s[]) {
    int i, j;
    char c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

