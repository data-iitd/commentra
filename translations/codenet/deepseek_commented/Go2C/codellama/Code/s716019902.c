#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 998244353
#define FAC_NUM 300001

int pow(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        n = n >> 1;
    }
    return ans;
}

int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    }
    while (b != 0) {
        a = a % b;
        b = b;
        b = a;
    }
    return a;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int combination(int n, int k, int *fac, int *ifac) {
    if (n < k || n < 0) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    //while n != 0
    int ans = ifac[k] * ifac[n-k] % MOD;
    return ans * fac[n] % MOD;
}

int *factorial() {
    int *fac = (int *)malloc(sizeof(int) * FAC_NUM);
    int *ifac = (int *)malloc(sizeof(int) * FAC_NUM);
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < FAC_NUM; i++) {
        fac[i] = fac[i-1] * i % MOD;
        ifac[i] = ifac[i-1] * pow(i, MOD-2) % MOD;
    }
    return fac;
}

int lowerBound(int *vs, int v) {
    int n = FAC_NUM / 2;
    int m = FAC_NUM;
    while (m != n) {
        if (vs[n] < v) {
            n = (m-n+1)/2 + n;
            //m = m
        } else {
            m = n;
            n = n / 2;
        }
    }
    return n;
}

int *IntSlice(int n, int init) {
    int *r = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        r[i] = init;
    }
    return r;
}

int main() {
    int *fac = factorial();
    int *ifac = IntSlice(FAC_NUM, 1);
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
    return 0;
}

