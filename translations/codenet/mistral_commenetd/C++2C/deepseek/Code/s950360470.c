#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants
#define MOD 1000000007 // Modulus value

// Helper functions
// a^n
long long pow(long long a, long long n) {
  long long res = 1; // Initialize result
  while (n > 0) { // While n is greater than 0
    if (n & 1) res *= a; // If n is odd, multiply result with base
    a *= a; // Square the base
    n >>= 1; // Divide n by 2
  }
  return res; // Return the final result
}

// a^n % mod
long long mod_pow(long long a, long long n, long long mod) {
  long long res = 1; // Initialize result
  while (n > 0) { // While n is greater than 0
    if (n & 1) res = (res * a) % mod; // If n is odd, multiply result with base and take modulo
    a = (a * a) % mod; // Square the base and take modulo
    n >>= 1; // Divide n by 2
  }
  return res; // Return the final result
}

// a^(-1) % mod (only if : a % p != 0)
long long mod_inv(long long a, long long mod) {
  return mod_pow(a, mod - 2, mod); // Calculate the modular inverse of 'a'
}

// nCk % mod
long long mod_nCk(int n, int k, int mod) {
  if (n == 0 || k == 0) return 1; // Base case: nC0 = kC0 = 1

  long long p = 1, q = 1; // Initialize p and q
  for (int i = n - k + 1; i <= n; i++) // Calculate p = nC(n-k+1)
    p = (p * i) % MOD;

  for (int i = 2; i <= k; i++) // Calculate q = k!
    q = (q * i) % MOD;

  q = mod_inv(q, MOD); // Calculate q^(-1) modulo 'mod'
  return (p * q) % MOD; // Return the final result: nCk = p * q
}

int main() {
  int n, k; // Initialize variables n and k to read input values
  scanf("%d %d", &n, &k); // Read input values for n and k from the standard input

  printf("%lld\n", mod_nCk(k, n, MOD)); // Print the result of nCk modulo 'MOD'
}
