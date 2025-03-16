
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>
#include <tuple>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOREACH(i, t) for (typeof((t).begin()) i = (t).begin(); i!= (t).end(); ++i)
#define RANGE(i, a, b) (a <= i && i <= b)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define WALL(a, b) cout << "#Wall" << endl;
#define mp make_pair
#define pb push_back

const int INF = 1e9;
const double EPS = 1e-8;
const int MOD = 100000007;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main() {
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;
    bool ok = false;
    REP(i, t) {
        int first = a - (da * i);
        REP(j, t) {
            int second = b - (db * j);
            if (second + first == x || second == x || first == x || x == 0) {
                ok = true;
                break;
            }
        }
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
// END-OF-CODE