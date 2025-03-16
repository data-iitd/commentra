
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
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }
    vector<vector<int>> l;
    vector<int> rem;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (auto j : itertools::combinations(pre.begin(), pre.end(), i)) {
            l.push_back(vector<int>(j.begin(), j.end()));
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < l.size(); j++) {
            int ca = 0;
            for (int k : l[j]) {
                ca += c[k][i];
            }
            if (ca < x) {
                rem.insert(rem.begin(), j);
            } else {
                // do nothing
            }
        }
        if (rem.size() > 0) {
            for (int j : rem) {
                l.erase(l.begin() + j);
            }
            rem.clear();
        }
        if (l.size() == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < l.size(); i++) {
        int ca = 0;
        for (int j : l[i]) {
            ca += c[j][0];
        }
        if (ans == 0) {
            ans = ca;
        } else {
            ans = min(ans, ca);
        }
    }
    cout << ans << endl;
    return 0;
}

