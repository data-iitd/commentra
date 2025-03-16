#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 1000000

int main() {
    char S[MAX_N];
    scanf("%s", S);  // Read input string
    int n = strlen(S);  // Get length of the string

    if (n == 1) {  // Check if the string length is 1
        if (S[0] == '5' || S[0] == '?') {  // Check if the string is '5' or '?'
            printf("1\n");  // Print 1 if true
        } else {
            printf("0\n");  // Print 0 otherwise
        }
        return 0;  // Exit the program
    }

    long long dp[n][13];  // Initialize dp array
    memset(dp, 0, sizeof(dp));  // Set all values to 0

    for (int i = 0; i < n; i++) {  // Iterate over the length of the string
        if (i == 0) {  // Base case for the first character
            if (S[i] != '?') {  // Check if the character is not '?'
                dp[i][S[i] - '0'] += 1;  // Update dp value directly
            } else {
                for (int j = 0; j < 10; j++) {  // Iterate over all possible digits
                    dp[i][j] += 1;  // Increment dp value
                }
            }
        } else {  // General case for subsequent characters
            if (S[i] != '?') {  // Check if the character is not '?'
                for (int k = 0; k < 13; k++) {  // Iterate over all possible remainders
                    dp[i][(k * 10 + (S[i] - '0')) % 13] += dp[i - 1][k];  // Update dp value
                    dp[i][(k * 10 + (S[i] - '0')) % 13] %= MOD;  // Apply modulo to prevent overflow
                }
            } else {
                for (int j = 0; j < 10; j++) {  // Iterate over all possible digits
                    for (int k = 0; k < 13; k++) {  // Iterate over all possible remainders
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];  // Update dp value
                        dp[i][(k * 10 + j) % 13] %= MOD;  // Apply modulo to prevent overflow
                    }
                }
            }
        }
    }

    printf("%lld\n", dp[n - 1][5]);  // Print the result
    return 0;
}

// <END-OF-CODE>
