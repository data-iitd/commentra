
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

int modpow(int a, int n) {
    int res = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    int *c = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    int ans = 0;
    qsort(c, n, sizeof(int), compare);
    for (int i = 0; i < n; i++) {
        ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
    }
    printf("%d\n", ans * modpow(4, n - 1) % mod);
    free(c);
    return 0;
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

