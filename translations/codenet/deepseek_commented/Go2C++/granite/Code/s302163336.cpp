
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <tuple>

using namespace std;

int main() {
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
        a--;
        b--;
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
        if (good[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

