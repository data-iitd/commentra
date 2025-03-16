
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

using T = long long;

struct ReRootingSolver {
    int NodeCount;

    vector<vector<int>> Adjacents;
    vector<vector<int>> IndexForAdjacents;

    vector<T> Res;
    vector<vector<T>> DP;

    T Identity;
    T (*Operate)(T, T);
    T (*OperateNode)(T, int);

    ReRootingSolver(int nodeCount, vector<vector<int>> edges, T identity, T (*operate)(T, T), T (*operateNode)(T, int)) {
        NodeCount = nodeCount;
        Identity = identity;
        Operate = operate;
        OperateNode = operateNode;

        Adjacents = vector<vector<int>>(nodeCount);
        IndexForAdjacents = vector<vector<int>>(nodeCount);
        for (auto e : edges) {
            IndexForAdjacents[e[0]].push_back(Adjacents[e[1]].size());
            IndexForAdjacents[e[1]].push_back(Adjacents[e[0]].size());
            Adjacents[e[0]].push_back(e[1]);
            Adjacents[e[1]].push_back(e[0]);
        }

        DP = vector<vector<T>>(Adjacents.size());
        Res = vector<T>(Adjacents.size());

        for (int i = 0; i < Adjacents.size(); i++) {
            DP[i] = vector<T>(Adjacents[i].size());
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

    void Initialize() {
        vector<int> parents(NodeCount, -1);
        vector<int> order(NodeCount);

        // InitOrderedTree
        int index = 0;
        vector<int> stack;
        stack.push_back(0);
        parents[0] = -1;
        while (!stack.empty()) {
            int node = stack.back();
            stack.pop_back();
            order[index] = node;
            index++;
            for (int i = 0; i < Adjacents[node].size(); i++) {
                int adjacent = Adjacents[node][i];
                if (adjacent == parents[node]) {
                    continue;
                }
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
            accum = Operate(accum, DP[node][j]);
            DP[node][j] = accum;
        }

        // toLeaf
        for (int i = 0; i < order.size(); i++) {
            int node = order[i];
            T accum = Identity;
            vector<T> accumsFromTail(Adjacents[node].size());
            accumsFromTail[accumsFromTail.size() - 1] = Identity;
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
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        vector<int> e = {x, y};
        edges.push_back(e);
    }

    // Initialize the disjoint set data structure
    T (*f)(T, T) = [](T x, T y) { return T(int(x) * int(y) % m); };
    T (*g)(T, int) = [](T v, int p) { return v + 1; };
    ReRootingSolver s(n, edges, 1, f, g);

    // Query the product of subtrees for all nodes and print the result
    for (int i = 0; i < n; i++) {
        cout << s.Query(i) - 1 << endl;
    }

    return 0;
}

