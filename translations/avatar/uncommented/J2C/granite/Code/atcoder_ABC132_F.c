
#include <stdio.h>
#include <stdlib.h>
#define mod 100000007

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int len[n];
    int l = 1;
    int q = 0;
    while (l <= n) {
        int r = n / (n / l);
        len[q++] = r - l + 1;
        l = r + 1;
    }
    long dp[k * (q + 1)];
    for (int j = 1; j <= q; j++) {
        dp[j] = len[j - 1] + dp[j - 1];
    }
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= q; j++) {
            dp[i * (q + 1) + j] = (dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * len[j - 1]) % mod;
        }
    }
    printf("%ld\n", dp[k * (q + 1) - 1]);
    return 0;
}
//END-OF-CODE