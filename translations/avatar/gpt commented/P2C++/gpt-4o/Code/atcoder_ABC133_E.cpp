#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;  // Define a modulus for the result to prevent overflow

// Initialize a graph using an unordered_map to store adjacency lists
unordered_map<int, vector<int>> graph;

// Define a recursive function to perform depth-first search (DFS) and count valid colorings
long long dfs(int fro, int to, int f) {
    long long caseNum = f;  // Initialize case number with the current color
    int colorNum = (f == 1) ? (K - 1) : (K - 2);  // Determine the number of available colors for the next node

    // Iterate through all adjacent nodes in the graph
    for (int u : graph[fro]) {
        if (u == to) {  // Skip the node we came from to avoid cycles
            continue;
        }
        long long pat = dfs(u, fro, colorNum);  // Recursively call DFS for the adjacent node
        if (pat == 0) {  // If no valid coloring is found, break out
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % MOD;  // Update the case number with the valid patterns found
        colorNum--;  // Decrease the available colors for the next node
    }

    return caseNum;  // Return the total valid colorings found
}

int main() {
    int N, K;
    cin >> N >> K;  // Read the number of nodes (N) and the number of colors (K)

    // Build the graph by reading N-1 edges
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;  // Read each edge
        graph[a - 1].push_back(b - 1);  // Add edge from a to b (0-indexed)
        graph[b - 1].push_back(a - 1);  // Add edge from b to a (0-indexed)
    }

    // Start the DFS from the root node (0) with no parent (-1) and K colors
    long long ans = dfs(0, -1, K);

    // Print the final answer which is the number of valid colorings
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
