#include <stdio.h> // Standard I/O library
#include <stdlib.h> // Standard library for memory allocation
#include <math.h>  // Mathematical functions

typedef long long ll; // Define a type alias for long long
const ll MOD = 1e9 + 7; // Define a constant for modulo operation

// Function to calculate a^n
ll pow(ll a, ll n) {
    ll res = 1; // Initialize result
    while (n > 0) { // Loop until n becomes 0
        if (n & 1) res *= a; // If n is odd, multiply result by a
        a *= a; // Square a
        n >>= 1; // Divide n by 2
    }
    return res; // Return the result
}

// Function to calculate a^n % mod
ll mod_pow(ll a, ll n, ll mod) {
    ll res = 1; // Initialize result
    while (n > 0) { // Loop until n becomes 0
        if (n & 1) res = res * a % mod; // If n is odd, multiply result by a modulo mod
        a = a * a % mod; // Square a modulo mod
        n >>= 1; // Divide n by 2
    }
    return res; // Return the result
}

// Function to calculate a^(-1) % mod (only if a % mod != 0)
ll mod_inv(ll a, ll mod) {
    return mod_pow(a, mod - 2, mod); // Use Fermat's little theorem: a^(mod-2) % mod is a^-1 % mod
}

// Function to calculate nCk % mod
ll mod_nCk(int n, int k, int mod) {
    if (n == 0 || k == 0) return 1; // Base case: nCk is 1 if n or k is 0
    ll p = 1, q = 1; // Initialize p and q
    for (int i = n - k + 1; i <= n; i++) // Calculate numerator
        p = (p * i) % MOD;
    for (int i = 2; i <= k; i++) // Calculate denominator
        q = (q * i) % MOD;
    q = mod_inv(q, MOD); // Calculate inverse of denominator
    return (p * q) % MOD; // Return the result
}

int main() {
    int n, k; 
    scanf("%d %d", &n, &k); // Read values of n and k
    printf("%lld\n", mod_nCk(k, n, MOD)); // Calculate and print nCk % MOD
    return 0; // Return success
}

// <END-OF-CODE>
