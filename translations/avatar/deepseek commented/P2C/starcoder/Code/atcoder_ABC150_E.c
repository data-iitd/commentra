
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    int mod = 1000000007;
    int b = pow(2, 2 * n - 2, mod);
    int a = 2 * b % mod;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += c[i] * (a + i * b);
        ans %= mod;
    }
    printf("%d", ans);
    return 0;
}

