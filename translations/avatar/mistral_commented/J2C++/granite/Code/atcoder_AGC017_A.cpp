

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <utility>
#include <climits>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <random>
#include <chrono>
#include <limits>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
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
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<pii, int> mpi;
typedef map<pll, ll> mpll;

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;
const double eps = 1e-9;
const ll LLINF = 1e18;

ll C(int n, int m) {
    ll res = 1;

    for (int i = m - n + 1; i <= m; i++) {
        res *= i;
    }

    for (int i = 1; i <= n; i++) {
        res /= i;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin >> n >> p;

    int k0 = 0, k1 = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x % 2 == 1) {
            k1++;
        } else {
            k0++;
        }
    }

    ll ans = 1;

    for (int i = 0; i < k0; i++) {
        ans *= 2;
    }

    if (p == 0) {
        ll add = 0;

        for (int i = 0; i <= k1; i += 2) {
            add += C(i, k1);
        }

        ans *= add;
    } else {
        ll add = 0;

        for (int i = 1; i <= k1; i += 2) {
            add += C(i, k1);
        }

        ans *= add;
    }

    cout << ans << endl;

    return 0;
}

These comments should provide a clear understanding of the code and its functionality.