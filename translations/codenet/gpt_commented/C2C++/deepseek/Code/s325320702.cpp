#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cctype>

// Define type aliases for convenience
using ll = long long;
using ld = long double;

// Macros for loop iterations and constants
#define rep(i, l, r) for(ll i = (l); i < (r); i++)
#define repp(i, l, r, k) for(ll i = (l); i < (r); i += (k))
#define rrep(i, l, r) for(ll i = (l); i >= (r); i--)
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N (1 << 20)
#define YES std::cout << "Yes\n"
#define NO std::cout << "No\n"
#define PN std::cout << "\n"
#define charsize 100005 // Maximum character size
#define PI 3.141592653589793238

// Function to swap two long long integers
void swap(ll &a, ll &b) {
    ll c = b;
    b = a;
    a = c;
}

// Function to read a long long integer
void cin(ll &n) { 
    std::cin >> n; 
}

// Functions to find maximum and minimum of two or three numbers
ll max2(ll a, ll b) { return a >= b ? a : b; }
ll min2(ll a, ll b) { return a >= b ? b : a; }
ll min3(ll a, ll b, ll c) { return std::min({a, b, c}); }
ll max3(ll a, ll b, ll c) { return std::max({a, b, c}); }

// Functions to find minimum and maximum in an array
ll minn(ll n, ll a[]) { 
    ll b = INF; 
    rep(i, 0, n) b = std::min(b, a[i]); 
    return b; 
}
ll maxn(ll n, ll a[]) { 
    ll b = -INF; 
    rep(i, 0, n) b = std::max(b, a[i]); 
    return b; 
}

// Functions for power calculations
ll POW(ll a, ll b) { 
    ll c = 1; 
    rep(i, 0, b) c *= a; 
    return c; 
}
double POW_d(double a, double b) { 
    double c = 1; 
    rep(i, 0, b) c *= a; 
    return c; 
}

// Functions for GCD and LCM calculations
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Functions for modular arithmetic
ll mod_MOD1(ll n) { 
    n += n < 0 ? ((-n) / MOD1 + 1) * MOD1 : 0; 
    return n % MOD1; 
}
ll mod_p(ll n, ll p) { 
    n += n < 0 ? ((-n) / p + 1) * p : 0; 
    return n % p; 
}

// Function to convert a string to a number
ll change_into_num(const char s[], ll len, ll p) { 
    return !p ? 0 : POW(10, p - 1) * (s[len - p] - '0') + change_into_num(s, len, p - 1); 
}

// Function to count the number of digits in a number
ll digits(ll a, ll b) { 
    return a / b ? 1 + digits(a / b, b) : 1; 
}

// Functions to check if an index is within array bounds
ll is_inArr1(ll x, ll n) { return (x < 0 || x >= n) ? 0 : 1; }
ll is_inArr2(ll y, ll x, ll h, ll w) { return (y < 0 || y >= h || x < 0 || x >= w) ? 0 : 1; }

// Functions for lower and upper bounds in binary search
void lr_lower(int &l, int &r, ll am, ll val, int type) { 
    (type < 3) ? (am < val ? l = (l + r) / 2 : r = (l + r) / 2) : (am <= val ? l = (l + r) / 2 : r = (l + r) / 2); 
}
void lr_upper(int &l, int &r, ll am, ll val, int type) { 
    (type < 3) ? (am <= val ? l = (l + r) / 2 : r = (l + r) / 2) : (am < val ? l = (l + r) / 2 : r = (l + r) / 2); 
}

// Comparison functions for lower and upper bounds
int cmp_lower(ll a, ll b, int type) { 
    return (type == 1) ? (a == b ? 1 : 0) : (type == 2) ? (a >= b ? 1 : 0) : (a > b ? 1 : 0); 
}
int cmp_upper(ll a, ll b, int type) { 
    return (type == 1) ? (a == b ? 1 : 0) : (type == 2) ? (a <= b ? 1 : 0) : (a < b ? 1 : 0); 
}

