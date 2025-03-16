#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define Nsq 1000

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

int main() {
    int N;
    scanf("%d", &N);
    int M = 1000000;
    long long A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    long long fact[M * M];
    fact[0] = 1;
    for (int n = 1; n < Nsq; n++) {
        for (int m = 0; m < Nsq; m++) {
            fact[n * Nsq + m] = (fact[(n - 1) * Nsq + m] * n) % MOD;
        }
    }

    long long inv[N];
    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        inv[i] = pow_mod(i + 1, MOD - 2, MOD);
    }

    long long inv_cumsum[N];
    inv_cumsum[0] = inv[0];
    for (int i = 1; i < N; i++) {
        inv_cumsum[i] = (inv_cumsum[i - 1] + inv[i]) % MOD;
    }

    long long temp[N];
    for (int i = 0; i < N; i++) {
        temp[i] = (inv_cumsum[i] + inv_cumsum[N - 1 - i] - 1) % MOD;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + A[i] * temp[i]) % MOD;
    }

    long long fact_value = 1;
    for (int i = 1; i <= N; i++) {
        fact_value = (fact_value * i) % MOD;
    }

    ans = (ans * fact_value) % MOD;
    printf("%lld\n", ans);

    return 0;
}
