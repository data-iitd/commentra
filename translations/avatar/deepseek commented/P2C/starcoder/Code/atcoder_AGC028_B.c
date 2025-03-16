
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define N 1000000
#define Nsq 1000

int main() {
    int i, j, n, m;
    long long int ans, temp, fact[Nsq * Nsq], inv[N];
    scanf("%d", &n);
    long long int A[n];
    for (i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    fact[0] = 1;
    for (i = 1; i < Nsq; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    for (i = 1; i < Nsq; i++) {
        fact[i] = fact[i] * fact[i - 1] % MOD;
    }
    for (i = 0; i < N; i++) {
        inv[i] = pow(i + 1, MOD - 2, MOD);
    }
    for (i = 0; i < N; i++) {
        inv[i] = (inv[i] + inv[N - 1 - i]) % MOD;
    }
    for (i = 0; i < N; i++) {
        temp = inv[i] + inv[N - 1 - i] - 1;
        temp %= MOD;
        ans = (A[i] * temp % MOD);
        ans %= MOD;
        ans *= fact[N];
        ans %= MOD;
        printf("%lld\n", ans);
    }
    return 0;
}

