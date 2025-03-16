#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define M 1000000
#define Nsq 1000

long long fact[Nsq][Nsq]; // Factorial table
long long inv[M]; // Inverse factorial values

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
    scanf("%d", &N); // Read the size of the array
    long long *A = (long long *)malloc(N * sizeof(long long)); // Allocate memory for the array
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]); // Read the array elements
    }

    // Initialize the factorial table
    fact[0][0] = 1;
    for (int n = 1; n < Nsq; n++) {
        fact[0][n] = (fact[0][n - 1] * n) % MOD; // Compute factorials
    }

    // Compute the factorial table row-wise
    for (int n = 1; n < Nsq; n++) {
        fact[n][0] = fact[n - 1][0]; // Copy the first column
        for (int m = 1; m < Nsq; m++) {
            fact[n][m] = (fact[n][m - 1] * n) % MOD; // Compute factorials
        }
    }

    // Compute the inverse factorial values
    for (int i = 0; i < N; i++) {
        inv[i] = mod_pow(i + 1, MOD - 2, MOD); // Compute inverse factorials
    }

    // Compute the temporary value
    long long *temp = (long long *)malloc(N * sizeof(long long));
    for (int j = 0; j < N; j++) {
        temp[j] = (inv[j] + inv[N - 1 - j] - 1 + MOD) % MOD; // Ensure non-negative
    }

    // Compute the final answer
    long long ans = 0;
    for (int j = 0; j < N; j++) {
        ans = (ans + (A[j] * temp[j]) % MOD) % MOD; // Sum the contributions
    }

    // Multiply the final answer with the factorial of N
    ans = (ans * fact[N][Nsq - 1]) % MOD; // Use the last element of the last row

    // Print the final answer
    printf("%lld\n", ans);

    // Free allocated memory
    free(A);
    free(temp);

    return 0;
}

// <END-OF-CODE>
