#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);

    long long mdans[p];
    for (int i = 0; i < p; i++) {
        scanf("%lld", &mdans[i]);
    }

    long long dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int is_present = 0;
        for (int j = 0; j < p; j++) {
            if (mdans[j] == i) {
                is_present = 1;
                break;
            }
        }
        if (is_present) {
            dp[i] = 0;
        } else {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
    }

    printf("%lld\n", dp[n]);
    return 0;
}

