
#include <stdio.h>
#include <string.h>

#define MOD 100000007

int main() {
    char l[100001];
    scanf("%s", l);
    int n = strlen(l);
    int dp[n + 1][2] = {{1, 0}};
    for (int i = 0; i < n; i++) {
        if (l[i] == '0') {
            dp[i + 1][0] = (dp[i][0] + dp[i][1] * 3) % MOD;
            dp[i + 1][1] = dp[i][1] * 3 % MOD;
        } else {
            dp[i + 1][0] = (dp[i][0] * 2 + dp[i][1]) % MOD;
            dp[i + 1][1] = (dp[i][0] + dp[i][1] * 3) % MOD;
        }
    }
    printf("%d\n", (dp[n][0] + dp[n][1]) % MOD);
    return 0;
}
