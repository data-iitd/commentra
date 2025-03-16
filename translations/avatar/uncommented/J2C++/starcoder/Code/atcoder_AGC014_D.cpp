#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        int a = 0;
        for (int j = 0; j < g[i].size(); j++) {
            if (g[i][j] == i) continue;
            a += maxMatching(g[i][j], i) / 2;
        }
        m = max(m, a);
    }
    if (2 * m == n) {
        cout << "Second";
    } else {
        cout << "First";
    }
    return 0;
}

