

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Main : public thread {
public:
  vector < vector < int > > graph;
  vector < bool > visited;
  vector < int > color;
  ll one, bipartite, count;
  bool mujun;

  void run() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    visited.resize(n);
    color.resize(n);
    fill(color.begin(), color.end(), -1);
    one = bipartite = count = 0;
    for (int i = 0; i < n; i++) {
      if (visited[i]) continue;
      count++;
      mujun = false;
      int kind = dfs(i, 0);
      if (kind == 1) one++;
      else if (!mujun) bipartite++;
    }
    ll total = one * (2 * n - one);
    total += (count - one) * (count - one);
    total += bipartite * bipartite;
    cout << total << endl;
  }

  int dfs(int a, int c) {
    if (visited[a]) {
      if (color[a] >= 0 && color[a]!= c) mujun = true;
      return 0;
    }
    visited[a] = true;
    color[a] = c;
    int total = 1;
    for (int b : graph[a]) {
      total += dfs(b, 1 - c);
    }
    return total;
  }
};

int main() {
  Main().join();
  return 0;
}

