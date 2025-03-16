

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#include <bitset>
#include <stack>
#include <functional>
#include <random>
#include <cassert>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    vector<bool> good(n, true);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (h[a] > h[b]) {
            good[b] = false;
        } else if (h[a] < h[b]) {
            good[a] = false;
        } else {
            good[a] = false;
            good[b] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (good[i]) ans++;
    }
    cout << ans << endl;

    return 0;
}

