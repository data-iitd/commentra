#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000 + 7;

class ReRootingSolver {
public:
    int NodeCount;
    vector<vector<int>> Adjacents;
    vector<vector<int>> IndexForAdjacents;
    vector<int> Res;
    vector<vector<int>> DP;
    int Identity;
    function<int(int, int)> Operate;
    function<int(int, int)> OperateNode;

    ReRootingSolver(int nodeCount, vector<pair<int, int>>& edges, int identity,
                    function<int(int, int)> operate, function<int(int, int)> operateNode) {
        NodeCount = nodeCount;
        Identity = identity;
        Operate = operate;
        OperateNode = operateNode;

        Adjacents.resize(nodeCount);
        IndexForAdjacents.resize(nodeCount);
        for (auto& e : edges) {
            Adjacents[e.first].push_back(e.second);
            Adjacents[e.second].push_back(e.first);
        }

        DP.resize(nodeCount);
        Res.resize(nodeCount);
        for (int i = 0; i < nodeCount; i++) {
            DP[i].resize(Adjacents[i].size());
        }

        if (NodeCount > 1) {
            Initialize();
        } else {
            Res[0] = OperateNode(Identity, 0);
        }
    }

    int Query(int node) {
        return Res[node];
    }

private:
    void Initialize() {
        vector<int> parents(NodeCount, -1);
        vector<int> order(NodeCount);
        int index = 0;
        stack<int> stack;
        stack.push(0);
        parents[0] = -1;

        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            order[index++] = node;
            for (int adjacent : Adjacents[node]) {
                if (adjacent == parents[node]) continue;
                stack.push(adjacent);
                parents[adjacent] = node;
            }
        }

        for (int i = NodeCount - 1; i >= 1; i--) {
            int node = order[i];
            int parent = parents[node];
            int accum = Identity;
            int parentIndex = -1;
            for (int j = 0; j < Adjacents[node].size(); j++) {
                if (Adjacents[node][j] == parent) {
                    parentIndex = j;
                    continue;
                }
                accum = Operate(accum, DP[node][j]);
            }
            DP[parent][IndexForAdjacents[node][parentIndex]] = OperateNode(accum, node);
        }

        for (int i = 0; i < NodeCount; i++) {
            int node = order[i];
            int accum = Identity;
            vector<int> accumsFromTail(Adjacents[node].size(), Identity);
            for (int j = accumsFromTail.size() - 1; j >= 1; j--) {
                accumsFromTail[j - 1] = Operate(DP[node][j], accumsFromTail[j]);
            }
            for (int j = 0; j < accumsFromTail.size(); j++) {
                DP[Adjacents[node][j]][IndexForAdjacents[node][j]] = OperateNode(Operate(accum, accumsFromTail[j]), node);
                accum = Operate(accum, DP[node][j]);
            }
            Res[node] = OperateNode(accum, node);
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        edges[i] = {x, y};
    }

    auto f = [&](int x, int y) { return (1LL * x * y) % m; };
    auto g = [&](int v, int p) { return v + 1; };
    ReRootingSolver solver(n, edges, 1, f, g);
    for (int i = 0; i < n; i++) {
        cout << solver.Query(i) - 1 << endl;
    }

    return 0;
}

// <END-OF-CODE>
