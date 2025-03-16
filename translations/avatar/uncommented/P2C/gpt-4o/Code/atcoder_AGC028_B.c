#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define M 1000000
#define Nsq 1000

long long mod_pow(long long base, long long exp, long long mod) {
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
    
    long long *A = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    long long *fact = (long long *)malloc(Nsq * Nsq * sizeof(long long));
    for (int i = 0; i < Nsq * Nsq; i++) {
        fact[i] = 0;
    }
    fact[0] = 1;

    for (int n = 1; n < Nsq; n++) {
        for (int i = 0; i < Nsq; i++) {
            fact[i * Nsq + n] = (fact[i * Nsq + n - 1] * fact[i * Nsq + n]) % MOD;
        }
    }

    for (int n = 1; n < Nsq; n++) {
        for (int i = 0; i < Nsq; i++) {
            fact[n * Nsq + i] = (fact[n * Nsq + i] * fact[(n - 1) * Nsq + Nsq - 1]) % MOD;
        }
    }

    long long *inv = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        inv[i] = mod_pow(i + 1, MOD - 2, MOD);
    }

    long long *cumsum = (long long *)malloc(N * sizeof(long long));
    cumsum[0] = inv[0];
    for (int i = 1; i < N; i++) {
        cumsum[i] = (cumsum[i - 1] + inv[i]) % MOD;
    }

    long long ans = 0;
    for (int j = 0; j < N; j++) {
        long long temp = (cumsum[j] + cumsum[N - 1 - j] - 1 + MOD) % MOD;
        ans = (ans + (A[j] * temp) % MOD) % MOD;
    }

    ans = (ans * fact[N]) % MOD;

    printf("%lld\n", ans);

    free(A);
    free(fact);
    free(inv);
    free(cumsum);

    return 0;
}

// <END-OF-CODE>
