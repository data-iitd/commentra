#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Initialize an array of strings called divide
char divide[4][10] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    // Declare a string variable called S and read a string from the standard input
    char S[100];
    scanf("%s", S);

    // Reverse the string S and also reverse each string in the divide array
    int i, j;
    for (i = 0; i < strlen(S) / 2; ++i) {
        j = strlen(S) - i - 1;
        S[i] = S[i] ^ S[j];
        S[j] = S[i] ^ S[j];
        S[i] = S[i] ^ S[j];
    }
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < strlen(divide[i]) / 2; ++j) {
            j = strlen(divide[i]) - j - 1;
            divide[i][j] = divide[i][j] ^ divide[i][j];
            divide[i][j] = divide[i][j] ^ divide[i][j];
            divide[i][j] = divide[i][j] ^ divide[i][j];
        }
    }

    // Initialize a boolean variable called can to true
    bool can = true;

    // Iterate through each character in the string S
    for (i = 0; i < strlen(S);) {
        // Initialize a boolean variable called can2 to false
        bool can2 = false;

        // Iterate through each string in the divide array
        for (j = 0; j < 4; ++j) {
            // Get the string d from the divide array
            char d[10];
            strcpy(d, divide[j]);

            // Check if the substring of S starting from the current index i and having the same size as d is equal to d
            if (strncmp(S + i, d, strlen(d)) == 0) {
                // If the substring is equal to d, set can2 to true and move the index i to the end of the matched substring
                can2 = true;
                i += strlen(d);
            }
        }

        // If can2 is false, it means the current substring of S cannot be divided by any string in the divide array, so set can to false and break the loop
        if (!can2) {
            can = false;
            break;
        }
    }

    // Output "YES" if can is true, otherwise output "NO"
    if (can) printf("YES\n");
    else printf("NO\n");
}

