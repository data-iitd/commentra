
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <random>
#include <chrono>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using si = set<int>;
using msi = map<string, int>;
using mii = map<int, int>;
using mci = map<char, int>;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const ll oo = 1e18;
const ld EPS = 1e-9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    ll total = 0;
    for (int i = k; i <= n + 1; i++) {
        ll min = (ll)(k - 1) * k / 2;
        ll max = (ll)(2 * n - k + 1) * k / 2;
        total += max - min + 1;
        total %= MOD;
    }
    cout << total << endl;

    return 0;
}

