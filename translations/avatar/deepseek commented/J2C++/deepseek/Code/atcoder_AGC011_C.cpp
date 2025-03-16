#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cstring>

class Main {
public:
    std::vector<int> graph[100005]; // Adjacency list to represent the graph
    bool visited[100005]; // Array to keep track of visited nodes
    int color[100005]; // Array to store colors for bipartite check
    long one; // Counter for components with exactly one node
    long bipartite; // Counter for bipartite components
    long count; // Counter for total number of connected components
    bool mujun; // Flag to check for non-bipartite conditions

    // Depth-first search method to color nodes and check for bipartiteness
    int dfs(int a, int c) {
        if (visited[a]) { // If node is already visited
            if (color[a] >= 0 && color[a] != c) mujun = true; // Check if color conflict and set mujun flag
            return 0; // Return 0 as we don't want to count this node again
        }
        visited[a] = true; // Mark node as visited
        color[a] = c; // Assign color to the node
        int total = 1; // Initialize total count for this component
        for (int b : graph[a]) { // Iterate through neighbors
            total += dfs(b, 1 - c); // Recursively call dfs and accumulate total
        }
        return total; // Return total count for this component
    }

    // Main method to execute the program
    void run() {
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            graph[u].push_back(v); // Add edge u -> v
            graph[v].push_back(u); // Add edge v -> u
        }
        std::memset(visited, false, sizeof(visited)); // Initialize visited array
        std::memset(color, -1, sizeof(color)); // Initialize color array
        one = 0; // Initialize one counter
        bipartite = 0; // Initialize bipartite counter
        count = 0; // Initialize component counter
        for (int i = 1; i <= n; ++i) { // Iterate through all nodes
            if (visited[i]) continue; // Skip if already visited
            count++; // Increment component count
            mujun = false; // Reset mujun flag
            int kind = dfs(i, 0); // Perform DFS and get component size
            if (kind == 1) one++; // If component has exactly one node, increment one counter
            else if (!mujun) bipartite++; // If component is bipartite, increment bipartite counter
        }
        long total = one * (2 * n - one) + (count - one) * (count - one) + bipartite * bipartite; // Calculate total for all components
        std::cout << total << std::endl; // Print the total number of valid configurations
    }
};

int main() {
    Main main;
    main.run();
    return 0;
}
