#include <bits/stdc++.h>
using namespace std;

int n;
vector < vector < int >> g;
int ans[100000];

void dfs(int to, int color, int parents) {
    int k = 1;
    for (int i = 0; i < g[to].size(); i++) {
        int to = g[to][i];
        if (to == parents) continue;
        if (k == color) k++;
        ans[g[to][i]] = k;
        dfs(to, k, to);
        k++;
    }
}

int main() {
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1, -1);
    int max = 0;
    for (int i = 0; i < n - 1; i++) {
        max = max > ans[i]? max : ans[i];
    }
    cout << max << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}

