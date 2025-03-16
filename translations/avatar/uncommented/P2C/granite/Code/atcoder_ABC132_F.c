
#include <stdio.h>
#include <stdlib.h>
#define MOD 100000007

typedef long long ll;

int main() {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    ll coef[n];
    for (int i = 1; i <= (int)sqrt(n); i++) {
        coef[i - 1] = (n / i) - (n / (i + 1));
    }
    for (int i = (int)sqrt(n); i < n; i++) {
        coef[i] = 1;
    }
    ll dp[k + 1][n];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        ll tmp = 0;
        for (int j = n - 1; j >= 0; j--) {
            tmp += dp[i - 1][(n - 1) - j];
            tmp %= MOD;
            dp[i][j] = coef[j] * tmp;
            dp[i][j] %= MOD;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[k][i];
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
