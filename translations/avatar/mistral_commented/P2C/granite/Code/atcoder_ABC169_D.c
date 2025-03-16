
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <random>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 0 << nl;
        return;
    }
    vector<int> fac;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            fac.pb(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) fac.pb(n);
    int ans = 0;
    for (int p : fac) {
        int e = 0;
        for (int i = 1; i <= 1000000000; i++) {
            if (i > e) {
                ans++;
                e += i;
            } else break;
        }
    }
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    FOR(t, 1, T+1) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}

Translate the above C code to Rust and end with comment "