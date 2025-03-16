#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, a, b) for(int i = a; i >= b; --i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
#define PB push_back
#define MP make_pair
#define CLR(x) memset(x, 0, sizeof(x))
#define SET(x) memset(x, -1, sizeof(x))
#define ST first
#define ND second
#define INF 1000000000
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.14159265358979323846

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int k;
    cin >> s >> k;

    int l = 0;
    REP(i, SIZE(s)) {
        if (s[i] != '1') {
            break;
        }
        l++;
    }

    if (l >= k) {
        cout << 1 << endl;
    } else {
        cout << s[l] << endl;
    }

    return 0;
}
