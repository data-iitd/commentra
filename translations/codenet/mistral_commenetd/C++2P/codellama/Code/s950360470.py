#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <math.h>
#include <cmath> // For std::pow() in C++11 and later
using namespace std;

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <math.h>
#include <cmath> // For std::pow() in C++11 and later
using namespace std;

// Constants
typedef long long ll;
const ll MOD = 1e9 + 7; //1000000007                                                    // Modulus value

// Helper functions
// a^n
ll pow(ll a, ll n) {
  ll res = 1; // Initialize result
  while (n > 0) { // While n is greater than 0
    if (n & 1) res *= a; // If n is odd, multiply result with base
    a *= a; // Square the base
    n >>= 1; // Divide n by 2
  }
  return res; // Return the final result
}

// a^n % mod
ll mod_pow(ll a, ll n, ll mod) {
  ll res = 1; // Initialize result
  while (n > 0) { // While n is greater than 0
    if (n & 1) res = (res * a) % MOD; // If n is odd, multiply result with base and take modulo
    a = (a * a) % MOD; // Square the base and take modulo
    n >>= 1; // Divide n by 2
  }
  return res; // Return the final result
}

// a^(-1) % mod (only if : a % p != 0)
ll mod_inv(ll a, ll mod) {
  return mod_pow(a, mod - 2, mod); // Calculate the modular inverse of 'a'
}

// nCk % mod
ll mod_nCk(int n, int k, int mod) {
  if (n == 0 || k == 0) return 1; // Base case: nC0 = kC0 = 1

  ll p = 1, q = 1; // Initialize p and q
  for (int i = n - k + 1; i <= n; i++) // Calculate p = nC(n-k+1)
    p = (p * i) % MOD;

  for (int i = 2; i <= k; i++) // Calculate q = k!
    q = (q * i) % MOD;

  q = mod_inv(q, MOD); // Calculate q^(-1) modulo 'mod'
  return (p * q) % MOD; // Return the final result: nCk = p * q
}

int main() {
  int n, k; // Initialize variables n and k to read input values
  cin >> n >> k; // Read input values for n and k from the standard input

  cout << mod_nCk(k, n, MOD) << endl; // Print the result of nCk modulo 'MOD'
}

