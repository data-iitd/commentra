
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define d 1000000007

int main() {
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);

    int64_t *mdans = (int64_t *)malloc(sizeof(int64_t) * p);
    for (int i = 0; i < p; i++) {
        scanf("%lld", &mdans[i]);
    }

    int64_t *dp = (int64_t *)malloc(sizeof(int64_t) * (n + 1));
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < p; j++) {
            if (mdans[j] == i) {
                found = true;
                break;
            }
        }
        if (found) {
            dp[i] = 0;
        } else {
            dp[i] = (dp[i - 1] + dp[i - 2]) % d;
        }
    }

    printf("%lld\n", dp[n]);

    free(mdans);
    free(dp);

    return 0;
}

