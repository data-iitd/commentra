
#include <bits/stdc++.h>
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

    vector<int> pre;
    for (int i = 0; i < n; i++) {
        pre.push_back(i);
    }

    vector<vector<int>> l;
    vector<int> rem;
    int ans = 0;

    for (int i = 0; i <= len(pre); i++) {
        for (auto j : itertools.combinations(pre, i)) {
            l.push_back(j);
        }
    }

    for (int i = 1; i <= m; i++) {
        int ca = 0;
        for (auto j : l[i]) {
            ca += c[j][i];
        }

        if (ca < x) {
            rem.insert(rem.begin(), i);
        } else {
            continue;
        }

        if (!rem.empty()) {
            for (auto j : rem) {
                l.erase(l.begin() + j);
            }
            rem.clear();
        }

        if (l.empty()) {
            cout << -1 << endl;
            break;
        }
    }

    if (!l.empty()) {
        int ca = 0;
        for (auto i : l) {
            ca = 0;
            for (auto j : i) {
                ca += c[j][0];
            }

            if (ans == 0) {
                ans = ca;
            } else {
                ans = min(ans, ca);
            }
        }

        cout << ans << endl;
    }

    return 0;
}

