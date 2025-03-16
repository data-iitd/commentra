#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int main() {
    char l[100001]; // Assuming the input length won't exceed 100000
    scanf("%s", l);
    int n = strlen(l);
    
    long long dp[n + 1][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        char c = l[i];
        if (c == '0') {
            dp[i + 1][0] += dp[i][0];
            dp[i + 1][1] += dp[i][1] * 3;
        } else {
            dp[i + 1][0] += dp[i][0] * 2;
            dp[i + 1][1] += dp[i][0];
            dp[i + 1][1] += dp[i][1] * 3;
        }
        dp[i + 1][0] %= MOD;
        dp[i + 1][1] %= MOD;
    }

    printf("%lld\n", (dp[n][0] + dp[n][1]) % MOD);
    return 0;
}

// <END-OF-CODE>
