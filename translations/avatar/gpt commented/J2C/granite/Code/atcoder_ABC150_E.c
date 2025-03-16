
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MOD 1000000007

long long power(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long val = power(x, n / 2);
    val = val * val % MOD;
    if (n % 2 == 1) {
        val = val * x % MOD;
    }
    return val;
}

int main() {
    int n;
    scanf("%d", &n);
    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    qsort(c, n, sizeof(int), cmpfunc);
    long long b = power(2, n);
    long long a = power(2, n - 2);
    long long ans = 0;
    for (int i = 2; i <= n + 1; i++) {
        long long val = a * i % MOD;
        val = val * c[n + 1 - i] % MOD;
        ans = (ans + val) % MOD;
    }
    ans = ans * b % MOD;
    printf("%lld\n", ans);
    return 0;
}

