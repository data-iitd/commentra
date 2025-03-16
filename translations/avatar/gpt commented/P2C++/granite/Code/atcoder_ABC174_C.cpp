
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <utility>
#include <numeric>
#include <iterator>
#include <iomanip>
#include <cassert>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
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

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define fored(i, l, r) for (int i = (int)(r); i >= (int)(l); i--)
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define debug3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define debugv(v) cout << #v << " = "; for (auto x : v) cout << x << " "; cout << endl;
#define debuga(a, n) cout << #a << " = "; forn(i, n) cout << a[i] << " "; cout << endl;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(1.0 * (x))
#define fi first
#define se second
#define endl '\n'
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    int t = 0;
    forn(i, k) {
        t = (t % k) * 10 + 7;
        if (t % k == 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}

Translate the above C++ code to Java and end with comment "