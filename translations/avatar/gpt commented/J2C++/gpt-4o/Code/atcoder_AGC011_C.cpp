#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Main {
    // Adjacency list representation of the graph
    vector<int> graph[100000]; 
    // Array to track visited nodes
    bool visited[100000]; 
    // Array to store colors of nodes for bipartite checking
    int color[100000]; 
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
            if (color[a] >= 0 && color[a] != c) mujun = true; 
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

public:
    // Main execution method for the program
    void run() {
        int n, m;
        cin >> n >> m; // Read number of nodes and edges

        // Initialize visited and color arrays
        memset(visited, false, sizeof(visited)); 
        memset(color, -1, sizeof(color)); // Set all colors to -1 (uncolored)

        // Initialize counters
        one = 0; 
        bipartite = 0; 
        count = 0; 

        // Read edges and populate the graph
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v; // Read first and second node of the edge
            u--; v--; // Convert to 0-based index
            graph[u].push_back(v); // Add edge to the graph
            graph[v].push_back(u); // Add edge in both directions
        }

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
};

// Main method to start the program
int main() {
    Main mainObj;
    mainObj.run();
    return 0;
}

// <END-OF-CODE>