// Function to find the lower bound in an array
ll lower_bound(ll a[], int l, int r, ll val, int type) {  
    while (r - l > 1) lr_lower(l, r, a[(l + r) / 2], val, type);  
    return cmp_lower(a[l], val, type) ? l : cmp_lower(a[r], val, type) ? r : -1;  
}

// Function to find the upper bound in an array
ll upper_bound(ll a[], int l, int r, ll val, int type) {  
    while (r - l > 1) lr_upper(l, r, a[(l + r) / 2], val, type); 
    return cmp_upper(a[r], val, type) ? r : cmp_upper(a[l], val, type) ? l : -1; 
}

// Function to count occurrences of a value in an array
ll count(ll a[], int l, int r, ll x) {  
    int p = lower_bound(a, l, r, x, 1);  
    return p == -1 ? 0 : upper_bound(a, p, r, x, 1) - p + 1; 
}

// Global variables for factorization
std::vector<ll> factors[2], fac_cnt = 0, is_factor_prepared = 0;

// Function to prepare factors for prime factorization
ll factor_pre() {  
    rep(i, 0, 1) { 
        if (is_factor_prepared++) return 0; 
    }  
    ll tmp = (1e6) / 2 + 1;
    std::vector<ll> fac_tmp(tmp);  
    rep(i, 0, tmp) { fac_tmp[i] = i ? 2 * i + 1 : 2; }  
    rep(i, 1, tmp) { 
        if (fac_tmp[i]) {  
            repp(j, 3, tmp / (2 * i + 1) + 1, 2) {  
                if (j * (2 * i + 1) < tmp) fac_tmp[(j * (2 * i + 1) - 1) / 2] = 0;  
            }  
        } else continue; 
    }  
    rep(i, 0, tmp) { 
        if (fac_tmp[i]) {  
            rep(j, 0, 2) { 
                factors[j].push_back(j ? 0 : fac_tmp[i]);  
            }  
        } 
    }  
    return 0;  
}

// Function to factor a number and update factor counts
ll factor(ll n, ll new_common_plus) { 
    factor_pre();  
    rep(i, 0, factors[0].size()) { 
        ll cnt = 0; 
        while (n % factors[0][i] == 0) { 
            cnt++; 
            n /= factors[0][i]; 
        } 
        if (new_common_plus == 1) {
            factors[1].push_back(cnt); 
        } else if (new_common_plus == 2) {
            factors[1].back() = std::max(factors[1].back(), cnt); 
        } else {
            factors[1].push_back(factors[1].back() + cnt); 
        }
        if (factors[0][i] > n) break; 
    } 
    if (n > 1) {
        if (new_common_plus == 1) {
            factors[1].push_back(1); 
        } else if (new_common_plus == 2) {
            factors[1].back() = std::max(factors[1].back(), 1LL); 
        } else {
            factors[1].push_back(factors[1].back() + 1); 
        }
    }
    return n; 
}

// Function to judge if a number is prime
ll judge_prime(ll n) { 
    factor_pre(); 
    rep(i, 0, factors[0].size()) { 
        if (n < factors[0][i] * factors[0][i] || n == factors[0][i]) break; 
        else if (n % factors[0][i] == 0) n /= n; 
    }  
    return n == 1 ? 0 : 1; 
}

// Global variables for modular inverses and factorials
std::vector<ll> mf_arr, inv_arr, finv_arr;
ll is_minv_made = 0, is_mf_made = 0, num_of_inv = 2 * 1e6 + 10;

// Function to create modular inverses
ll makeinv(ll n, ll mod) {  
    if (is_minv_made++) return 0;  
    inv_arr.resize(n + 1);  
    finv_arr.resize(n + 1);  
    inv_arr[1] = 1; 
    finv_arr[0] = finv_arr[1] = 1;  
    rep(i, 2, n + 1) {  
        inv_arr[i] = mod - inv_arr[mod % i] * (mod / i) % mod;  
        finv_arr[i] = finv_arr[i - 1] * inv_arr[i] % mod;  
    }  
    return 0; 
}

