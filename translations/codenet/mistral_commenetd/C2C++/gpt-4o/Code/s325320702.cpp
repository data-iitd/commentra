#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cctype>

using namespace std;

// Include necessary standard libraries

typedef long long ll;
typedef long double ld;

// Define custom data types

#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k) for(ll i=(l);i<(r);i+=(k))
#define rrep(i,l,r) for(ll i=(l);i>=(r);i--)

// Macros for repetition

#define INF (1LL<<60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N (1 << 20)
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
#define PN cout << endl;
#define charsize 100005 //10^5+5
#define PI 3.141592653589793238

// Constants and definitions

void swap(ll &a, ll &b) { ll c; c = b; b = a; a = c; }
// Function to swap two variables

void cin(ll &n) { cin >> n; }
// Function to read an integer from the standard input

ll max2(ll a, ll b) { return a >= b ? a : b; }
// Function to find the maximum of two numbers

ll min2(ll a, ll b) { return a >= b ? b : a; }
// Function to find the minimum of two numbers

ll min3(ll a, ll b, ll c) { return (a <= b && a <= c) ? a : b <= c ? b : c; }
// Function to find the minimum of three numbers

ll max3(ll a, ll b, ll c) { return (a >= b && a >= c) ? a : b >= c ? b : c; }
// Function to find the maximum of three numbers

ll minn(ll n, ll a[]) { ll b = INF; rep(i, 0, n) b = min2(b, a[i]); return b; }
// Function to find the minimum number in an array

ll maxn(ll n, ll a[]) { ll b = -INF; rep(i, 0, n) b = max2(b, a[i]); return b; }
// Function to find the maximum number in an array

ll POW(ll a, ll b) { ll c = 1; rep(i, 0, b) c *= a; return c; }
// Function to calculate a^b

double POW_d(double a, double b) { double c = 1; rep(i, 0, b) c *= a; return c; }
// Function to calculate a^b (double version)

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// Function to find the greatest common divisor of two numbers

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
// Function to find the least common multiple of two numbers

ll mod_MOD1(ll n) { n += n < 0 ? ((-n) / MOD1 + 1) * MOD1 : 0; return n %= MOD1; }
// Function to calculate n % MOD1

ll mod_p(ll n, ll p) { n += n < 0 ? ((-n) / p + 1) * p : 0; return n %= p; }
// Function to calculate n % p

ll change_into_num(char s[], ll len, ll p) { return !p ? 0 : POW(10, p - 1) * (s[len - p] - '0') + change_into_num(s, len, p - 1); }
// Function to convert a substring of a string into a number

ll digits(ll a, ll b) { return a / b ? 1 + digits(a / b, b) : 1; }
// Function to calculate the number of digits in a number

ll base(ll n, ll a, ll i) { return i == 1 ? n % a : base(n / a, a, i - 1); }
// Function to calculate the base representation of a number

ll is_inArr1(ll x, ll n) { return (x < 0 || x >= n) ? 0 : 1; }
// Function to check if a number is within the range of an array

ll is_inArr2(ll y, ll x, ll h, ll w) { return (y < 0 || y >= h || x < 0 || x >= w) ? 0 : 1; }
// Function to check if a pair of coordinates is within the range of a rectangle

void lr_lower(int *l, int *r, ll am, ll val, int type) {
    // Function to find the lowest index i such that a[i] = val
    // If type is less than 3, then am < val, otherwise am <= val
}

void lr_upper(int *l, int *r, ll am, ll val, int type) {
    // Function to find the highest index i such that a[i] = val
    // If type is less than 3, then am <= val, otherwise am < val
}

int cmp_lower(ll a, ll b, int type) {
    // Comparison function for lower_bound
    // If type is 1, then a == b, otherwise a < b (type = 2) or a < b (type = 3)
}

int cmp_upper(ll a, ll b, int type) {
    // Comparison function for upper_bound
    // If type is 1, then a == b, otherwise a <= b (type = 2) or a < b (type = 3)
}

