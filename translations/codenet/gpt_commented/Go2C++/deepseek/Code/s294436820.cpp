#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <numeric>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <cassert>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define x first
#define y second
#define endl '\n'

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);

const int N = 100;

int h, w, k;
char m[N][N];

int countBlack(int h, int w, char m[N][N]) {
    int count = 0;
    forn(i, h) {
        forn(j, w) {
            if (m[i][j] == '#') {
                count++;
            }
        }
    }
    return count;
}

int solve(int h, int w, int k, char m[N][N]) {
    int result = 0;
    forn(i, 1 << h) {
        forn(j, 1 << w) {
            char tmp[N][N];
            memcpy(tmp, m, sizeof(m));
            forn(ii, h) {
                if (i & (1 << ii)) {
                    forn(jj, w) {
                        tmp[ii][jj] = '.';
                    }
                }
            }
            forn(jj, w) {
                if (j & (1 << jj)) {
                    forn(ii, h) {
                        tmp[ii][jj] = '.';
                    }
                }
            }
            if (countBlack(h, w, tmp) == k) {
                result++;
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> h >> w >> k;
    forn(i, h) {
        cin >> m[i];
    }

    int answer = solve(h, w, k, m);
    cout << answer << endl;

    return 0;
}
