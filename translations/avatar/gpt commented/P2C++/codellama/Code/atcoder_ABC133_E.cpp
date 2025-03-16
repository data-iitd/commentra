#include <bits/stdc++.h>
using namespace std;

// Define a graph using a vector of vectors to store adjacency lists
vector<vector<int>> graph;

// Define a recursive function to perform depth-first search (DFS) and count valid colorings
int dfs(int fro, int to, int f) {
    int caseNum = f;  // Initialize case number with the current color
    int colorNum = K - 1;  // Determine the number of available colors for the next node
    
    // Iterate through all adjacent nodes in the graph
    for (int u : graph[fro]) {
        if (u == to)  // Skip the node we came from to avoid cycles
            continue;
        int pat = dfs(u, fro, colorNum);  // Recursively call DFS for the adjacent node
        if (pat == 0)  // If no valid coloring is found, break out
            caseNum = 0;
        else
            caseNum = (caseNum * pat) % mod;  // Update the case number with the valid patterns found
        colorNum--;  // Decrease the available colors for the next node
    }
    
    return caseNum;  // Return the total valid colorings found
}

int main() {
    int N, K;  // Define the number of nodes (N) and the number of colors (K)
    cin >> N >> K;  // Read the number of nodes (N) and the number of colors (K) from input
    
    // Build the graph by reading N-1 edges
    graph.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;  // Read each edge
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);  // Add edge from a to b (0-indexed)
        graph[b - 1].push_back(a - 1);  // Add edge from b to a (0-indexed)
    }
    
    int mod = 1e9 + 7;  // Define a modulus for the result to prevent overflow
    
    // Start the DFS from the root node (0) with no parent (-1) and K colors
    int ans = dfs(0, -1, K);
    
    // Print the final answer which is the number of valid colorings
    cout << ans << endl;
    
    return 0;
}

