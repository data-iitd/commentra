#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    int mod = 1000000007;
    if (n == 1) {
        printf("%d\n", c[0] * 2 % mod);
        return 0;
    }
    qsort(c, n, sizeof(int), compare);

    long b = pow(2, n);
    long a = pow(2, n - 2);
    long ans = 0;

    for (int i = 2; i <= n + 1; i++) {
        long val = a * i % mod;
        val *= c[n + 1 - i];
        val %= mod;
        ans += val;
        ans %= mod;
    }
    ans *= b;
    ans %= mod;
    printf("%ld\n", ans);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

