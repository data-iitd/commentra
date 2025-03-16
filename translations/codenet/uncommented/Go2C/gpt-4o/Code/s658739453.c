#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);

    int64_t *mdans = (int64_t *)calloc(n + 1, sizeof(int64_t));
    for (int index = 0; index < p; index++) {
        int64_t n1;
        scanf("%lld", &n1);
        if (n1 <= n) {
            mdans[n1] = n1;
        }
    }

    int64_t *dp = (int64_t *)calloc(n + 1, sizeof(int64_t));
    dp[0] = 1;
    dp[1] = 1;

    if (mdans[1]) {
        dp[1] = 0;
    }

    for (int i = 2; i <= n; i++) {
        if (mdans[i]) {
            continue;
        }
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    printf("%lld\n", dp[n]);

    free(mdans);
    free(dp);
    return 0;
}

// <END-OF-CODE>
