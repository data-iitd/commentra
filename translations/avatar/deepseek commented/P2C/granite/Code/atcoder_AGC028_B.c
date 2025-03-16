

#include <stdio.h>
#include <stdlib.h>

#define MOD 100000007  // Define the modulo constant
#define N 1000  // Define the size of the array
#define M 1000000  // Define the size of the factorial table

typedef long long ll;

int main() {
    ll A[N];  // Declare the array A
    ll fact[M];  // Declare the factorial table
    ll inv[N];  // Declare the inverse factorial table
    ll temp[N];  // Declare the temporary array

    // Read the array elements
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Initialize the factorial table
    fact[0] = 1;
    for (int i = 1; i < M; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    // Compute the inverse factorial values
    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        inv[i] = inv[i - 1] * (i + 1) % MOD;
    }

    // Compute the temporary value
    for (int i = 0; i < N; i++) {
        temp[i] = inv[i] + inv[N - 1 - i] - 1;
    }

    // Compute the final answer
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i] * temp[i] % MOD;
        ans %= MOD;
    }

    // Multiply the final answer with the factorial of N
    ans = ans * fact[N] % MOD;

    // Print the final answer
    printf("%lld\n", ans);

    return 0;
}
