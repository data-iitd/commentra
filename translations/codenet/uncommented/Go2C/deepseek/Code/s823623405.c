#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

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
        return pow(n, k - 1) * n % MOD;
    } else {
        int t = pow(n, k / 2);
        return t * t % MOD;
    }
}

int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return (a + MOD - b) % MOD;
}

int mul(int a, int b) {
    return a % MOD * b % MOD % MOD;
}

int div(int a, int b) {
    return mul(a, pow(b, MOD - 2));
}

int main() {
    int n;
    scanf("%d", &n);
    int as[n];
    int* ps[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
        ps[i] = primeFactorize(as[i]);
    }

    int x[n];
    for (int i = 0; i < n; i++) {
        x[i] = 1;
        for (int j = 2; j <= as[i]; j++) {
            int count = 0;
            while (as[i] % j == 0) {
                as[i] /= j;
                count++;
            }
            int pCount = 0;
            for (int k = 0; k < n; k++) {
                if (ps[k][j] > pCount) {
                    pCount = ps[k][j];
                }
            }
            for (int k = 0; k < pCount; k++) {
                x[i] = mul(x[i], j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, div(x[0], as[i]));
    }
    printf("%d\n", ans);

    for (int i = 0; i < n; i++) {
        free(ps[i]);
    }
    return 0;
}
