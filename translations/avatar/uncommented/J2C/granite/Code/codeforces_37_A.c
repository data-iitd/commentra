
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <ctgmath>
#include <chrono>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef priority_queue<int> pqmin;
typedef priority_queue<int, vector<int>, greater<int>> pqmax;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int dx8[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy8[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int MAX = 2e5 + 5;
const ll MAXN = 1e18;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int oo = INT_MAX;
const ll OO = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }
ll randll(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }
ll gcd(ll a, ll b) { return b == 0? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll fpow(ll a, ll b, ll mod = MOD) {
    if (!b) return 1;
    ll res = fpow(a * a % mod, b / 2, mod);
    return (b & 1)? res * a % mod : res;
}
ll divmod(ll i, ll j, ll mod = MOD) {
    i %= mod, j %= mod;
    return i * fpow(j, mod - 2, mod) % mod;
}
ll add(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
ll sub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll mul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }
ll invp(ll a, ll mod = MOD) { return fpow(a, mod - 2, mod); }
ll nCr(ll n, ll r, ll mod = MOD) {
    if (n < r) return 0;
    if (n == r ||!r) return 1;
    return mul(fac[n], mul(invfac[r], invfac[n - r]));
}
ll nPr(ll n, ll r, ll mod = MOD) { return mul(fac[n], invfac[n - r]); }
ll nHr(ll n, ll r, ll mod = MOD) { return nCr(r + n - 1, r, mod); }
void precalc() {
    fac.resize(MAX);
    invfac.resize(MAX);
    fac[0] = invfac[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fac[i] = mul(fac[i - 1], i);
        invfac[i] = invp(fac[i], MOD);
    }
}
int main() {
    faster;
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int mx = 0;
    for (auto it : mp) {
        mx = max(mx, it.second);
    }
    cout << mx <<'' << mp.size() << endl;
    return 0;
}
