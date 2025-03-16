#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> li(m);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        li[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> li[i][j];
        }
    }
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        set<int> q;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                q.insert(i + 1);
            }
        }
        bool valid = true;
        for (int i = 0; i < m; ++i) {
            int count = 0;
            for (int x : li[i]) {
                if (q.count(x)) {
                    ++count;
                }
            }
            if (count % 2 != p[i]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}
