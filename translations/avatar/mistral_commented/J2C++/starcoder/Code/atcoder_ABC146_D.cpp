
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
int ans[100000];

void dfs(int to, int color, int parents) {
 int k = 1;
 for (int i = 0; i < g[to].size(); i++) {
 if (g[to][i] == parents) continue;
 if (k == color) k++;
 ans[g[to][i]] = k;
 dfs(g[to][i], k, to);
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
 for (int temp : ans) {
 max = max > temp? max : temp;
 }
 cout << max << endl;
 for (int c : ans) {
 cout << c << endl;
 }
 return 0;
}

