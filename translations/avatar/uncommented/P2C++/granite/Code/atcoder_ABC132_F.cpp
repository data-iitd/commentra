
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> coef;
    for (ll i = 1; i * i <= n; i++) {
        coef.push_back((n / i) - (n / (i + 1)));
    }
    coef.push_back(1);
    while (coef.size() < n) coef.push_back(0);
    reverse(coef.begin(), coef.end());
    ll nn = coef.size();
    vector<vector<ll>> dp(k + 1, vector<ll>(nn, 0));
    dp[0][0] = 1;
    for (ll i = 1; i <= k; i++) {
        ll tmp = 0;
        for (ll j = nn - 1; j >= 0; j--) {
            tmp += dp[i - 1][(nn - 1) - j];
            tmp %= mod;
            dp[i][j] = coef[j] * tmp;
            dp[i][j] %= mod;
        }
    }
    ll ans = 0;
    for (ll i = 0; i < nn; i++) {
        ans += dp[k][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
