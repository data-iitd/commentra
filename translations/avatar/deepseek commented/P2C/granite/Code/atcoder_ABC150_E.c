

#include <stdio.h>
#include <stdlib.h>

#define MOD 100000007

int main() {
    int n;
    scanf("%d", &n);

    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    qsort(c, n, sizeof(int), cmpfunc);

    long long b = 1;
    for (int i = 0; i < 2 * n - 2; i++) {
        b = (b * 2) % MOD;
    }

    long long a = (b * 2) % MOD;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + c[i] * ((a + i * b) % MOD)) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

Translate the above C code to Java and end with comment "