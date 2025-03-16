#include <stdio.h>
#include <stdlib.h>

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

    long long fact[M];
    fact[0] = 1;
    for (int n = 1; n < Nsq; n++) {
        fact[n] = (fact[n - 1] * n) % MOD;
    }

    long long inv[N];
    for (int i = 0; i < N; i++) {
        inv[i] = pow_mod(i + 1, MOD - 2, MOD);
    }

    long long temp[N];
    for (int j = 0; j < N; j++) {
        temp[j] = (inv[j] + inv[N - 1 - j] - 1) % MOD;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + A[i] * temp[i]) % MOD;
    }

    ans = (ans * fact[N]) % MOD;

    printf("%lld\n", ans);

    return 0;
}
