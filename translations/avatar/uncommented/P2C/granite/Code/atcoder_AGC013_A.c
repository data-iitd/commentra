
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio_ext.h>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <numeric>
#include <iomanip>
#include <chrono>
#include <regex>
#include <tuple>
using namespace std;
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define trav(a, x) for (auto& a : x)
#define unique(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define _1 first
#define _2 second
#define clog(x) cout << #x << " = " << x << endl;
#define os(x) setprecision(15) << fixed << x
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef pair<pll, pll> ppll;
typedef vector<ppll> vppll;
typedef priority_queue<int> pq;
typedef priority_queue<int, vi, greater<int>> pqs;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
ll randll(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
template<typename T> void print(T x, string end = "\n") { cout << x << end; }
template<typename T> void print(vector<T> v, string sep = " ", string end = "\n") { for (T i : v) cout << i << sep; cout << end; }
template<typename T, size_t size> void print(array<T, size> a, string sep = " ", string end = "\n") { for (T i : a) cout << i << sep; cout << end; }
template<typename T, typename V> void print(vector<pair<T, V>> v, string sep = " ", string end = "\n") { for (auto p : v) cout << '(' << p.fi << ", " << p.se << ')' << sep; cout << end; }
template<typename T, typename V> void print(map<T, V> m, string sep = " ", string end = "\n") { for (auto p : m) cout << '(' << p.fi << ", " << p.se << ')' << sep; cout << end; }
template<typename T> void print(set<T> s, string sep = " ", string end = "\n") { for (auto i : s) cout << i << sep; cout << end; }
template<typename T> void print(T a[], int l, int r, string sep = " ", string end = "\n") { for (int i = l; i <= r; i++) cout << a[i] << sep; cout << end; }
template<typename T> void print(vector<T> v, int l, int r, string sep = " ", string end = "\n") { for (int i = l; i <= r; i++) cout << v[i] << sep; cout << end; }
const int mxn = 1e5 + 10;
const int mxa = 1e6 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9;
const ll infl = 1e18;
const ld pi = 4.0 * atanl(1.0);
const ld eps = 1e-10;
int n, a[mxn], ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    forn(i, n) cin >> a[i];
    forn(i, n - 2) {
        if ((a[i] < a[i + 1] && a[i + 1] > a[i + 2]) || (a[i] > a[i + 1] && a[i + 1] < a[i + 2])) {
            ans++;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
