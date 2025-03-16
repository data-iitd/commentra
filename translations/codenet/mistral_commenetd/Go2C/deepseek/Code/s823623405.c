#include <stdio.h>
#include <stdlib.h>

#define mod 1000000007

int max(int a, int b) {
    return a > b ? a : b;
}

int* primeFactorize(int n) {
    int* res = (int*)calloc(n + 1, sizeof(int));
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }
    if (n != 1) {
        res[n]++;
    }
    return res;
}

int pow(int n, int k) {
    if (k == 0) {
        return 1;
    } else if (k % 2 == 1) {
        return pow(n, k - 1) * n % mod;
    } else {
        int t = pow(n, k / 2);
        return t * t % mod;
    }
}

int add(int a, int b) {
    return (a + b) % mod;
}

int sub(int a, int b) {
    return (a + mod - b) % mod;
}

int mul(int a, int b) {
    return a % mod * b % mod % mod;
}

int div(int a, int b) {
    return mul(a, pow(b, mod - 2));
}

int main() {
    int n;
    scanf("%d", &n);
    int as[n];
    int* ps[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
        int* ns = primeFactorize(as[i]);
        for (int j = 2; j <= as[i]; j++) {
            if (ns[j] > 0) {
                if (ps[j] == NULL) {
                    ps[j] = (int*)calloc(1, sizeof(int));
                    *ps[j] = 0;
                }
                ps[j] = (int*)realloc(ps[j], (*ps[j] + 1) * sizeof(int));
                ps[j][*ps[j]] = ns[j];
                *ps[j] = max(ps[j][*ps[j] - 1], ns[j]);
            }
        }
        free(ns);
    }

    int x = 1;
    for (int i = 2; i <= 1000; i++) {
        if (ps[i] != NULL) {
            for (int j = 1; j <= ps[i][*ps[i] - 1]; j++) {
                x = mul(x, i);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, div(x, as[i]));
    }

    printf("%d\n", ans);

    for (int i = 2; i <= 1000; i++) {
        if (ps[i] != NULL) {
            free(ps[i]);
        }
    }

    return 0;
}
