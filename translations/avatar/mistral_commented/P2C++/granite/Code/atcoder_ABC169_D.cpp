
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <sstream>
#include <numeric>
#include <math.h>
#include <iomanip>
#include <cassert>
#include <random>
#include <time.h>
#include <fstream>
#include <complex>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef pair<double, double> Pd;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REPD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define CLR(arr, val) memset(arr, val, sizeof(arr))
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort((x).begin(), (x).end())
#define REV(x) reverse((x).begin(), (x).end())
#define SZ(x) ((int)(x).size())
#define UNIQUE(x) (x).erase(unique(ALL(x)), (x).end())
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define DUMP(x, u)                                                                                                   \
    do {                                                                                                              \
        if (u)                                                                                                         \
            cout << #x << " : " << (x) << endl;                                                                     \
        else                                                                                                           \
            cout << #x << " = " << (x) << endl;                                                                     \
    } while (0)
#define DEBUG(x) cerr << #x << " = " << (x) << endl;
#define DEBUG2(x, y)-------------------------------------------------------------------------------------------------- \
    do {                                                                                                              \
        cerr << #x << " = " << (x) << "," << #y << " = " << y << endl;                                            \
    } while (0)
#define DEBUG3(x, y, z)                                                                                             \
    do {                                                                                                              \
        cerr << #x << " = " << (x) << "," << #y << " = " << y << "," << #z << " = " << z << endl;                   \
    } while (0)

#define X first
#define Y second
#define MP make_pair
#define PB push_back

const int dr[]{-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[]{0, 1, 1, 1, 0, -1, -1, -1};

const int MOD = 1000000007;
const double EPS = 1e-9;
const int INT_INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

ll gcd(ll a, ll b) { return b? gcd(b, a % b) : a; }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

ll fpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

ll inv(ll x) { return fpow(x, MOD - 2); }

ll C(ll n, ll k) {
    ll res = 1;
    REP(i, k) {
        res = res * (n - i) % MOD * inv(i + 1) % MOD;
    }
    return res;
}

template <typename T>
T read() {
    T x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> p;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            p.PB(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        p.PB(n);
    }
    int ans = 0;
    for (int i : p) {
        int x = i;
        while (x <= 1e9) {
            ans++;
            x *= i;
        }
    }
    cout << ans << endl;

    return 0;
}

