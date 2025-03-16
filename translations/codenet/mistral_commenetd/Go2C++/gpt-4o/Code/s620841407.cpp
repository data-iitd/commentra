#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000 + 7;

using T = int;

class ReRootingSolver {
public:
    int NodeCount;
    vector<vector<int>> Adjacents;
    vector<vector<int>> IndexForAdjacents;
    vector<T> Res;
    vector<vector<T>> DP;
    T Identity;
    function<T(T, T)> Operate;
    function<T(T, int)> OperateNode;

    ReRootingSolver(int nodeCount, vector<vector<int>>& edges, T identity,
                    function<T(T, T)> operate, function<T(T, int)> operateNode) {
        NodeCount = nodeCount;
        Identity = identity;
        Operate = operate;
        OperateNode = operateNode;

        Adjacents.resize(nodeCount);
        IndexForAdjacents.resize(nodeCount);
        for (auto& e : edges) {
            IndexForAdjacents[e[0]].push_back(Adjacents[e[1]].size());
            IndexForAdjacents[e[1]].push_back(Adjacents[e[0]].size());
            Adjacents[e[0]].push_back(e[1]);
            Adjacents[e[1]].push_back(e[0]);
        }

        DP.resize(nodeCount, vector<T>(0));
        Res.resize(nodeCount, Identity);
        for (int i = 0; i < nodeCount; i++) {
            DP[i].resize(Adjacents[i].size());
        }

        if (NodeCount > 1) {
            Initialize();
        } else {
            Res[0] = OperateNode(Identity, 0);
        }
    }

    T Query(int node) {
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
            for (int i = 0; i < Adjacents[node].size(); i++) {
                int adjacent = Adjacents[node][i];
                if (adjacent == parents[node]) continue;
                stack.push(adjacent);
                parents[adjacent] = node;
            }
        }

        for (int i = order.size() - 1; i >= 1; i--) {
            int node = order[i];
            int parent = parents[node];

            T accum = Identity;
            int parentIndex = -1;
            for (int j = 0; j < Adjacents[node].size(); j++) {
                if (Adjacents[node][j] == parent) {
                    parentIndex = j;
                    continue;
                }
                accum = Operate(accum, DP[node][j]);
            }
            DP[parent][IndexForAdjacents[node][parentIndex]] = OperateNode(accum, node);
            accum = Operate(accum, DP[node][j]);
            DP[node][j] = accum;
        }

        for (int i = 0; i < order.size(); i++) {
            int node = order[i];
            T accum = Identity;
            vector<T> accumsFromTail(Adyacents[node].size(), Identity);
            accumsFromTail.back() = Identity;
            for (int j = accumsFromTail.size() - 1; j >= 1; j--) {
                accumsFromTail[j - 1] = Operate(DP[node][j], accumsFromTail[j]);
            }
            for (int j = 0; j < accumsFromTail.size(); j++) {
                DP[Adyacents[node][j]][IndexForAdjacents[node][j]] = OperateNode(Operate(accum, accumsFromTail[j]), node);
                accum = Operate(accum, DP[node][j]);
            }
            Res[node] = OperateNode(accum, node);
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        edges.push_back({x, y});
    }

    auto f = [](T x, T y) { return (1LL * x * y) % m; };
    auto g = [](T v, int p) { return v + 1; };
    ReRootingSolver s(n, edges, 1, f, g);

    for (int i = 0; i < n; i++) {
        cout << s.Query(i) - 1 << endl;
    }

    return 0;
}

// <END-OF-CODE>
