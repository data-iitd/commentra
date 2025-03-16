#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cstring>
#include <climits>

using namespace std;

#define all(x) x.begin(),x.end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int ALPHABET_NUM = 26;
const long long INF_INT64 = 1e18;
const int INF_INT32 = 1e9;
const short INF_INT16 = 1e4;
const char INF_CHAR = 127;
const double INF_DOUBLE = 1e30;
const long double INF_LONG_DOUBLE = 1e30;
const string INF_STRING = "z";

// Constants used throughout the program
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

// Initializes the input reader and output writer
void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Global variables
int n, m;
vector<vector<int>> edges;

// Main function to execute the program
int main() {
    init();
    // Read the number of nodes and edges
    cin >> n >> m;

    // Construct the graph from the edges
    edges.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    // Define the operations for the ReRootingSolver
    auto f = [](int x, int y) { return x * y % m; };
    auto g = [](int v, int p) { return v + 1; };

    // Initialize and use the ReRootingSolver to compute the results
    ReRootingSolver s(n, edges, 1, f, g);
    for (int i = 0; i < n; i++) {
        cout << s.Query(i) - 1 << endl;
    }

    return 0;
}

// T is a type alias for integers used in the ReRootingSolver
using T = int;

// ReRootingSolver struct for solving the re-rooting problem
struct ReRootingSolver {
    int NodeCount;

    vector<vector<int>> Adjacents;
    vector<vector<int>> IndexForAdjacents;

    vector<T> Res;
    vector<vector<T>> DP;

    T Identity;
    function<T(T, T)> Operate;
    function<T(T, int)> OperateNode;

    ReRootingSolver(
        int nodeCount, const vector<vector<int>>& edges, T identity,
        function<T(T, T)> operate, function<T(T, int)> operateNode
    ) : NodeCount(nodeCount), Identity(identity), Operate(operate), OperateNode(operateNode) {
        Adjacents.resize(nodeCount);
        IndexForAdjacents.resize(nodeCount);
        for (const auto& e : edges) {
            IndexForAdjacents[e[0]].push_back(Adjacents[e[1]].size());
            IndexForAdjacents[e[1]].push_back(Adjacents[e[0]].size());
            Adjacents[e[0]].push_back(e[1]);
            Adjacents[e[1]].push_back(e[0]);
        }

        DP.resize(Adjacents.size());
        Res.resize(Adjacents.size());

        for (int i = 0; i < Adjacents.size(); i++) {
            DP[i].resize(Adjacents[i].size());
        }

        if (NodeCount > 1) {
            Initialize();
        } else {
            Res[0] = OperateNode(Identity, 0);
        }
    }

    // Query returns the result for a given node
    T Query(int node) {
        return Res[node];
    }

    // Initialize computes the dynamic programming values
    void Initialize() {
        vector<int> parents(NodeCount), order(NodeCount);

        // InitOrderedTree initializes the tree in a way that is useful for traversal
        int index = 0;
        stack<int> stack;
        stack.push(0);
        parents[0] = -1;
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            order[index] = node;
            index++;
            for (int adjacent : Adjacents[node]) {
                if (adjacent == parents[node]) {
                    continue;
                }
                stack.push(adjacent);
                parents[adjacent] = node;
            }
        }

        // fromLeaf computes values starting from the leaves
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

        // toLeaf computes values propagating from leaves to the root
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