// Function to create factorials
ll make_mf(ll n, ll mod) {  
    if (is_mf_made++) return 0;  
    mf_arr.resize(n + 1);  
    ll x = 1;  
    mf_arr[0] = mf_arr[1] = x;  
    rep(i, 2, n + 1) {   
        x = x * i % mod;  
        mf_arr[i] = x; 
    }  
    return 0;  
}

// Function to get modular inverse based on whether it's factorial or not
ll m_inv(ll x, ll mod, ll is_fac) { 
    makeinv(num_of_inv, mod);  
    return is_fac ? finv_arr[x] : inv_arr[x]; 
}

// Function to get factorial modulo
ll m_f(ll x, ll mod) {  
    make_mf(num_of_inv, mod);  
    return mf_arr[x];  
}

// Function to calculate n choose k modulo
ll mod_nck(ll n, ll k, ll mod) { 
    return m_f(n, mod) * m_inv(k, mod, 1) % mod * m_inv(n - k, mod, 1) % mod; 
}

// Function for modular exponentiation
ll m_p(ll r, ll n, ll mod) {  
    ll t = 1, s = r;  
    while (n > 0) { 
        t = (n & 1) ? t * s % mod : t;  
        s = s * s % mod; 
        n >>= 1; 
    }  
    return r ? t : 0;  
}

// Functions for modular multiplication
ll m_mul2(ll a, ll b, ll mod) { return a * b % mod; }
ll m_mul3(ll a, ll b, ll c, ll mod) { return m_mul2(a * b % mod, c, mod); }
ll m_mul4(ll a, ll b, ll c, ll d, ll mod) { return m_mul3(a * b % mod, c, d, mod); }
ll m_mul5(ll a, ll b, ll c, ll d, ll e, ll mod) { return m_mul4(a * b % mod, c, d, e, mod); }

// Comparison functions for sorting
bool upll(const ll &a, const ll &b) { return a < b; }
bool downll(const ll &a, const ll &b) { return a > b; }
bool cmp_string(const void *a, const void *b) { return strcmp((char *)a, (char *)b); }
bool cmp_char(const void *a, const void *b) { return *(char *)a - *(char *)b; }

// Sorting functions
void sortup(ll *a, int n) { std::sort(a, a + n, upll); }
void sortdown(ll *a, int n) { std::sort(a, a + n, downll); }
void sort_string(int n, int size, char s[][size]) { qsort((void *)s, n, sizeof(s[0]), cmp_string); }
void sort_char(char *s) { std::sort(s, s + strlen(s)); }

// Functions to count unique strings and numbers
ll unique_string(ll n, ll size, char s[][size]) { 
    ll ans = 1; 
    rep(i, 1, n) if (strcmp(s[i], s[i - 1])) ans++; 
    return ans; 
}
ll unique_num(ll n, ll a[]) { 
    ll ans = 1; 
    rep(i, 1, n) if (a[i] != a[i - 1]) ans++; 
    return ans; 
}

// Structure for sorting pairs
typedef struct { ll a, b; } fr;

// Comparison functions for sorting pairs
bool cmp1(const fr &p, const fr &q) { return p.a < q.a; }
bool cmp2(const fr &p, const fr &q) { return p.a > q.a; }

// Sorting functions for pairs
void strsortup(fr *a, int n) { std::sort(a, a + n, cmp1); }
void strsortdown(fr *a, int n) { std::sort(a, a + n, cmp2); }

// Main function
char s[1151154]; // Buffer for input
int main(void) {
    // Read input values for l, r, and d
    ll l, r, d;
    ll ans = 0;
    cin(l);
    cin(r);
    cin(d);

    // Count the multiples of d in the range [l, r]
    rep(i, l, r + 1) {
        if (i % d == 0) ans++;
    }

    // Output the result
    std::cout << ans << std::endl;
    return 0;
}
