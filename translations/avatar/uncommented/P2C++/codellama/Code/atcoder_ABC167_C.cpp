#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> c(n, vector<int>(m + 1));
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m + 1; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }
    vector<vector<int>> l;
    vector<int> rem;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < pow(2, i); j++) {
            vector<int> tmp;
            for (int k = 0; k < i; k++) {
                if (j & (1 << k)) {
                    tmp.push_back(pre[k]);
                }
            }
            l.push_back(tmp);
        }
    }
    for (int i = 1; i < m + 1; i++) {
        for (int j = 0; j < l.size(); j++) {
            int ca = 0;
            for (int k = 0; k < l[j].size(); k++) {
                ca += c[l[j][k]][i];
            }
            if (ca < x) {
                rem.push_back(j);
            }
        }
        if (rem.size() > 0) {
            for (int j = 0; j < rem.size(); j++) {
                l.erase(l.begin() + rem[j]);
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
        for (int j = 0; j < l[i].size(); j++) {
            ca += c[l[i][j]][0];
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



Translate the above Python code to Java and end with comment "