

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define d 1000000007

int main() {
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);

    int64_t mdans[p];
    for (int i = 0; i < p; i++) {
        scanf("%ld", &mdans[i]);
    }

    int64_t dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    if (mdans[0] == 1) {
        dp[1] = 0;
    }

    for (int i = 2; i <= n; i++) {
        if (mdans[i-1] == i) {
            continue;
        }
        dp[i] = (dp[i-1] + dp[i-2]) % d;
    }

    printf("%ld\n", dp[n]);

    return 0;
}

