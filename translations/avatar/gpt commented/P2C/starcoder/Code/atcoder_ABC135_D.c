#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

int main() {
    int n;
    scanf("%d", &n);
    char S[n + 1];
    scanf("%s", S);
    int dp[n][13];
    memset(dp, 0, sizeof(dp));
    dp[0][5] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 13; k++) {
                dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
            }
        }
        for (int k = 0; k < 13; k++) {
            dp[i][k] %= mod;
        }
    }
    printf("%d\n", dp[n - 1][5]);
    return 0;
}

