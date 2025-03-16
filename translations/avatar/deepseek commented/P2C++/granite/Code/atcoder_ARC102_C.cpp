
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
const int MAX_N = 8000;

// Function to calculate binomial coefficient modulo mod
ll cmb(int n, int r, ll mod) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    ll res = 1;
    for (int i = 0; i < r; i++) {
        res = (res * (n - i)) % mod;
        res = (res * modpow(i + 1, mod - 2, mod)) % mod;
    }
    return res;
}

// Function to calculate modular exponentiation
ll modpow(ll a, ll n, ll mod) {
    if (n == 0) return 1;
    ll res = modpow(a * a % mod, n / 2, mod);
    if (n % 2) res = res * a % mod;
    return res;
}

// Function to solve the problem for a given n
ll solve(int n) {
    ll ans = 0;
    int kumi = (n - 1) / 2;
    for (int p = 0; p <= kumi; p++) {
        if (p > N) break;
        ans += modpow(2, p, MOD) * cmb(kumi, p, MOD) % MOD * cmb(N - p + kumi - p - 1, kumi - p, MOD) % MOD;
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += modpow(2, p, MOD) * cmb(kumi, p, MOD) % MOD * cmb(N - p - 1 + kumi - p, kumi - p, MOD) % MOD;
        }
    }
    return ans % MOD;
}

int main() {
    int K, N;
    cin >> K >> N;
    vector<ll> ans;
    for (int i = 2; i <= 2 * K; i++) {
        if (i <= K + 1) {
            ll tmp = solve(i);
            ans.push_back(tmp);
            cout << tmp << endl;
        } else {
            cout << ans[i - K - 2] << endl;
        }
    }
    return 0;
}

