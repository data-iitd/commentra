#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define _USE_MATH_DEFINES
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,n) for(int i=0;i<n;i++)
#define show(s) printf("%s\n", s)
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define LINF (1000000000000000000ll)
#define MOD (1e9+7)
#define rep1(i,n) for(int i =1;i<=n;i++)

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} P;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcd(ll a, ll b) {
    if (b == 0) return a;
    return (a / gcd(a, b)) * b;
}

int* divnum(ll num) {
    int dig;
    int* p = (int*)malloc(sizeof(int) * 100005);
    int index = 0;
    while (num) {
        dig = num % 10;
        p[index++] = dig;
        num /= 10;
    }
    return p;
}

int digiter(ll num) {
    int dig;
    int* p = (int*)malloc(sizeof(int) * 100005);
    int index = 0;
    while (num) {
        dig = num % 10;
        p[index++] = dig;
        num /= 10;
    }
    return index;
}

int* convertstring(char* s) {
    int* d = (int*)malloc(sizeof(int) * 100005);
    int n = strlen(s);
    rep(i, n) {
        d[i] = s[i] - '0';
    }
    return d;
}

typedef struct {
    ll first;
    ll second;
} mint;

mint prime_factor(ll n) {
    mint ret;
    ret.first = 0;
    ret.second = 0;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret.first = i;
            ret.second++;
            n /= i;
        }
    }
    if (n != 1) {
        ret.first = n;
        ret.second = 1;
    }
    return ret;
}

ll* divisor(ll n) {
    ll* res = (ll*)malloc(sizeof(ll) * 100005);
    int index = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i != 0) continue;
        res[index++] = i;
        if (i * i != n) res[index++] = n / i;
    }
    return res;
}

ll myPow(ll x, ll n, ll m) {
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return myPow(x * x % m, n / 2, m);
    else
        return x * myPow(x, n - 1, m) % m;
}

int* Eratosthenes(const int N) {
    int* is_prime = (int*)malloc((N + 1) * sizeof(int));
    for (int i = 0; i <= N; i++) {
        is_prime[i] = 1;
    }
    int* P = (int*)malloc((N + 1) * sizeof(int));
    int index = 0;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                is_prime[j] = 0;
            }
            P[index++] = i;
        }
    }
    return P;
}

const ll mod = MOD;
mint mint_new(ll x) {
    x = (x % mod + mod) % mod;
    mint ret;
    ret.first = x;
    return ret;
}

mint mint_operator_minus(mint a) {
    return mint_new(-a.first);
}

mint& mint_operator_plus_equal(mint* a, mint b) {
    a->first = (a->first + b.first) % mod;
    if (a->first >= mod) a->first -= mod;
    return *a;
}

mint& mint_operator_minus_equal(mint* a, mint b) {
    a->first = (a->first + mod - b.first) % mod;
    if (a->first >= mod) a->first -= mod;
    return *a;
}

mint& mint_operator_multiply_equal(mint* a, mint b) {
    a->first = (a->first * b.first) % mod;
    return *a;
}

mint mint_operator_plus(mint a, mint b) {
    return mint_new(a.first + b.first);
}

mint mint_operator_minus(mint a, mint b) {
    return mint_new(a.first + mod - b.first);
}

mint mint_operator_multiply(mint a, mint b) {
    return mint_new(a.first * b.first);
}

mint mint_pow(mint x, ll t) {
    if (t == 0) return mint_new(1);
    mint a = mint_pow(x, t >> 1);
    a = mint_operator_multiply(a, a);
    if (t & 1) a = mint_operator_multiply(a, x);
    return a;
}

mint mint_inv(mint x) {
    return mint_pow(x, mod - 2);
}

mint& mint_operator_divide_equal(mint* a, mint b) {
    *a = mint_operator_multiply(*a, mint_inv(b));
    return *a;
}

mint mint_operator_divide(mint a, mint b) {
    return mint_operator_multiply(a, mint_inv(b));
}

typedef struct {
    mint* fact;
    mint* ifact;
} combination;

combination comb_new(ll n) {
    combination ret;
    ret.fact = (mint*)malloc((n + 1) * sizeof(mint));
    ret.ifact = (mint*)malloc((n + 1) * sizeof(mint));
    ret.fact[0] = mint_new(1);
    for (ll i = 1; i <= n; ++i) ret.fact[i] = mint_operator_multiply(ret.fact[i - 1], mint_new(i));
    ret.ifact[n] = mint_operator_divide(ret.fact[n], ret.fact[n]);
    for (ll i = n; i >= 1; --i) ret.ifact[i - 1] = mint_operator_multiply(ret.ifact[i], mint_new(i));
    return ret;
}

mint comb_operator(combination* c, ll n, ll k) {
    if (k < 0 || k > n) return mint_new(0);
    return mint_operator_multiply(c->fact[n], mint_operator_multiply(c->ifact[k], c->ifact[n - k]));
}

mint f(ll n, ll k) {
    if (n < 0) return mint_new(0);
    mint res = comb_operator(&comb(1000005), n, k);
    res = mint_operator_multiply(res, c