#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MOD 1000000007
#define M 1000000
#define Nsq 1000

uint64_t mod_pow(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int N;
    scanf("%d", &N);

    uint64_t A[N];
    char buffer[100000];
    fgets(buffer, sizeof(buffer), stdin); // Read the newline character
    fgets(buffer, sizeof(buffer), stdin);
    char *token = strtok(buffer, " ");
    for (int i = 0; i < N; i++) {
        A[i] = strtoul(token, NULL, 10);
        token = strtok(NULL, " ");
    }

    uint64_t fact[M];
    fact[0] = 1;
    for (int n = 1; n < M; n++) {
        fact[n] = (fact[n - 1] * n) % MOD;
    }

    uint64_t inv[N];
    for (int i = 0; i < N; i++) {
        inv[i] = mod_pow(i + 1, MOD - 2, MOD);
    }

    uint64_t inv_cumsum[N];
    inv_cumsum[0] = inv[0];
    for (int i = 1; i < N; i++) {
        inv_cumsum[i] = (inv_cumsum[i - 1] + inv[i]) % MOD;
    }

    uint64_t temp[N];
    for (int i = 0; i < N; i++) {
        temp[i] = (inv_cumsum[i] + inv_cumsum[N - 1 - i] - 1) % MOD;
    }

    uint64_t ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + (A[i] * temp[i]) % MOD) % MOD;
    }

    ans = (ans * fact[N]) % MOD;

    printf("%llu\n", ans);
    return 0;
}
