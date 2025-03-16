
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

typedef long long ll;

ll mod_pow(ll x, ll n, ll mod) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

ll mod_inv(ll x, ll mod) {
    return mod_pow(x, mod - 2, mod);
}

ll mod_div(ll a, ll b, ll mod) {
    return a * mod_inv(b, mod) % mod;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll lcm = 1;
    for (int ai : A) {
        ll a = ai;
        lcm = lcm / __gcd(lcm, a) * a;
    }

    ll mod = 1000000007;
    ll mod_lcm = lcm % mod;

    ll ans = 0;
    for (int ai : A) {
        ans = (ans + mod_div(mod_lcm, ai, mod)) % mod;
    }

    cout << ans << endl;

    return 0;
}

