#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

// Function to calculate GCD
ll gcd(ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

// Function to perform modular exponentiation
ll modPow(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to calculate modular inverse
ll modInv(ll x, ll mod) {
    return modPow(x, mod - 2, mod);
}

// Function to perform modular division
ll modDiv(ll a, ll b, ll mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

int main() {
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));

    // Read N integers into array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Initialize LCM to 1
    ll lcmValue = 1;

    // Calculate the LCM of all elements in array A
    for (int i = 0; i < N; i++) {
        lcmValue = lcm(lcmValue, A[i]);
    }

    // Define the modulo value
    ll mod = 1000000007;

    // Calculate the LCM modulo 10^9 + 7
    ll modLcm = lcmValue % mod;

    // Initialize the answer to 0
    ll ans = 0;

    // Calculate the sum of each element in A divided by the LCM, modulo 10^9 + 7
    for (int i = 0; i < N; i++) {
        ans = (ans + modDiv(modLcm, A[i], mod)) % mod;
    }

    // Print the final answer
    printf("%lld\n", ans);

    // Free allocated memory
    free(A);

    return 0;
}

// <END-OF-CODE>
