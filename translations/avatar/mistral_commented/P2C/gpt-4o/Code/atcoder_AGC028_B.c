#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define Nsq 1000
#define M 1000000

// Function to calculate power with modulo
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
    // Read input number of elements N
    int N;
    scanf("%d", &N);

    // Initialize array A
    long long *A = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Initialize 2D array fact
    long long fact[Nsq][Nsq];
    fact[0][0] = 1;

    // Calculate factorial for each cell in the 2D array fact
    for (int n = 1; n < Nsq; n++) {
        for (int i = 0; i < Nsq; i++) {
            fact[i][n] = (fact[i][n - 1] * (i + 1)) % MOD; // Multiply current row with previous row
        }
    }

    // Calculate factorial for each cell in the new rows
    for (int n = 1; n < Nsq; n++) {
        for (int i = 0; i < Nsq; i++) {
            fact[n][i] = (fact[n][i] * fact[n - 1][Nsq - 1]) % MOD; // Multiply current row with last cell of previous row
        }
    }

    // Flatten the 2D array fact into a 1D array
    long long *fact_flat = (long long *)malloc(Nsq * Nsq * sizeof(long long));
    for (int i = 0; i < Nsq; i++) {
        for (int j = 0; j < Nsq; j++) {
            fact_flat[i * Nsq + j] = fact[i][j];
        }
    }

    // Initialize array j
    long long *j = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        j[i] = i;
    }

    // Calculate the inverse of each element in the array inv
    long long *inv = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        inv[i] = pow_mod(i + 1, MOD - 2, MOD);
    }

    // Calculate cumulative sum of the array inv
    for (int i = 1; i < N; i++) {
        inv[i] = (inv[i] + inv[i - 1]) % MOD;
    }

    // Calculate temporary array temp using elements from j and inv
    long long *temp = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        temp[i] = (inv[j[i]] + inv[N - 1 - j[i]] - 1 + MOD) % MOD; // Ensure non-negative
    }

    // Calculate the answer ans using given formula
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + (A[i] * temp[i]) % MOD) % MOD;
    }

    // Multiply the answer ans with the last element of fact array
    ans = (ans * fact_flat[N]) % MOD;

    // Print the answer ans
    printf("%lld\n", ans);

    // Free allocated memory
    free(A);
    free(fact_flat);
    free(j);
    free(inv);
    free(temp);

    return 0;
}

// <END-OF-CODE>
