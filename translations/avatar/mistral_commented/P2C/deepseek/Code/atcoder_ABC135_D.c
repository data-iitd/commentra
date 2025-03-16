#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 100001

int dp[MAX_N][13];

int main() {
    char S[MAX_N];
    int n;

    // Read the string S
    scanf("%s", S);
    n = strlen(S);

    // Base case: if the length of the string is 1
    if (n == 1) {
        // Check if the string is '5' or '?' and print 1 if true, else print 0
        if (S[0] == '5' || S[0] == '?') {
            printf("1\n");
        } else {
            printf("0\n");
            return 0;
        }
    }

    // Initialize the dp array
    memset(dp, 0, sizeof(dp));

    // Iterate through each index i from 0 to n-1
    for (int i = 0; i < n; i++) {
        // If i is the first index, process it differently
        if (i == 0) {
            // If the character at index i is not '?', update the dp array accordingly
            if (S[i] != '?') {
                dp[i][S[i] - '0'] = 1;
            } else {
                for (int j = 0; j < 10; j++) {
                    dp[i][j] = 1;
                }
            }
        } else {
            // If the character at index i is not '?', update the dp array accordingly
            if (S[i] != '?') {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + S[i] - '0') % 13] = (dp[i][(k * 10 + S[i] - '0') % 13] + dp[i - 1][k]) % MOD;
                }
            } else {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] = (dp[i][(k * 10 + j) % 13] + dp[i - 1][k]) % MOD;
                    }
                }
            }
        }
    }

    // Print the final answer, which is dp[n-1][5]
    printf("%d\n", dp[n - 1][5]);

    return 0;
}
