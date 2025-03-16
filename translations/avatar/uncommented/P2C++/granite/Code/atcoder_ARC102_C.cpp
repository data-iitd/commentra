
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll K, N;
ll g1[8001], g2[8001], inv[8001];
ll cmb(ll n, ll r, ll mod) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    return g1[n] * g2[r] % mod * g2[n - r] % mod;
}
ll kumiawase(ll p, ll q) {
    return cmb(p + q - 1, q - 1, mod);
}
ll solve(ll n) {
    assert(n <= K + 1);
    ll ans = 0;
    ll kumi = (n - 1) / 2;
    for (ll p = 0; p <= kumi; p++) {
        if (p > N) break;
        ans += (1LL << p) * cmb(kumi, p, mod) % mod * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0))) % mod;
        if (n % 2 == 0 && N - p - 1 >= 0) {
            ans += (1LL << p) * cmb(kumi, p, mod) % mod * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0))) % mod;
        }
    }
    return ans;
}
int main() {
    cin >> K >> N;
    g1[0] = g2[0] = 1;
    inv[1] = 1;
    for (ll i = 1; i <= 8000; i++) {
        g1[i] = g1[i - 1] * i % mod;
        if (i > 1) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        g2[i] = g2[i - 1] * inv[i] % mod;
    }
    vector<ll> ans;
    for (ll i = 2; i <= 2 * K; i++) {
        if (i <= K + 1) {
            ll tmp = solve(i) % mod;
            ans.push_back(tmp);
            cout << tmp << endl;
        } else {
            cout << ans[i - K - 2] << endl;
        }
    }
    return 0;
}
