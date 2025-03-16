
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <random>
#define ll long long
#define endl '\n'
#define MOD 100000007
#define MOD2 998244353
#define EPS 1e-9
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define debug(x) cout << #x << ":" << x << endl;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int MAX = 1000000;
ll fac[MAX];
ll inv[MAX];
ll mod_pow(ll x, ll n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}
void init() {
    fac[0] = 1;
    for(int i = 1; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[MAX - 1] = mod_pow(fac[MAX - 1], MOD - 2);
    for(int i = MAX - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}
ll comb(ll n, ll k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    init();
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll ans = 0;
    rep(i, N) {
        ans += A[i] * (inv[i] + inv[N - 1 - i] - 1) % MOD;
        ans %= MOD;
    }
    ans *= fac[N];
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
