#include <stdio.h>

#define MOD 1000000007

int main() {
    // Read input string
    char l[100001]; // Assuming the maximum length of the input string is 100000
    scanf("%s", l);
    
    // Calculate the length of the input string
    int n = 0;
    while (l[n] != '\0') {
        n++;
    }

    // Initialize 2D dynamic programming table
    long long dp[n + 1][2];
    dp[0][0] = 1; // Base case: empty string has 1 solution
    dp[0][1] = 0;

    // Iterate through each character in the input string
    for (int i = 0; i < n; i++) {
        char c = l[i];
        if (c == '0') {
            dp[i + 1][0] = dp[i][0] % MOD;
            dp[i + 1][1] = (dp[i][1] * 3) % MOD;
        } else {
            dp[i + 1][0] = (dp[i][0] * 2) % MOD;
            dp[i + 1][1] = (dp[i][0] + dp[i][1] * 3) % MOD;
        }
    }

    // Calculate the final answer
    long long result = (dp[n][0] + dp[n][1]) % MOD;
    printf("%lld\n", result);

    return 0;
}

// <END-OF-CODE>
