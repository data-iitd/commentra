
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <climits>
#include <bitset>
#include <iomanip>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>
#include <stack>
#include <valarray>
#include <list>
#include <bitset>
#include <utility>
#include <memory>

using namespace std;
using ll = long long;

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
        if (good[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

