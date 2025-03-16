
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>
#include <locale>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <ctime>
#include <cassert>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REPR(i, n) for (int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORR(i, a, b) for (int i = (a); i >= (b); i--)
#define FOREACH(i, t) for (auto i : t)
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) a.resize(distance(a.begin(), unique(ALL(a))))
#define fill(a, b) memset((a), (b), sizeof(a))
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second
#define eb emplace_back
#define endl '\n'
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) cerr << #x << ": " << x << ", " << #y << ": " << y << endl;
#define debug3(x, y, z) cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;

const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const ll MAXLL = 1e18 + 5;

template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
void setmax(T& a, T b) { a = max(a, b); }
template<typename T>
void setmin(T& a, T b) { a = min(a, b); }

template<typename T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

template<typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

template<typename T>
T expo(T base, T exp, T mod) {
    T res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

template<typename T>
T modinv(T a, T mod) {
    return expo(a, mod - 2, mod);
}

template<typename T>
void get_primes(T n, vector<T>& primes) {
    vector<T> is_prime(n + 1, true);
    for (T i = 2; i <= n; i++) {
        if (is_prime[i]) primes.pb(i);
        for (T j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }
}

template<typename T>
T extended_ euclid(T a, T b, T& x, T& y) {
    T xx = y = 0;
    T yy = x = 1;
    while (b) {
        T q = a / b;
        T t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}

template<typename T>
T mod_inverse(T a, T n) {
    T x, y;
    T d = extended_euclid(a, n, x, y);
    if (d > 1) return -1;
    return mod(x, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vi a(n);
    REP(i, n) cin >> a[i];

    int max_profit = 0;
    int max_cnt = 0;
    int max_a = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        int profit = max(0, max_a - a[i]);
        if (profit == max_profit) {
            max_cnt++;
        } else if (profit > max_profit) {
            max_profit = profit;
            max_cnt = 1;
        }
        max_a = max(max_a, a[i]);
    }
    cout << max_cnt << endl;

    return 0;
}

