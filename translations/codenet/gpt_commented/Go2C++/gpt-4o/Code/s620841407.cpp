#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000 + 7; // Modulus for calculations

// Type definition for generic operations
using T = int;

// Structure for the re-rooting solver
class ReRootingSolver {
public:
    int NodeCount; // Number of nodes
    vector<vector<int>> Adjacents; // Adjacency list
    vector<vector<int>> IndexForAdjacents; // Index mapping for adjacency
    vector<T> Res; // Result array
    vector<vector<T>> DP; // Dynamic programming table

    T Identity; // Identity element for operations
    function<T(T, T)> Operate; // Operation function
    function<T(T, int)> OperateNode; // Node operation function

    ReRootingSolver(int nodeCount, vector<pair<int, int>>& edges, T identity,
                    function<T(T, T)> operate, function<T(T, int)> operateNode) {
        NodeCount = nodeCount;
        Identity = identity;
        Operate = operate;
        OperateNode = operateNode;

        Adjacents.resize(NodeCount);
        IndexForAdjacents.resize(NodeCount);
        for (auto& e : edges) {
            int x = e.first, y = e.second;
            Adjacents[x].push_back(y);
            Adjacents[y].push_back(x);
        }

        DP.resize(NodeCount);
        Res.resize(NodeCount);
        for (int i = 0; i < NodeCount; i++) {
            DP[i].resize(Adjacents[i].size());
        }

        if (NodeCount > 1) {
            Initialize();
        } else {
            Res[0] = OperateNode(Identity, 0);
        }
    }

    T Query(int node) {
        return Res[node]; // Return the result for the queried node
    }

private:
    void Initialize() {
        vector<int> parents(NodeCount, -1);
        vector<int> order(NodeCount);
        int index = 0;
        stack<int> stack;
        stack.push(0); // Start from the root node

        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            order[index++] = node; // Record the order of nodes
            for (int adjacent : Adjacents[node]) {
                if (adjacent == parents[node]) continue; // Skip the parent node
                stack.push(adjacent); // Add child to the stack
                parents[adjacent] = node; // Set parent
            }
        }

        // Process nodes from leaves to root
        for (int i = order.size() - 1; i >= 1; i--) {
            int node = order[i];
            int parent = parents[node];

            T accum = Identity; // Initialize accumulator
            int parentIndex = -1;
            for (int j = 0; j < Adjacents[node].size(); j++) {
                if (Adjacents[node][j] == parent) {
                    parentIndex = j; // Find index of parent
                    continue;
                }
                accum = Operate(accum, DP[node][j]); // Accumulate results from children
            }
            DP[parent][IndexForAdjacents[node][parentIndex]] = OperateNode(accum, node); // Update DP for parent
        }

        // Process nodes from root to leaves
        for (int i = 0; i < order.size(); i++) {
            int node = order[i];
            T accum = Identity; // Initialize accumulator
            vector<T> accumsFromTail(Adjacents[node].size(), Identity); // Initialize tail accumulator
            for (int j = accumsFromTail.size() - 1; j >= 1; j--) {
                accumsFromTail[j - 1] = Operate(DP[node][j], accumsFromTail[j]); // Accumulate results from tail
            }
            for (int j = 0; j < accumsFromTail.size(); j++) {
                // Update DP for adjacent nodes
                DP[Adyacents[node][j]][IndexForAdjacents[node][j]] = OperateNode(Operate(accum, accumsFromTail[j]), node);
                accum = Operate(accum, DP[node][j]); // Update accumulator
            }
            Res[node] = OperateNode(accum, node); // Store result for the node
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m; // Read the number of nodes and edges
    vector<pair<int, int>> edges(n - 1); // Edges list
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y; // Read each edge
        x--; y--; // Convert to zero-based index
        edges[i] = {x, y}; // Store edge
    }

    // Define operations for the re-rooting solver
    auto f = [](T x, T y) { return (1LL * x * y) % m; }; // Multiplication operation
    auto g = [](T v, int p) { return v + 1; }; // Increment operation

    // Create a new re-rooting solver instance
    ReRootingSolver s(n, edges, 1, f, g);
    // Query results for each node and print them
    for (int i = 0; i < n; i++) {
        cout << s.Query(i) - 1 << endl; // Output the result for each node
    }

    return 0;
}

// <END-OF-CODE>
