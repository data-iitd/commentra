#include <bits/stdc++.h>
using namespace std;

// Adjacency list representation of the graph
vector<int> graph[100001]; 
// Array to track visited nodes
bool visited[100001]; 
// Array to store colors of nodes for bipartite checking
int color[100001]; 
// Counters for specific conditions
long long one; 
long long bipartite; 
long long count; 
// Flag to check if the graph is not bipartite
bool mujun; 

// Depth-First Search (DFS) method to explore the graph
int dfs(int a, int c) {
    // If the node has already been visited
    if (visited[a]) {
        // Check for color conflict indicating the graph is not bipartite
        if (color[a] >= 0 && color[a]!= c) mujun = true; 
        return 0; 
    }
    // Mark the node as visited and assign it a color
    visited[a] = true; 
    color[a] = c; 
    int total = 1; // Count the current node

    // Recursively visit all adjacent nodes with alternate color
    for (int b : graph[a]) {
        total += dfs(b, 1 - c); 
    }
    return total; // Return the total count of nodes in this component
}

// Main execution method for the program
int main() {
    // Read number of nodes and edges
    int n, m; cin >> n >> m; 

    // Initialize the graph
    for (int i = 0; i < n; ++i) 
        graph[i].clear(); 

    // Read edges and populate the graph
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v; 
        graph[u].push_back(v); // Add edge to the graph
        graph[v].push_back(u); // Add edge in both directions
    }

    // Initialize visited and color arrays
    memset(visited, false, sizeof(visited)); 
    memset(color, -1, sizeof(color)); 

    // Initialize counters
    one = 0; 
    bipartite = 0; 
    count = 0; 

    // Iterate through all nodes to find connected components
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue; // Skip already visited nodes
        count++; // Increment component count
        mujun = false; // Reset bipartite flag
        int kind = dfs(i, 0); // Perform DFS starting from node i

        // Update counters based on the results of DFS
        if (kind == 1) one++; 
        else if (!mujun) bipartite++; 
    }

    // Calculate the total based on the counts of components
    long long total = one * (2 * n - one); 
    total += (count - one) * (count - one); 
    total += bipartite * bipartite; 

    // Output the final result
    cout << total << endl; 
}

