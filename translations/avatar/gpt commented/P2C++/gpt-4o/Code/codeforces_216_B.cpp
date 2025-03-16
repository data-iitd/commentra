#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>

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

pair<int, int> dfs(const map<int, set<int>>& g, set<int>& seen, int i) {
    // Performs a depth-first search (DFS) on the graph 'g' starting from node 'i'
    // 'seen' keeps track of visited nodes to avoid cycles
    if (seen.count(i)) {
        // If the node has already been visited, return 0 nodes and 0 edges
        return {0, 0};
    }
    seen.insert(i);  // Mark the current node as seen
    int nodes = 1;  // Count the current node
    int edges = g.at(i).size();  // Count the edges connected to the current node
    for (int j : g.at(i)) {
        // Recursively visit all adjacent nodes
        auto [x, y] = dfs(g, seen, j);
        nodes += x;  // Accumulate the number of nodes found
        edges += y;  // Accumulate the number of edges found
    }
    return {nodes, edges};  // Return the total count of nodes and edges
}

bool solve() {
    // Main function to solve the problem
    vector<int> line0 = readInts();
    if (line0.empty()) {
        // If end of input is reached, return false to stop processing
        return false;
    }
    int n = line0[0], m = line0[1];  // Unpack the number of nodes (n) and edges (m)
    map<int, set<int>> g;  // Initialize the graph as a map
    set<int> seen;  // Initialize a set to keep track of seen nodes
    for (int i = 1; i <= n; ++i) {
        // Initialize each node's adjacency list as an empty set
        g[i] = set<int>();
    }
    for (int i = 0; i < m; ++i) {
        // Read each edge and add it to the graph (undirected)
        vector<int> edge = readInts();
        g[edge[0]].insert(edge[1]);
        g[edge[1]].insert(edge[0]);
    }
    int ans = 0;  // Initialize the answer counter
    for (int i = 1; i <= n; ++i) {
        // Iterate through each node to find connected components
        if (seen.count(i) == 0) {
            // If the node has not been seen, perform DFS
            auto [nodes, edges] = dfs(g, seen, i);
            // Check the conditions for counting valid components
            if (nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges) {
                ans += 1;  // Increment the answer if conditions are met
            }
        }
    }
    if ((n - ans) % 2 == 1) {
        // Adjust the answer if the remaining nodes are odd
        ans += 1;
    }
    cout << ans << endl;  // Output the final answer
    return true;  // Return true to indicate successful processing
}

// Continuously solve the problem until EOF is reached
int main() {
    while (solve()) {
        // Loop until solve returns false
    }
    return 0;
}

// <END-OF-CODE>
