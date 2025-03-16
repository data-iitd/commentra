#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *coef = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        coef[i] = (n / (i + 1)) - (n / (i + 2));
    }
    for (int i = n - 1; i >= 0; i--) {
        coef[i] += coef[i + 1];
    }
    int *dp = (int *) malloc(sizeof(int) * (k + 1) * n);
    for (int i = 0; i < k + 1; i++) {
        dp[i * n] = 1;
    }
    for (int i = 1; i < k + 1; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            for (int l = 0; l < n; l++) {
                tmp += dp[(i - 1) * n + l];
                tmp %= 1000000007;
            }
            dp[i * n + j] = coef[j] * tmp;
            dp[i * n + j] %= 1000000007;
        }
    }
    printf("%d\n", dp[k * n]);
    return 0;
}

