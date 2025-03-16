#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Main {
public:
    vector<int> graph[100005]; // Adjacency list for the graph
    bool visited[100005]; // Array to track visited nodes
    int color[100005]; // Array to store colors of nodes
    long long one = 0; // Count of nodes in a single connected component
    long long bipartite = 0; // Count of bipartite connected components
    long long count = 0; // Total number of nodes in the graph
    bool mujun = false; // Flag to check for odd cycles

    void run() {
        int n, m;
        cin >> n >> m; // Read number of nodes and edges
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v; // Read edges
            graph[u - 1].push_back(v - 1); // Add edge to adjacency list
            graph[v - 1].push_back(u - 1); // Add edge to adjacency list
        }
        memset(visited, false, sizeof(visited)); // Initialize visited array
        memset(color, -1, sizeof(color)); // Initialize color array

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue; // Skip if already visited
            count++; // Increment count of components
            mujun = false; // Reset mujun flag
            int kind = dfs(i, 0); // Perform DFS
            if (kind == 1) one++; // Increment if single connected component
            else if (!mujun) bipartite++; // Increment if bipartite
        }

        long long total = one * (2 * n - one); // Calculate total edges
        total += (count - one) * (count - one); // Isolated nodes
        total += bipartite * bipartite; // Bipartite components
        cout << total << endl; // Output total edges
    }

    int dfs(int a, int c) {
        if (visited[a]) {
            if (color[a] >= 0 && color[a] != c) mujun = true; // Check for odd cycle
            return 0; // Already visited
        }
        visited[a] = true; // Mark as visited
        color[a] = c; // Set color
        int total = 1; // Initialize total nodes in component
        for (int b : graph[a]) {
            total += dfs(b, 1 - c); // Recursive DFS
        }
        return total; // Return total nodes in component
    }
};

int main() {
    Main mainObj;
    mainObj.run(); // Execute the run method
    return 0;
}

// <END-OF-CODE>
