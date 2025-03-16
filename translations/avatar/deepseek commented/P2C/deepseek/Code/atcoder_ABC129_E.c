#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int main() {
    char l[100001];
    scanf("%s", l);
    int n = strlen(l);

    long long dp[n + 1][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;  // Base case: one empty sequence

    for (int i = 0; i < n; i++) {
        if (l[i] == '0') {
            dp[i + 1][0] += dp[i][0];  // Add sequences ending with zero
            dp[i + 1][1] += dp[i][1] * 3;  // Triple sequences ending with one
        } else {
            dp[i + 1][0] += dp[i][0] * 2;  // Double sequences ending with zero
            dp[i + 1][1] += dp[i][0];  // Add sequences ending with zero
            dp[i + 1][1] += dp[i][1] * 3;  // Triple sequences ending with one
        }

        // Take modulo to prevent overflow
        dp[i + 1][0] %= MOD;
        dp[i + 1][1] %= MOD;
    }

    // Calculate and print the final result
    long long result = (dp[n][0] + dp[n][1]) % MOD;
    printf("%lld\n", result);

    return 0;
}
