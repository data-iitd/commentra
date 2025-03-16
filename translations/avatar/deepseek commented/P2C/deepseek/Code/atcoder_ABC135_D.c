#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 100000

int dp[MAX_N][13];

int main() {
    char S[MAX_N + 1];
    int n;

    // Read input string
    scanf("%s", S);
    n = strlen(S);

    // Set recursion limit to prevent stack overflow
    // This is not necessary in C, as the stack size is usually much larger

    // Define modulo constant
    // This is already defined as MOD

    // Check if the string length is 1
    if (n == 1) {
        if (S[0] == '5' || S[0] == '?') {
            printf("1\n");
        } else {
            printf("0\n");
        }
        return 0;
    }

    // Initialize dp array
    memset(dp, 0, sizeof(dp));

    // Iterate over the length of the string
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            // Base case for the first character
            if (S[i] != '?') {
                dp[i][S[i] - '0']++;
            } else {
                for (int j = 0; j < 10; j++) {
                    dp[i][j]++;
                }
            }
        } else {
            // General case for subsequent characters
            if (S[i] != '?') {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + S[i] - '0') % 13] += dp[i - 1][k];
                }
            } else {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                    }
                }
            }
            for (int k = 0; k < 13; k++) {
                dp[i][k] %= MOD;
            }
        }
    }

    // Print the result
    printf("%d\n", dp[n - 1][5]);

    return 0;
}
