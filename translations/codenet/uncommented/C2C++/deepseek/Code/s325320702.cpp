#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <random>
#include <cassert>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define repp(i, l, r, k) for (ll i = (l); i < (r); i += (k))
#define rrep(i, l, r) for (ll i = (l); i >= (r); i--)
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N (1 << 20)
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define PN cout << "\n"
#define charsize 100005 //10^5+5
#define PI 3.141592653589793238

void swap(ll &a, ll &b) { ll c; c = b; b = a; a = c; }
void cin(ll *n) { cin >> (*n); }
ll max2(ll a, ll b) { return a >= b ? a : b; }
ll min2(ll a, ll b) { return a >= b ? b : a; }
ll min3(ll a, ll b, ll c) { return (a <= b && a <= c) ? a : b <= c ? b : c; }
ll max3(ll a, ll b, ll c) { return (a >= b && a >= c) ? a : b >= c ? b : c; }
ll minn(ll n, ll a[]) { ll b = INF; rep(i, 0, n) b = min2(b, a[i]); return b; }
ll maxn(ll n, ll a[]) { ll b = -INF; rep(i, 0, n) b = max2(b, a[i]); return b; }
ll POW(ll a, ll b) { ll c = 1; rep(i, 0, b) c *= a; return c; }
double POW_d(double a, double b) { double c = 1; rep(i, 0, b) c *= a; return c; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll mod_MOD1(ll n) { n += n < 0 ? ((-n) / MOD1 + 1) * MOD1 : 0; return n %= MOD1; }
ll mod_p(ll n, ll p) { n += n < 0 ? (( -n) / p + 1) * p : 0; return n %= p; }
ll change_into_num(char s[], ll len, ll p) { return !p ? 0 : POW(10, p - 1) * (s[len - p] - '0') + change_into_num(s, len, p - 1); }
ll digits(ll a, ll b) { return a / b ? 1 + digits(a / b, b) : 1; }
ll base(ll n, ll a, ll i) { return i == 1 ? n % a : base(n / a, a, i - 1); }
ll is_inArr1(ll x, ll n) { return (x < 0 || x >= n) ? 0 : 1; }
ll is_inArr2(ll y, ll x, ll h, ll w) { return (y < 0 || y >= h || x < 0 || x >= w) ? 0 : 1; }

void lr_lower(int &l, int &r, ll am, ll val, int type) {
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am <= val ? (l = (l + r) / 2) : (r = (l + r) / 2)) :
    (type < 3) ? (am < val ? (l = (l + r) / 2) : (