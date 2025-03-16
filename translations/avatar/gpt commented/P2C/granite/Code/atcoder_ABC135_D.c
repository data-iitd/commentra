
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 100000007

int main() {
    char s[100005];
    scanf("%s", s);
    int n = strlen(s);
    int dp[n][13];
    memset(dp, 0, sizeof(dp));
    if (s[0]!= '?') {
        dp[0][s[0] - '0'] = 1;
    } else {
        for (int i = 0; i < 10; i++) {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (s[i]!= '?') {
            for (int j = 0; j < 13; j++) {
                dp[i][(j * 10 + s[i] - '0') % 13] += dp[i - 1][j];
                dp[i][(j * 10 + s[i] - '0') % 13] %= MOD;
            }
        } else {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                    dp[i][(k * 10 + j) % 13] %= MOD;
                }
            }
        }
    }
    printf("%d\n", dp[n - 1][5]);
    return 0;
}
