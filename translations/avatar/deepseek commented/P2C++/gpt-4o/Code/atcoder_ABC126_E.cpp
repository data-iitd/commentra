#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1e18;  // Define a constant for infinity

void solve() {
    int N, M;
    cin >> N >> M;  // Read the number of nodes and edges
    vector<vector<int>> edge(N);  // Initialize the edge list to represent the graph

    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;  // Read each edge
        X--; Y--;  // Adjust indices to be zero-based
        edge[X].push_back(Y);  // Add edge in both directions for an undirected graph
        edge[Y].push_back(X);
    }

    vector<bool> used(N, false);  // Initialize a list to track visited nodes
    int ans = 0;  // Initialize the counter for connected components

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans++;  // Increment the counter for each new connected component found
            queue<int> q;  // Initialize a queue for BFS
            q.push(i);  // Start BFS from the current node

            while (!q.empty()) {
                int node = q.front();  // Get the next node from the queue
                q.pop();  // Remove it from the queue
                used[node] = true;  // Mark the node as visited

                for (int nextnode : edge[node]) {
                    if (!used[nextnode]) {
                        q.push(nextnode);  // Add unvisited neighbors to the queue
                    }
                }
            }
        }
    }

    cout << ans << endl;  // Output the total number of connected components
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  // Optimize input/output
    solve();  // Call the solve function to execute the program
    return 0;
}

// <END-OF-CODE>
