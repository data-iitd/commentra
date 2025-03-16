#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    long mod = MOD;
    int n, k;
    scanf("%d %d", &n, &k);

    int *len = (int *)malloc(n * sizeof(int));
    int l = 1, q = 0;

    while (l <= n) {
        int r = n / (n / l);
        len[q++] = r - l + 1;
        l = r + 1;
    }

    long *dp = (long *)malloc((k * (q + 1)) * sizeof(long));
    for (int j = 1; j <= q; j++) {
        dp[j] = len[j - 1] + dp[j - 1];
    }

    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= q; j++) {
            dp[i * (q + 1) + j] = dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * len[j - 1];
            dp[i * (q + 1) + j] %= mod;
        }
    }

    printf("%ld\n", dp[k * (q + 1) - 1]);

    free(len);
    free(dp);
    return 0;
}

// <END-OF-CODE>
