#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353
#define FAC_NUM 300001

int Pow(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return ans;
}

int Gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int combination(int n, int k, int* fac, int* ifac) {
    if (n < k || n < 0) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    int ans = ifac[k] * ifac[n - k] % MOD;
    return ans * fac[n] % MOD;
}

void factorial(int** fac, int** ifac) {
    *fac = (int*)malloc(FAC_NUM * sizeof(int));
    *ifac = (int*)malloc(FAC_NUM * sizeof(int));
    (*fac)[0] = 1;
    (*ifac)[0] = 1;
    for (int i = 1; i < FAC_NUM; i++) {
        (*fac)[i] = (*fac)[i - 1] * i % MOD;
        (*ifac)[i] = (*ifac)[i - 1] * Pow(i, MOD - 2) % MOD;
    }
}

int lowerBound(int* vs, int v, int len) {
    int n = len / 2;
    int m = len;
    while (m != n) {
        if (vs[n] < v) {
            n = (m - n + 1) / 2 + n;
        } else {
            m = n;
            n = n / 2;
        }
    }
    return n;
}

int* IntSlice(int n, int init) {
    int* r = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        r[i] = init;
    }
    return r;
}

int main() {
    int N;
    scanf("%d", &N);
    int sum = 0;

    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        sum += i;
    }

    printf("%d\n", sum);

    int* fac, *ifac;
    factorial(&fac, &ifac);

    int result = combination(N, 2, fac, ifac);
    printf("%d\n", result);

    free(fac);
    free(ifac);

    return 0;
}
