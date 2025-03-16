#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;  // Set the modulo value to prevent overflow
unordered_map<int, vector<int>> graph;  // Initialize a map to store the graph

// Define the DFS function to calculate the number of valid colorings
long long dfs(int fro, int to, int f) {
    long long caseNum = f;  // Initialize the number of valid colorings with the initial number of colors
    int colorNum = (f == K) ? K - 1 : K - 2;  // Set the number of available colors for the current node
    for (int u : graph[fro]) {
        if (u == to) {
            continue;  // Skip if the neighbor is the parent node
        }
        long long pat = dfs(u, fro, colorNum);  // Recursively call dfs for the neighbor
        if (pat == 0) {
            caseNum = 0;  // If no valid colorings, set the current number to 0
            break;  // Break out of the loop as further calculations are unnecessary
        }
        caseNum = (caseNum * pat) % MOD;  // Multiply the current number of valid colorings by the recursive result
        colorNum--;  // Decrease the number of available colors for the next node
    }
    return caseNum;  // Return the number of valid colorings for the current node
}

int main() {
    int N, K;
    cin >> N >> K;  // Read the number of nodes and the number of colors

    // Construct the graph by reading edges
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);  // Append the edge to the graph
        graph[b - 1].push_back(a - 1);  // Since the graph is undirected, append the reverse edge as well
    }

    long long ans = dfs(0, -1, K);  // Call the dfs function starting from the root node with the initial number of colors
    cout << ans << endl;  // Print the final result

    return 0;
}  // <END-OF-CODE>
