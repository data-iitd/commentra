#include <stdio.h>
#include <string.h>

#define MOD 1000000007  // Set the modulus to a large prime number
#define MAX_LEN 100005  // Maximum length of the input string

int main() {
    char l[MAX_LEN];  // Input string
    scanf("%s", l);  // Read the input string
    int n = strlen(l);  // Calculate the length of the input string

    // Initialize the dynamic programming table
    long long dp[MAX_LEN][2] = {0};
    dp[0][0] = 1;  // Base case: one empty sequence

    // Iterate over each character in the input string
    for (int i = 0; i < n; i++) {
        char c = l[i];
        if (c == '0') {
            dp[i + 1][0] = (dp[i][0]) % MOD;  // Add sequences ending with zero
            dp[i + 1][1] = (dp[i][1] * 3) % MOD;  // Triple sequences ending with one
        } else {
            dp[i + 1][0] = (dp[i][0] * 2) % MOD;  // Double sequences ending with zero
            dp[i + 1][1] = (dp[i][0]) % MOD;  // Add sequences ending with zero
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][1] * 3) % MOD;  // Triple sequences ending with one
        }
    }

    // Calculate and print the final result
    long long result = (dp[n][0] + dp[n][1]) % MOD;
    printf("%lld\n", result);

    return 0;
}

// <END-OF-CODE>
