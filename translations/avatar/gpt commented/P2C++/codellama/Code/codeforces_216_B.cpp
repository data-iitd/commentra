#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

vector<int> readInts() {
    // Reads a line of input, splits it into components, and converts them to integers
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> ints;
    int temp;
    while (ss >> temp) {
        ints.push_back(temp);
    }
    return ints;
}

pair<int, int> dfs(map<int, set<int>> g, set<int> seen, int i) {
    // Performs a depth-first search (DFS) on the graph 'g' starting from node 'i'
    // 'seen' keeps track of visited nodes to avoid cycles
    if (seen.find(i) != seen.end()) {
        // If the node has already been visited, return 0 nodes and 0 edges
        return make_pair(0, 0);
    }
    seen.insert(i);  // Mark the current node as seen
    int nodes = 1;  // Count the current node
    int edges = g[i].size();  // Count the edges connected to the current node
    for (int j : g[i]) {
        // Recursively visit all adjacent nodes
        pair<int, int> xy = dfs(g, seen, j);
        nodes += xy.first;  // Accumulate the number of nodes found
        edges += xy.second;  // Accumulate the number of edges found
    }
    return make_pair(nodes, edges);  // Return the total count of nodes and edges
}

void solve() {
    // Main function to solve the problem
    vector<int> line0;
    try {
        // Attempt to read the first line of input
        line0 = readInts();
    } catch (...) {
        // If end of input is reached, return False to stop processing
        return;
    }
    int n = line0[0];  // Unpack the number of nodes (n)
    int m = line0[1];  // Unpack the number of edges (m)
    map<int, set<int>> g;  // Initialize the graph as a dictionary
    set<int> seen;  // Initialize a set to keep track of seen nodes
    for (int i = 1; i <= n; i++) {
        // Initialize each node's adjacency list as an empty set
        g[i] = set<int>();
    }
    for (int i = 0; i < m; i++) {
        // Read each edge and add it to the graph (undirected)
        vector<int> ab = readInts();
        int a = ab[0];
        int b = ab[1];
        g[a].insert(b);
        g[b].insert(a);
    }
    int ans = 0;  // Initialize the answer counter
    for (int i = 1; i <= n; i++) {
        // Iterate through each node to find connected components
        if (seen.find(i) == seen.end()) {
            // If the node has not been seen, perform DFS
            pair<int, int> nodes_edges = dfs(g, seen, i);
            // Check the conditions for counting valid components
            if (nodes_edges.first > 1 && nodes_edges.first % 2 == 1 && 2 * nodes_edges.first == nodes_edges.second) {
                ans += 1;  // Increment the answer if conditions are met
            }
        }
    }
    if ((n - ans) % 2 == 1) {
        // Adjust the answer if the remaining nodes are odd
        ans += 1;
    }
    cout << ans << endl;  // Output the final answer
}

// Continuously solve the problem until EOF is reached
while (true) {
    solve();
}

