#include <iostream>
#include <vector>
#include <numeric> // For std::gcd
#include <cmath> // For std::pow
#include <limits.h> // For LONG_MAX

using namespace std;

typedef long long ll;

// Function to calculate the modular inverse
ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algo
        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to perform modular division
ll modDiv(ll a, ll b, ll mod) {
    a = a % mod;
    ll inv = modInverse(b, mod);
    return (inv * a) % mod;
}

// Function to calculate power with modular arithmetic
ll modPow(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);

    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll lcm = 1;

    for (ll ai : A) {
        ll g = gcd(lcm, ai);
        lcm = (lcm / g) * ai;
    }

    ll mod = 1000000007;
    ll modLcm = lcm % mod;
    ll ans = 0;

    for (ll ai : A) {
        ans = (ans + modDiv(modLcm, ai, mod)) % mod;
    }

    cout << ans << endl;

    return 0;
}
