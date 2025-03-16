#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to perform modular exponentiation
int modpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
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

    long long ans = 0;
    qsort(c, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        ans = (ans + (long long)(n + 1 - i) * c[i] % MOD) % MOD;
    }

    printf("%lld\n", (ans * modpow(4, n - 1)) % MOD);

    free(c);
    return 0;
}

// <END-OF-CODE>
