
#include <stdio.h>
#include <string.h>
#define MOD 100000007
typedef long long ll;

int main(void) {
    char s[100001];
    scanf("%s", s);
    int n = strlen(s);
    ll dp[n][13];
    memset(dp, 0, sizeof(dp));
    if (s[0] == '?') {
        for (int i = 0; i < 10; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][s[0] - '0'] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == '?') {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                    dp[i][(k * 10 + j) % 13] %= MOD;
                }
            }
        } else {
            int j = s[i] - '0';
            for (int k = 0; k < 13; k++) {
                dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                dp[i][(k * 10 + j) % 13] %= MOD;
            }
        }
    }
    printf("%lld\n", dp[n - 1][5]);
    return 0;
}
