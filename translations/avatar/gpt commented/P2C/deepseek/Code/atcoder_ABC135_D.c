#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 100001

int dp[MAX_N][13];

int main() {
    char S[MAX_N];
    int n;

    // Set the recursion limit to a higher value to handle deep recursions
    // This is not necessary in C, but we can simulate it by setting a large stack size
    // For simplicity, we won't set a recursion limit in C

    // Read the string input S
    scanf("%s", S);
    n = strlen(S);

    // Handle the case where the input string length is 1
    if (n == 1) {
        if (S[0] == '5' || S[0] == '?') {
            printf("1\n");  // Output 1 if the single character is '5' or '?'
        } else {
            printf("0\n");  // Output 0 for any other single character
        }
        return 0;
    }

    // Initialize the dp table
    memset(dp, 0, sizeof(dp));

    // Fill the dp table based on the characters in S
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            // Handle the first character
            if (S[i] != '?') {
                dp[i][(S[i] - '0') % 13]++;  // Increment the count for the specific digit
            } else {
                // If the character is '?', increment counts for all digits (0-9)
                for (int j = 0; j < 10; j++) {
                    dp[i][j]++;
                }
            }
        } else {
            // Process subsequent characters
            if (S[i] != '?') {
                // If the character is a specific digit
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + (S[i] - '0')) % 13] = (dp[i][(k * 10 + (S[i] - '0')) % 13] + dp[i - 1][k]) % MOD;
                }
            } else {
                // If the character is '?', consider all digits (0-9)
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] = (dp[i][(k * 10 + j) % 13] + dp[i - 1][k]) % MOD;
                    }
                }
            }
        }
    }

    // Output the count of valid numbers that are divisible by 13 and end with digit 5
    printf("%d\n", dp[n - 1][5]);

    return 0;
}
