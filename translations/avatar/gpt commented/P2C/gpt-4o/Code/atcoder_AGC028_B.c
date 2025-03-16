#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define M 1000000
#define Nsq 1000

long long fact[Nsq][Nsq];

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

    // Initialize the first factorial value
    fact[0][0] = 1;

    // Compute factorial values for columns
    for (int n = 1; n < Nsq; n++) {
        fact[0][n] = (fact[0][n - 1] * n) % MOD;
    }

    // Compute factorial values for rows
    for (int n = 1; n < Nsq; n++) {
        fact[n][0] = (fact[n - 1][0] * fact[0][Nsq - 1]) % MOD;
        for (int m = 1; m < Nsq; m++) {
            fact[n][m] = (fact[n][m - 1] * n) % MOD;
        }
    }

    // Flatten the factorial array to 1D
    long long *flat_fact = (long long *)malloc(Nsq * Nsq * sizeof(long long));
    for (int i = 0; i < Nsq; i++) {
        for (int j = 0; j < Nsq; j++) {
            flat_fact[i * Nsq + j] = fact[i][j];
        }
    }

    // Calculate modular inverses of numbers from 1 to N
    long long *inv = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        inv[i] = mod_pow(i + 1, MOD - 2, MOD);
    }

    // Compute cumulative sum of inverses and take modulo
    for (int i = 1; i < N; i++) {
        inv[i] = (inv[i] + inv[i - 1]) % MOD;
    }

    // Calculate temporary values based on the cumulative inverses
    long long *temp = (long long *)malloc(N * sizeof(long long));
    for (int j = 0; j < N; j++) {
        temp[j] = (inv[j] + inv[N - 1 - j] - 1 + MOD) % MOD;
    }

    // Compute the final answer by multiplying A with temp and summing the result
    long long ans = 0;
    for (int j = 0; j < N; j++) {
        ans = (ans + A[j] * temp[j]) % MOD;
    }

    // Multiply the answer by the factorial of N and take modulo
    ans = (ans * flat_fact[N][0]) % MOD;

    // Print the final answer
    printf("%lld\n", ans);

    // Free allocated memory
    free(A);
    free(flat_fact);
    free(inv);
    free(temp);

    return 0;
}

// <END-OF-CODE>
