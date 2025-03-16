
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <errno.h>
#include <complex.h>
#include <stdatomic.h>

typedef long long ll;
typedef unsigned long long llu;
typedef unsigned long ul;
typedef long l;

#define reps(i, s, n) for (ll i = s; i < n; i++)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define each(it, v) for (auto it = v.begin(); it!= v.end(); it++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)

using namespace std;

// Define a large constant for infinity
const ll MOD = 1000000007;
const ll LLINF = 1LL << 60;
const int IINF = 1 << 30;

// Read an integer 'n' from input
ll n;

// If n is 1, print 0 and exit
int main() {
    scanf("%lld", &n);
    if (n == 1) {
        puts("0");
        return 0;
    }

    // Function to perform prime factorization of a number
    vector<ll> prime_factorize(ll n) {
        vector<ll> a;
        // Divide n by 2 until it is odd
        while (n % 2 == 0) {
            a.pb(2);
            n /= 2;
        }

        // Check for odd factors from 3 upwards
        for (ll f = 3; f * f <= n; f += 2) {
            if (n % f == 0) {
                a.pb(f);
                n /= f;
            }
        }

        // If n is still greater than 1, it is a prime factor
        if (n!= 1) {
            a.pb(n);
        }

        return a;
    }

    // Perform prime factorization on n
    vector<ll> fac = prime_factorize(n);

    // Count the occurrences of each prime factor
    map<ll, ll> fac_;
    for (auto p : fac) {
        fac_[p]++;
    }

    // Initialize the answer variable
    ll ans = 0;

    // Calculate the number of ways to express the prime factors
    for (auto p : fac_) {
        ll x = p.se;
        // For each prime factor's exponent, calculate how many times it can be used
        for (ll i = 1; i <= 99999999; i++) {
            if (x >= i) {
                x -= i;
                ans++;
            } else {
                break;
            }
        }
    }

    // Print the final answer
    printf("%lld\n", ans);

    return 0;
}

Translate the above C code to Rust and end with comment "