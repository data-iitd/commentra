#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
#include <cassert>

using namespace std;

// Constants
const int MOD = 1000000000 + 7;
const int INF_INT64 = numeric_limits<int64_t>::max();
const int NIL = -1;

// Type alias for integers used in the ReRootingSolver
using T = int;

// ReRootingSolver struct for solving the re-rooting problem
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

    ReRootingSolver(int nodeCount, const vector<pair<int, int>>& edges, T identity,
                    function<T(T, T)> operate, function<T(T, int)> operateNode)
        : NodeCount(nodeCount), Identity(identity), Operate(operate), OperateNode(operateNode) {
        Adjacents.resize(nodeCount);
        IndexForAdjacents.resize(nodeCount);
        for (const auto& e : edges) {
            int u = e.first, v = e.second;
            IndexForAdjacents[u].push_back(Adjacents[v].size());
            IndexForAdjacents[v].push_back(Adjacents[u].size());
            Adjacents[u].push_back(v);
            Adjacents[v].push_back(u);
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

    T Query(int node) {
        return Res[node];
    }

private:
    void Initialize() {
        vector<int> parents(NodeCount, -1);
        vector<int> order(NodeCount);
        int index = 0;
        vector<int> stack = {0};
        parents[0] = -1;

        // InitOrderedTree
        while (!stack.empty()) {
            int node = stack.back();
            stack.pop_back();
            order[index++] = node;
            for (int adjacent : Adjacents[node]) {
                if (adjacent == parents[node]) continue;
                stack.push_back(adjacent);
                parents[adjacent] = node;
            }
        }

        // fromLeaf
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
        }

        // toLeaf
        for (int i = 0; i < order.size(); i++) {
            int node = order[i];
            T accum = Identity;
            vector<T> accumsFromTail(Adjacents[node].size(), Identity);
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

// Main function to execute the program
int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--; // Convert to 0-based index
        edges.emplace_back(x, y);
    }

    // Define the operations for the ReRootingSolver
    auto f = [](T x, T y) { return (int64_t(x) * y) % m; };
    auto g = [](T v, int p) { return v + 1; };

    // Initialize and use the ReRootingSolver to compute the results
    ReRootingSolver s(n, edges, 1, f, g);
    for (int i = 0; i < n; i++) {
        cout << s.Query(i) - 1 << endl;
    }

    return 0;
}

// <END-OF-CODE>
