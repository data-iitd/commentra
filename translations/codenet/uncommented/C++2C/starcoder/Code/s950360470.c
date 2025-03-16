#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#define MOD 1000000007

//a^n
long long pow(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}

//a^n % mod
long long mod_pow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

//a^(-1) % mod (only if : a % p!= 0)
long long mod_inv(long long a, long long mod) {
  return mod_pow(a, mod - 2, mod);
}

//nCk % mod
long long mod_nCk(int n, int k, int mod) {
  if (n == 0 || k == 0) return 1;
  long long p = 1, q = 1;
  for (int i = n - k + 1; i <= n; i++)
    p = (p * i) % MOD;
  for (int i = 2; i <= k; i++)
    q = (q * i) % MOD;
  q = mod_inv(q, MOD);
  return (p * q) % MOD;
}

int main() {
  int n, k; scanf("%d %d", &n, &k);
  printf("%lld\n", mod_nCk(k, n, MOD));
}

