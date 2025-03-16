#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int max(int a, int b) {
    return (a > b) ? a : b;
}

int* primeFactorize(int n, int* size) {
    int* res = (int*)malloc(100 * sizeof(int)); // Assuming a maximum of 100 unique prime factors
    int* counts = (int*)malloc(100 * sizeof(int));
    *size = 0;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            int found = 0;
            for (int j = 0; j < *size; j++) {
                if (res[j] == i) {
                    counts[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                res[*size] = i;
                counts[*size] = 1;
                (*size)++;
            }
        }
    }
    if (n != 1) {
        res[*size] = n;
        counts[*size] = 1;
        (*size)++;
    }

    free(counts);
    return res;
}

int pow_mod(int n, int k) {
    if (k == 0) return 1;
    if (k % 2 == 1) return (1LL * pow_mod(n, k - 1) * n) % MOD;
    int t = pow_mod(n, k / 2);
    return (1LL * t * t) % MOD;
}

int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return (a + MOD - b) % MOD;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int div_mod(int a, int b) {
    return mul(a, pow_mod(b, MOD - 2));
}

int main() {
    int n;
    scanf("%d", &n);
    int* as = (int*)malloc(n * sizeof(int));
    int* ps = (int*)calloc(100, sizeof(int)); // Assuming a maximum of 100 unique prime factors

    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
        int size;
        int* factors = primeFactorize(as[i], &size);
        for (int j = 0; j < size; j++) {
            ps[factors[j]] = max(ps[factors[j]], 1); // Assuming all factors are counted as 1
        }
        free(factors);
    }

    int x = 1;
    for (int i = 0; i < 100; i++) {
        if (ps[i] > 0) {
            for (int j = 0; j < ps[i]; j++) {
                x = mul(x, i);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, div_mod(x, as[i]));
    }
    printf("%d\n", ans);

    free(as);
    free(ps);
    return 0;
}

// <END-OF-CODE>
