
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>> c(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }

    vector<int> pre(n);
    iota(pre.begin(), pre.end(), 0);

    vector<vector<int>> l;
    vector<int> rem;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            l.push_back({i, j});
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < l.size(); j++) {
            int ca = 0;
            for (int k : l[j]) {
                ca += c[k][i];
            }
            if (ca < x) {
                rem.push_back(j);
            }
        }
        if (rem.size() > 0) {
            for (int j : rem) {
                l.erase(l.begin() + j);
            }
            rem.clear();
        } else {
            break;
        }
    }

    if (l.size() == 0) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < l.size(); i++) {
            int ca = 0;
            for (int j : l[i]) {
                ca += c[j][0];
            }
            if (i == 0) {
                ans = ca;
            } else {
                ans = min(ans, ca);
            }
        }
        cout << ans << endl;
    }

    return 0;
}

