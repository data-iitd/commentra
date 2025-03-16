
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> readInts() {
    // Reads a line of input, splits it into components, and converts them to integers
    vector<int> result;
    int x;
    while (cin >> x) {
        result.push_back(x);
    }
    return result;
}

void dfs(const vector<vector<int>>& g, set<int>& seen, int i, int& nodes, int& edges) {
    // Performs a depth-first search (DFS) on the graph 'g' starting from node 'i'
    //'seen' keeps track of visited nodes to avoid cycles
    if (seen.count(i)) {
        // If the node has already been visited, return 0 nodes and 0 edges
        return;
    }
    seen.insert(i);  // Mark the current node as seen
    nodes++;  // Count the current node
    edges += g[i].size();  // Count the edges connected to the current node
    for (int j : g[i]) {
        // Recursively visit all adjacent nodes
        dfs(g, seen, j, nodes, edges);
    }
}

int solve() {
    // Main function to solve the problem
    vector<int> line0;
    try {
        // Attempt to read the first line of input
        line0 = readInts();
    } catch (const exception& e) {
        // If end of input is reached, return -1 to stop processing
        return -1;
    }
    int n = line0[0], m = line0[1];  // Unpack the number of nodes (n) and edges (m)
    vector<vector<int>> g(n);  // Initialize the graph as a vector of vectors
    set<int> seen;  // Initialize a set to keep track of seen nodes
    for (int i = 0; i < n; i++) {
        // Initialize each node's adjacency list as an empty vector
        g[i] = vector<int>();
    }
    for (int i = 0; i < m; i++) {
        // Read each edge and add it to the graph (undirected)
        int a, b;
        cin >> a >> b;
        a--; b--;  // Adjust for 0-based indexing
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;  // Initialize the answer counter
    for (int i = 0; i < n; i++) {
        // Iterate through each node to find connected components
        if (!seen.count(i)) {
            // If the node has not been seen, perform DFS
            int nodes = 0, edges = 0;
            dfs(g, seen, i, nodes, edges);
            // Check the conditions for counting valid components
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans++;  // Increment the answer if conditions are met
            }
        }
    }
    if ((n - ans) % 2 == 1) {
        // Adjust the answer if the remaining nodes are odd
        ans++;
    }
    cout << ans << endl;  // Output the final answer
    return 0;  // Return 0 to indicate successful processing
}

int main() {
    // Continuously solve the problem until EOF is reached
    while (solve()!= -1) {
        // Do nothing
    }
    return 0;
}

Translate the above C++ code to Java and end with comment "