#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

// Function to perform modular exponentiation
ll modPow(ll b, ll e, ll mod) {
    ll ans = 1;
    ll x = b % mod;

    // Loop to calculate b^e % mod using exponentiation by squaring
    while (e != 0) {
        if (e & 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        e >>= 1;
    }

    // Return the final result of b^e % mod
    return ans;
}

// Function to compute modular inverse using Fermat's Little Theorem
ll modInv(ll x, ll mod) {
    return modPow(x, mod - 2, mod);
}

// Function to perform modular division
ll modDiv(ll a, ll b, ll mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

// Function to calculate GCD
ll gcd(ll a, ll b) {
    while (b != 0) {
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

int main() {
    // Read the number of elements N
    int N;
    scanf("%d", &N);

    // Initialize an array A to hold N integers
    int *A = (int *)malloc(N * sizeof(int));

    // Read N integers into the array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Initialize the LCM to 1
    ll lcmValue = 1;

    // Calculate the LCM of all elements in the array A
    for (int i = 0; i < N; i++) {
        lcmValue = lcm(lcmValue, A[i]);
    }

    // Define the modulus value
    ll mod = 1000000007;

    // Calculate the LCM modulo mod
    ll modLcm = lcmValue % mod;

    // Initialize the answer variable to accumulate results
    ll ans = 0;

    // Calculate the sum of modDiv for each element in A
    for (int i = 0; i < N; i++) {
        ans = (ans + modDiv(modLcm, A[i], mod)) % mod;
    }

    // Print the final result
    printf("%lld\n", ans);

    // Free the allocated memory
    free(A);

    return 0;
}

// <END-OF-CODE>
