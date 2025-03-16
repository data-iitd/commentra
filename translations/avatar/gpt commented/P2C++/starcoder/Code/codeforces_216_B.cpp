#include <bits/stdc++.h>
using namespace std;

// Reads a line of input, splits it into components, and converts them to integers
vector<int> readInts() {
    string line;
    getline(cin, line);
    vector<int> ret;
    istringstream iss(line);
    for (int x; iss >> x;) {
        ret.push_back(x);
        if (iss.peek() =='')
            iss.ignore();
    }
    return ret;
}

// Performs a depth-first search (DFS) on the graph 'g' starting from node 'i'
//'seen' keeps track of visited nodes to avoid cycles
pair<int, int> dfs(const vector<vector<int>> &g, set<int> &seen, int i) {
    if (i in seen) {
        // If the node has already been visited, return 0 nodes and 0 edges
        return {0, 0};
    }
    seen.insert(i);  // Mark the current node as seen
    int nodes = 1, edges = g[i].size();  // Count the current node
    for (int j : g[i]) {
        // Recursively visit all adjacent nodes
        auto [x, y] = dfs(g, seen, j);
        nodes += x;  // Accumulate the number of nodes found
        edges += y;  // Accumulate the number of edges found
    }
    return {nodes, edges};  // Return the total count of nodes and edges
}

// Main function to solve the problem
int main() {
    int n, m;
    cin >> n >> m;  // Read the number of nodes (n) and edges (m)
    vector<vector<int>> g(n + 1);  // Initialize the graph as a 2D array
    set<int> seen;  // Initialize a set to keep track of seen nodes
    for (int i = 1; i <= m; i++) {
        // Read each edge and add it to the graph (undirected)
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;  // Initialize the answer counter
    for (int i = 1; i <= n; i++) {
        // Iterate through each node to find connected components
        if (i not in seen) {
            // If the node has not been seen, perform DFS
            auto [nodes, edges] = dfs(g, seen, i);
            // Check the conditions for counting valid components
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans++;  // Increment the answer if conditions are met
        }
    }
    if ((n - ans) % 2 == 1) {
        // Adjust the answer if the remaining nodes are odd
        ans++;
    }
    cout << ans << endl;  // Output the final answer
    return 0;
}

