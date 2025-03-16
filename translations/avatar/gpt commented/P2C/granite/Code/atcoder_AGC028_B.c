
#include <stdio.h>
#include <stdlib.h>

// Define the modulo constant
#define MOD 100000007

// Define a constant for the maximum size
#define M 1000000

// Function to calculate modular inverse
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    // Read the integer input N
    int N;
    scanf("%d", &N);

    // Define a constant for the maximum size
    #define Nsq 1000

    // Read the array A from input and convert it to a numpy array of int64 type
    long long A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Initialize a 2D array to store factorial values
    long long fact[Nsq][Nsq];
    for (int i = 0; i < Nsq; i++) {
        fact[i][0] = 1;
        for (int j = 1; j < Nsq; j++) {
            fact[i][j] = fact[i][j - 1] * (i + j) % MOD;
        }
    }

    // Compute factorial values for rows
    for (int i = 1; i < Nsq; i++) {
        fact[i][0] *= fact[i - 1][N - 1];
        fact[i][0] %= MOD;
        for (int j = 1; j < Nsq; j++) {
            fact[i][j] *= fact[i - 1][N - j - 1];
            fact[i][j] %= MOD;
        }
    }

    // Create an array of indices from 0 to N-1
    int j[N];
    for (int i = 0; i < N; i++) {
        j[i] = i;
    }

    // Calculate modular inverses of numbers from 1 to N
    long long inv[N];
    for (int i = 0; i < N; i++) {
        inv[i] = modinv(i + 1, MOD);
    }

    // Compute cumulative sum of inverses and take modulo
    for (int i = 1; i < N; i++) {
        inv[i] += inv[i - 1];
        inv[i] %= MOD;
    }

    // Calculate temporary values based on the cumulative inverses
    long long temp[N];
    for (int i = 0; i < N; i++) {
        temp[i] = inv[i] + inv[N - 1 - i] - 1;
    }

    // Compute the final answer by multiplying A with temp and summing the result
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i] * temp[i] % MOD;
        ans %= MOD;
    }

    // Multiply the answer by the factorial of N and take modulo
    ans *= fact[N][N];
    ans %= MOD;

    // Print the final answer
    printf("%lld\n", ans);

    return 0;
}
