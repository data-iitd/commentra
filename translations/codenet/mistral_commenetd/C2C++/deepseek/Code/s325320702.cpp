#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
void cin(ll &n) { cin >> n; }
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
    // Function to find the lowest index i such that a[i] = val
    // If type is less than 3, then am < val, otherwise am <= val
}
void lr_upper(int &l, int &r, ll am, ll val, int type) {
    // Function to find the highest index i such that a[i] = val
    // If type is less than 3, then am <= val, otherwise am < val
}
int cmp_lower(ll a, ll b, int type) {
    // Comparison function for lower_bound
    // If type is 1, then a == b, otherwise a < b (type = 2) or a < b (type = 3)
    return (type == 1 ? a == b : (type == 2 ? a < b : a <= b));
}
int cmp_upper(ll a, ll b, int type) {
    // Comparison function for upper_bound
    // If type is 1, then a == b, otherwise a <= b (type = 2) or a < b (type = 3)
    return (type == 1 ? a == b : (type == 2 ? a <= b : a < b));
}
ll lower_bound(ll a[], int l, int r, ll val, int type) {
    // Binary search function for finding the lowest index i such that a[i] = val
    // If type is 1, then a[i] == val, otherwise a[i] <= val (type = 2) or a[i] < val (type = 3)
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (cmp_lower(a[mid], val, type)) l = mid + 1;
        else r = mid;
    }
    return l;
}
ll upper_bound(ll a[], int l, int r, ll val, int type) {
    // Binary search function for finding the highest index i such that a[i] = val
    // If type is 1, then a[i] == val, otherwise a[i] <= val (type = 2) or a[i] < val (type = 3)
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (cmp_upper(a[mid], val, type)) r = mid;
        else l = mid + 1;
    }
    return l;
}
ll count(ll a[], int l, int r, ll x) {
    // Function to find the number of occurrences of x in the subarray a[l..r]
    ll cnt = 0;
    rep(i, l, r + 1) {
        if (a[i] == x) cnt++;
    }
    return cnt;
}
ll factor(ll n, ll new_common_plus) {
    // Function to find the prime factorization of n
    // new_common_plus can be 1 (common factor), 2 (common factor and its power), or 0 (no common factor)
    ll cnt = 0;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
    }
    if (n > 1) cnt++;
    return cnt;
}
ll judge_prime(ll n) {
    // Function to check if n is prime
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
ll makeinv(ll x, ll mod, ll is_fac) {
    // Function to calculate the multiplicative inverse of x modulo mod
    // is_fac can be 1 (calculate the inverse of x) or 0 (calculate the inverse of mod/x)
    ll m0 = mod, t, q;
    ll x0 = 0, x1 = 1;
    if (mod == 1) return 0;
    while (x > 1) {
        q = x / mod;
        t = mod;
        mod = x % mod, x = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}
ll m_inv(ll x, ll mod, ll is_fac) {
    // Function to calculate the inverse of x modulo mod
    // is_fac can be 1 (calculate the inverse of x) or 0 (calculate the inverse of mod/x)
    return makeinv(x, mod, is_fac);
}
ll m_f(ll x, ll mod) {
    // Function to calculate the multiplicative function of x modulo mod
    ll result = 1;
    for (ll i = 2; i * i <= x; i++) {
        ll cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        result *= (cnt + 1);
    }
    if (x > 1) result *= 2;
    return result % mod;
}
ll mod_nck(ll n, ll k, ll mod) {
    // Function to calculate nCk modulo mod
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    ll res = 1;
    for (ll i = 1; i <= k; i++) {
        res = res * (n - i + 1) % mod * m_inv(i, mod, 1) % mod;
    }
    return res;
}
ll m_p(ll r, ll n, ll mod) {
    // Function to calculate r^n modulo mod
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) res = res * r % mod;
        r = r * r % mod;
        n /= 2;
    }
    return res;
}
ll m_mul2(ll a, ll b, ll mod) {
    // Function to calculate the product of two numbers modulo mod
    ll res = 0;
    a = mod_p(a, mod);
    while (b > 0) {
        if (b % 2 == 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return res;
}
ll m_mul3(ll a, ll b, ll c, ll mod) {
    // Function to calculate the product of three numbers modulo mod
    return m_mul2(m_mul2(a, b, mod), c, mod);
}
ll m_mul4(ll a, ll b, ll c, ll d, ll mod) {
    // Function to calculate the product of four numbers modulo mod
    return m_mul2(m_mul2(a, b, mod), m_mul2(c, d, mod), mod);
}
ll m_mul5(ll a, ll b, ll c, ll d, ll e, ll mod) {
    // Function to calculate the product of five numbers modulo mod
    return m_mul2(m_mul2(m_mul2(a, b, mod), m_mul2(c, d, mod), mod), e, mod);
}
void sortup(ll *a, int n) {
    // Function to sort an array in ascending order
    sort(a, a + n);
}
void sortdown(ll *a, int n) {
    // Function to sort an array in descending order
    sort(a, a + n, greater<ll>());
}
int upll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? -1 : *(ll *)a > *(ll *)b ? 1 : 0; }
int downll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? 1 : *(ll *)a > *(ll *)b ? -1 : 0; }
int cmp_string(const void *a, const void *b) { return strcmp((char *)a, (char *)b); }
int cmp_char(const void *a, const void *b) { return *(char *)a - *(char *)b; }
ll unique_string(ll n, ll size, char s[][size]) {
    // Function to find the number of unique elements in an array or a string
    ll ans = 1;
    rep(i, 1, n) if (strcmp(s[i], s[i - 1])) ans++;
    return ans;
}
ll unique_num(ll n, ll a[]) {
    // Function to find the number of unique elements in an array
    ll ans = 1;
    rep(i, 1, n) if (a[i] != a[i - 1]) ans++;
    return ans;
}
int main(void) {
    // Main function
    ll l, r, d;
    ll ans = 0;
    cin >> l >> r >> d;
    rep(i, l, r + 1) {
        if (i % d == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
