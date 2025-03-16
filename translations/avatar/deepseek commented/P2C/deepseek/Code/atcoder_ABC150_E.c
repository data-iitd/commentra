#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    int n;
    scanf("%d", &n);

    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // Sort the array c in descending order
    qsort(c, n, sizeof(int), (int (*)(const void *, const void *))compare);

    long long b = 1;
    for (int i = 0; i < 2 * n - 2; i++) {
        b = (b * 2) % MOD;
    }

    long long a = (2 * b) % MOD;

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans = (ans + c[i] * (a + i * b)) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
