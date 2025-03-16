#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>> c(n, vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cin >> c[i][j];
        }
    }

    vector<int> pre(n);
    iota(pre.begin(), pre.end(), 0);

    vector<vector<int>> l;
    vector<int> rem;
    int ans = 0;

    for (int i = 0; i <= pre.size(); ++i) {
        for (auto j : combinations(pre.begin(), pre.begin() + i)) {
            l.push_back(vector<int>(j, j + i));
        }
    }

    for (int i = 1; i <= m; ++i) {
        int ca = 0;
        for (auto j : l[i]) {
            ca += c[j][i];
        }
        if (ca < x) {
            rem.insert(rem.begin(), i);
        }
        if (ca >= x) {
            continue;
        }
        if (!rem.empty()) {
            for (auto j : rem) {
                l.erase(remove_if(l.begin(), l.end(), [j](const vector<int>& vec) { return find(vec.begin(), vec.end(), j) != vec.end(); }), l.end());
            }
            rem.clear();
        }
        if (l.empty()) {
            cout << -1 << endl;
            return 0;
        }
    }

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
    return 0;
}

