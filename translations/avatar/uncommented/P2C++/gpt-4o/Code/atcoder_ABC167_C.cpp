#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <iterator>

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
    int ans = numeric_limits<int>::max();

    for (int i = 1; i <= n; ++i) {
        vector<bool> v(n);
        fill(v.begin(), v.begin() + i, true);
        do {
            vector<int> combination;
            for (int j = 0; j < n; ++j) {
                if (v[j]) {
                    combination.push_back(pre[j]);
                }
            }
            l.push_back(combination);
        } while (prev_permutation(v.begin(), v.end()));
    }

    for (int i = 1; i <= m; ++i) {
        for (size_t j = 0; j < l.size(); ++j) {
            int ca = 0;
            for (int ii : l[j]) {
                ca += c[ii][i];
            }
            if (ca < x) {
                rem.insert(rem.begin(), j);
            }
        }
        if (!rem.empty()) {
            for (int j : rem) {
                l.erase(l.begin() + j);
            }
            rem.clear();
        }
        if (l.empty()) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (const auto& i : l) {
        int ca = 0;
        for (int j : i) {
            ca += c[j][0];
        }
        ans = min(ans, ca);
    }

    cout << (ans == numeric_limits<int>::max() ? -1 : ans) << endl;

    return 0;
}

// <END-OF-CODE>
