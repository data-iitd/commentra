#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define a constant for infinity
const long long INF = 1e18;

// Function to read input
inline void input(int &x) {
    cin >> x;
}

int main() {
    // Read the number of nodes (N) and edges (M)
    int N, M;
    input(N);
    input(M);
    
    // Initialize an adjacency list to represent the graph
    vector<vector<int>> edge(N);
    
    // Read each edge and populate the adjacency list
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        input(X); input(Y); input(Z);
        X--; Y--; // Convert to 0-based index
        edge[X].push_back(Y);
        edge[Y].push_back(X);
    }
    
    // Array to track visited nodes
    vector<bool> used(N, false);
    
    // Variable to count the number of connected components
    int ans = 0;
    
    // Iterate through each node to find connected components
    for (int i = 0; i < N; i++) {
        if (!used[i]) {  // If the node has not been visited
            ans++;  // Increment the count of connected components
            queue<int> q;  // Initialize a queue for BFS
            q.push(i);  // Start BFS from the current node
            
            // Perform BFS to mark all reachable nodes from the current node
            while (!q.empty()) {
                int node = q.front();  // Get the front node
                q.pop();  // Dequeue the node
                used[node] = true;  // Mark the node as visited
                
                // Explore all adjacent nodes
                for (int nextnode : edge[node]) {
                    if (!used[nextnode]) {  // If the adjacent node has not been visited
                        q.push(nextnode);  // Enqueue the adjacent node
                    }
                }
            }
        }
    }
    
    // Output the number of connected components found
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
