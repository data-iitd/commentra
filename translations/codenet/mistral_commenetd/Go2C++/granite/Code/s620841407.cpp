

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

struct ReRootingSolver {
  int nodeCount;
  vector<vector<int>> adjacents;
  vector<vector<int>> indexForAdjacents;
  vector<ll> res;
  vector<vector<ll>> dp;
  ll identity;
  function<ll(ll, ll)> operate;
  function<ll(ll, int)> operateNode;

  ReRootingSolver(int nodeCount, vector<vector<int>> edges, ll identity, function<ll(ll, ll)> operate, function<ll(ll, int)> operateNode) : nodeCount(nodeCount), identity(identity), operate(operate), operateNode(operateNode) {
    adjacents.resize(nodeCount);
    indexForAdjacents.resize(nodeCount);
    for (auto &e : edges) {
      indexForAdjacents[e[0]].push_back(adjacents[e[1]].size());
      indexForAdjacents[e[1]].push_back(adjacents[e[0]].size());
      adjacents[e[0]].push_back(e[1]);
      adjacents[e[1]].push_back(e[0]);
    }
    dp.resize(nodeCount);
    for (auto &v : dp) v.resize(adjacents.size());
    res.resize(nodeCount);
    if (nodeCount > 1) {
      initialize();
    } else {
      res[0] = operateNode(identity, 0);
    }
  }

  ll query(int node) {
    return res[node];
  }

  void initialize() {
    vector<int> parents(nodeCount), order(nodeCount);

    // InitOrderedTree
    int index = 0;
    stack<int> stack;
    stack.push(0);
    parents[0] = -1;
    while (!stack.empty()) {
      int node = stack.top();
      stack.pop();
      order[index] = node;
      index++;
      for (int i = 0; i < adjacents[node].size(); i++) {
        int adjacent = adjacents[node][i];
        if (adjacent == parents[node]) continue;
        stack.push(adjacent);
        parents[adjacent] = node;
      }
    }

    // fromLeaf
    for (int i = nodeCount - 1; i >= 1; i--) {
      int node = order[i];
      int parent = parents[node];

      ll accum = identity;
      int parentIndex = -1;
      for (int j = 0; j < adjacents[node].size(); j++) {
        if (adjacents[node][j] == parent) {
          parentIndex = j;
          continue;
        }
        accum = operate(accum, dp[node][j]);
      }
      dp[parent][indexForAdjacents[node][parentIndex]] = operateNode(accum, node);
      accum = operate(accum, dp[node][j]);
      dp[node][j] = accum;
    }

    // toLeaf
    for (int i = 0; i < nodeCount; i++) {
      int node = order[i];
      ll accum = identity;
      vector<ll> accumsFromTail(adjacents[node].size());
      accumsFromTail[adjacents[node].size() - 1] = identity;
      for (int j = adjacents[node].size() - 1; j >= 1; j--) {
        accumsFromTail[j - 1] = operate(dp[node][j], accumsFromTail[j]);
      }
      for (int j = 0; j < accumsFromTail.size(); j++) {
        dp[adjacents[node][j]][indexForAdjacents[node][j]] = operateNode(operate(accum, accumsFromTail[j]), node);
        accum = operate(accum, dp[node][j]);
      }
      res[node] = operateNode(accum, node);
    }
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    edges[i] = {x, y};
  }

  ReRootingSolver solver(n, edges, 1, [](ll a, ll b) { return (a * b) % m; }, [](ll v, int p) { return v + 1; });

  for (int i = 0; i < n; i++) {
    cout << solver.query(i) - 1 << endl;
  }

  return 0;
}

