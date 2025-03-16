
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <cassert>
#include <random>
#include <iomanip>

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int inf = numeric_limits<int>::max() / 2;

template <typename T>
void vprint(const vector<T> &v) {
    int sz = v.size();
    for (int i = 0; i < sz; i++) {
        cout << v[i] << " \n"[i == sz-1];
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 0;
    int a_prev = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > i || a > a_prev + 1) {
            cout << -1 << endl;
            return 0;
        }
        if (a == a_prev + 1) {
            ans++;
        } else {
            ans += a;
        }
        a_prev = a;
    }
    cout << ans << endl;
    return 0;
}

