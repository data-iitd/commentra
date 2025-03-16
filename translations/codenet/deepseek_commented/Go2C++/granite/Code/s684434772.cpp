
#include <iostream>
#include <algorithm>
#include <vector>
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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
const int MAXLOG = 20;
const ll MAXLL = 1e18 + 10;
const ll inf = 1e18;

ll combi(int n, int k) {
    ll min = (ll)k * (k - 1) / 2;
    ll max = (ll)(2 * n - k + 1) * k / 2;
    return max - min + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    ll total = 0;
    for (int i = k; i <= n + 1; i++) {
        total += combi(n, i);
        total %= (ll)1e9 + 7;
    }
    cout << total << endl;

    return 0;
}

