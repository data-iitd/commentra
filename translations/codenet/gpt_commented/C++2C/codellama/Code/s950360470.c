#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;
const ll MOD = 1e9 + 7; // Define a constant for modulo operation (1000000007)

// Function to compute a raised to the power n (a^n)
ll pow(ll a, ll n) {
  ll res = 1; // Initialize result to 1
  while (n > 0) { // Loop until n becomes 0
    if (n & 1) res *= a; // If n is odd, multiply result by a
    a *= a; // Square the base
    n >>= 1; // Divide n by 2
  }
  return res; // Return the computed power
}

// Function to compute a raised to the power n modulo mod (a^n % mod)
ll mod_pow(ll a, ll n, ll mod) {
  ll res = 1; // Initialize result to 1
  while (n > 0) { // Loop until n becomes 0
    if (n & 1) res = res * a % mod; // If n is odd, multiply result by a and take modulo
    a = a * a % mod; // Square the base and take modulo
    n >>= 1; // Divide n by 2
  }
  return res; // Return the computed power modulo
}

// Function to compute modular multiplicative inverse of a modulo mod (a^(-1) % mod)
// This function assumes that a is not divisible by mod
ll mod_inv(ll a, ll mod) {
  return mod_pow(a, mod - 2, mod); // Use Fermat's Little Theorem to compute inverse
}

// Function to compute n choose k modulo mod (nCk % mod)
ll mod_nCk(int n, int k, int mod) {
  if (n == 0 || k == 0) return 1; // Base case: nC0 = 1
  ll p = 1, q = 1; // Initialize numerator (p) and denominator (q)
  
  // Calculate the numerator for nCk
  for (int i = n - k + 1; i <= n; i++)
    p = (p * i) % MOD; // Multiply terms from (n-k+1) to n and take modulo
  
  // Calculate the denominator for nCk
  for (int i = 2; i <= k; i++)
    q = (q * i) % MOD; // Multiply terms from 1 to k and take modulo
  
  q = mod_inv(q, MOD); // Compute the modular inverse of the denominator
  return (p * q) % MOD; // Return the result of nCk modulo
}

int main() {
  int n, k; // Declare variables for n and k
  scanf("%d %d", &n, &k); // Read values of n and k from input
  printf("%lld\n", mod_nCk(k, n, MOD)); // Compute and print nCk modulo MOD
}

