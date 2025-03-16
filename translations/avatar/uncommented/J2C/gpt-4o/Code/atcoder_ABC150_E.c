#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long power(long x, long n) {
    if (n == 0) {
        return 1;
    }
    long val = power(x, n / 2);
    val = (val * val) % MOD;
    if (n % 2 == 1) {
        val = (val * x) % MOD;
    }
    return val;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *c = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    if (n == 1) {
        printf("%ld\n", (c[0] * 2LL) % MOD);
        free(c);
        return 0;
    }

    qsort(c, n, sizeof(int), compare);

    long b = power(2, n);
    long a = power(2, n - 2);
    long ans = 0;

    for (int i = 2; i <= n + 1; i++) {
        long val = (a * i) % MOD;
        val = (val * c[n + 1 - i]) % MOD;
        ans = (ans + val) % MOD;
    }

    ans = (ans * b) % MOD;
    printf("%ld\n", ans);

    free(c);
    return 0;
}