// Functions for finding the lowest and highest indices of a value in an array

ll lower_bound(ll a[], int l, int r, ll val, int type) {
    // Binary search function for finding the lowest index i such that a[i] = val
    // If type is 1, then a[i] == val, otherwise a[i] <= val (type = 2) or a[i] < val (type = 3)
}

ll upper_bound(ll a[], int l, int r, ll val, int type) {
    // Binary search function for finding the highest index i such that a[i] = val
    // If type is 1, then a[i] == val, otherwise a[i] <= val (type = 2) or a[i] < val (type = 3)
}

// Functions for finding the number of occurrences of a value in an array

ll count(ll a[], int l, int r, ll x) {
    // Function to find the number of occurrences of x in the subarray a[l..r]
}

ll factor(ll n, ll new_common_plus) {
    // Function to find the prime factorization of n
    // new_common_plus can be 1 (common factor), 2 (common factor and its power), or 0 (no common factor)
}

ll judge_prime(ll n) {
    // Function to check if n is prime
}

// Functions for calculating the inverse and multiplicative function of a number modulo another number

ll makeinv(ll x, ll mod, ll is_fac) {
    // Function to calculate the multiplicative inverse of x modulo mod
    // is_fac can be 1 (calculate the inverse of x) or 0 (calculate the inverse of mod/x)
}

ll m_inv(ll x, ll mod, ll is_fac) {
    // Function to calculate the inverse of x modulo mod
    // is_fac can be 1 (calculate the inverse of x) or 0 (calculate the inverse of mod/x)
}

ll m_f(ll x, ll mod) {
    // Function to calculate the multiplicative function of x modulo mod
}

ll mod_nck(ll n, ll k, ll mod) {
    // Function to calculate nCk modulo mod
}

ll m_p(ll r, ll n, ll mod) {
    // Function to calculate r^n modulo mod
}

ll m_mul2(ll a, ll b, ll mod) {
    // Function to calculate the product of two numbers modulo mod
}

ll m_mul3(ll a, ll b, ll c, ll mod) {
    // Function to calculate the product of three numbers modulo mod
}

ll m_mul4(ll a, ll b, ll c, ll d, ll mod) {
    // Function to calculate the product of four numbers modulo mod
}

ll m_mul5(ll a, ll b, ll c, ll d, ll e, ll mod) {
    // Function to calculate the product of five numbers modulo mod
}

// Functions for sorting arrays

int upll(const void* a, const void* b) { return *(ll*)a < *(ll*)b ? -1 : *(ll*)a > *(ll*)b ? 1 : 0; }
int downll(const void* a, const void* b) { return *(ll*)a < *(ll*)b ? 1 : *(ll*)a > *(ll*)b ? -1 : 0; }
int cmp_string(const void* a, const void* b) { return strcmp((char*)a, (char*)b); }  // qsort((void*)s,n,sizeof(s[0]),int_sort );
int cmp_char(const void* a, const void* b) { return *(char*)a - *(char*)b; }
void sortup(ll* a, int n) { qsort(a, n, sizeof(ll), upll); }
void sortdown(ll* a, int n) { qsort(a, n, sizeof(ll), downll); }
void sort_string(int n, int size, char s[][size]) { qsort((void*)s, n, sizeof(s[0]), cmp_string); }
void sort_char(char* s) { qsort((void*)s, strlen(s), sizeof(char), cmp_char); }

// Function to find the number of unique elements in an array or a string

ll unique_string(ll n, ll size, char s[][size]) { ll ans = 1; rep(i, 1, n) if (strcmp(s[i], s[i - 1])) ans++; return ans; }
ll unique_num(ll n, ll a[]) { ll ans = 1; rep(i, 1, n) if (a[i] != a[i - 1]) ans++; return ans; }

// Global variables and constants

char s[1151154];

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

// <END-OF-CODE>
