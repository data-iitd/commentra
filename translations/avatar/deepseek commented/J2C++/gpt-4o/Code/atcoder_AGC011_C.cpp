#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Main {
    vector<int> *graph; // Adjacency list to represent the graph
    bool *visited; // Array to keep track of visited nodes
    int *color; // Array to store colors for bipartite check
    long long one; // Counter for components with exactly one node
    long long bipartite; // Counter for bipartite components
    long long count; // Counter for total number of connected components
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

public:
    // Main method to execute the program
    void run() {
        int n, m;
        cin >> n >> m; // Read number of nodes and edges
        graph = new vector<int>[n]; // Initialize graph adjacency list
        for (int i = 0; i < m; ++i) { // Read each edge and add to graph
            int u, v;
            cin >> u >> v; // Read node u and v
            u--; v--; // Convert to 0-based index
            graph[u].push_back(v); // Add edge u -> v
            graph[v].push_back(u); // Add edge v -> u
        }
        visited = new bool[n]; // Initialize visited array
        color = new int[n]; // Initialize color array
        memset(color, -1, n * sizeof(int)); // Set all colors to -1 (uncolored)
        one = 0; // Initialize one counter
        bipartite = 0; // Initialize bipartite counter
        count = 0; // Initialize component counter
        memset(visited, false, n * sizeof(bool)); // Initialize visited array to false

        for (int i = 0; i < n; ++i) { // Iterate through all nodes
            if (visited[i]) continue; // Skip if already visited
            count++; // Increment component count
            mujun = false; // Reset mujun flag
            int kind = dfs(i, 0); // Perform DFS and get component size
            if (kind == 1) one++; // If component has exactly one node, increment one counter
            else if (!mujun) bipartite++; // If component is bipartite, increment bipartite counter
        }

        long long total = one * (2 * n - one); // Calculate total for components with exactly one node
        total += (count - one) * (count - one); // Calculate total for components with more than one node
        total += bipartite * bipartite; // Add total for bipartite components
        cout << total << endl; // Print the total number of valid configurations

        // Clean up dynamically allocated memory
        delete[] graph;
        delete[] visited;
        delete[] color;
    }
};

int main() {
    Main mainObj;
    mainObj.run(); // Start the program
    return 0;
}

// <END-OF-CODE>
