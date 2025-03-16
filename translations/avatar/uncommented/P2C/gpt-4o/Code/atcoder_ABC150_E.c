#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to perform modular exponentiation
long long pow_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *c = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    qsort(c, n, sizeof(int), compare); // Sort array c in descending order

    long long b = pow_mod(2, 2 * n - 2, MOD);
    long long a = (2 * b) % MOD;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans = (ans + c[i] * (a + i * b)) % MOD;
    }

    printf("%lld\n", ans);
    free(c);
    return 0;
}

// <END-OF-CODE>
