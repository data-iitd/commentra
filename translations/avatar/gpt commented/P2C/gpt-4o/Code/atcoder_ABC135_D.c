#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 10000000

// Function to read a line of input
char* input() {
    static char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
    return buffer;
}

int main() {
    // Read the string input S
    char* S = input();
    int n = strlen(S);

    // Handle the case where the input string length is 1
    if (n == 1) {
        if (S[0] == '5' || S[0] == '?') {
            printf("1\n");  // Output 1 if the single character is '5' or '?'
        } else {
            printf("0\n");  // Output 0 for any other single character
        }
        return 0;
    }

    // Initialize a 2D array for dynamic programming
    long long dp[n][13];
    memset(dp, 0, sizeof(dp)); // Initialize dp array to 0

    // Fill the dp table based on the characters in S
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            // Handle the first character
            if (S[i] != '?') {
                dp[i][S[i] - '0'] += 1; // Increment the count for the specific digit
            } else {
                // If the character is '?', increment counts for all digits (0-9)
                for (int j = 0; j < 10; j++) {
                    dp[i][j] += 1;
                }
            }
        } else {
            // Process subsequent characters
            if (S[i] != '?') {
                // If the character is a specific digit
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + (S[i] - '0')) % 13] += dp[i - 1][k];
                    dp[i][(k * 10 + (S[i] - '0')) % 13] %= MOD; // Apply modulo
                }
            } else {
                // If the character is '?', consider all digits (0-9)
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                        dp[i][(k * 10 + j) % 13] %= MOD; // Apply modulo
                    }
                }
            }
        }
    }

    // Output the count of valid numbers that are divisible by 13 and end with digit 5
    printf("%lld\n", dp[n - 1][5]);

    return 0;
}

// <END-OF-CODE>
