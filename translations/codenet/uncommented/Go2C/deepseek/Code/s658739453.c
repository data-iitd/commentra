#include <stdio.h>

#define MOD 1000000007

int main() {
    int n, p;
    scanf("%d %d", &n, &p);

    long long mdans[p];
    for (int i = 0; i < p; i++) {
        scanf("%lld", &mdans[i]);
    }

    long long dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 0; i < p; i++) {
        if (mdans[i] == 1) {
            dp[1] = 0;
        }
    }

    for (int i = 2; i <= n; i++) {
        int is_valid = 1;
        for (int j = 0; j < p; j++) {
            if (mdans[j] == i) {
                is_valid = 0;
                break;
            }
        }
        if (is_valid) {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
    }

    printf("%lld\n", dp[n]);
    return 0;
}
