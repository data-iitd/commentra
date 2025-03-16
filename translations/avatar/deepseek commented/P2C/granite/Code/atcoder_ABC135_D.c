
#include <stdio.h>
#include <string.h>
#define MOD 100000007
typedef long long ll;

int main() {
    char s[100005];
    scanf("%s", s);
    int n = strlen(s);
    ll dp[100005][13] = {0};
    if (n == 1) {
        if (s[0] == '5' || s[0] == '?') {
            printf("1\n");
        } else {
            printf("0\n");
        }
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i]!= '?') {
                dp[i][s[i] - '0'] = 1;
            } else {
                for (int j = 0; j < 10; j++) {
                    dp[i][j] = 1;
                }
            }
        } else {
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
    }
    printf("%lld\n", dp[n - 1][5]);
    return 0;
}
