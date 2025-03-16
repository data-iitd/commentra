
```cpp
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<ctype.h>

// Define type aliases for convenience
typedef long long ll;
typedef long double ld;

// Macros for loop iterations and constants
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k) for(ll i=(l);i<(r);i+=(k))
#define rrep(i,l,r) for(ll i=(l);i>=(r);i--)
#define INF (1LL<<60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N (1 << 20)
#define YES printf("Yes\n")
#define NO printf("No\n")
#define PN printf("\n")
#define charsize 100005 // Maximum character size
#define PI 3.141592653589793238

// Function to swap two long long integers
void swap(ll *a, ll *b) {
    ll c;
    c = *b;
    *b = *a;
    *a = c;
}

// Function to read a long long integer
void cin(ll *n) { 
    scanf("%lld", &(*n)); 
}

// Functions to find maximum and minimum of two or three numbers
ll max2(ll a, ll b) { return a >= b? a : b; }
ll min2(ll a, ll b) { return a >= b? b : a; }
ll min3(ll a, ll b, ll c) { return (a <= b && a <= c)? a : b <= c? b : c; }
ll max3(ll a, ll b, ll c) { return (a >= b && a >= c)? a : b >= c? b : c; }

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
ll gcd(ll a, ll b) { return b? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Functions for modular arithmetic
ll mod_MOD1(ll n) { 
    n += n < 0? ((-n) / MOD1 + 1) * MOD1 : 0; 
    return n %= MOD1; 
}
ll mod_p(ll n, ll p) { 
    n += n < 0? ((-n) / p + 1) * p : 0; 
    return n %= p; 
}

// Function to convert a string to a number
ll change_into_num(char s[], ll len, ll p) { 
    return!p? 0 : POW(10, p - 1) * (s[len - p] - '0'); 
}

// Function to count the number of digits in a number
ll digits(ll a, ll b) { 
    return a / b? digits(a / b, a % b) : 1; 
}

// Functions to check if an index is within array bounds
ll is_inArr1(ll x, ll n) { return (x < 0 || x >= n)? 0 : 1; }
ll is_inArr2(ll y, ll x, ll h, ll w) { return (y < 0 || y >= h || x < 0 || x >= w)? 0 : 1; }

// Functions for lower and upper bounds in binary search
void lr_lower(int *l, int *r, ll am, ll val, int type) { 
    (type < 3)? (type == 1)? (type == 2)? (type == 1)? (*l = (*l + *r) / 2, *r = (*l + *r) / 2) : (*r = (*l + *r) / 2); 
}
void lr_upper(int *l, int *r, ll am, ll val, int type) { 
    (type == 1)? (type == 2)? (type == 1)? (*l = (*l + *r) / 2, *r = (*l + *r) / 2) : (*r = (*l + *r) / 2, *r = (*l + *r) / 2); 
}

// Comparison functions for lower and upper bounds
int cmp_lower(ll a, ll b, int type) { 
    return (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)? (type == 2)? (type == 1)