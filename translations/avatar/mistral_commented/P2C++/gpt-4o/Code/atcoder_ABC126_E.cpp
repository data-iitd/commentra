#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define constant value for INF
const long long INF = 1e18;

int main() {
    // Read input values for N and M
    int N, M;
    cin >> N >> M;

    // Initialize an empty list for edges
    vector<vector<int>> edge(N);

    // Read edges and add them to the edge list
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        edge[X - 1].push_back(Y - 1);
        edge[Y - 1].push_back(X - 1);
    }

    // Initialize a vector of boolean values for used nodes
    vector<bool> used(N, false);

    // Initialize a variable for answer
    int ans = 0;

    // Iterate through all nodes
    for (int i = 0; i < N; i++) {
        // If the current node is not used
        if (!used[i]) {
            // Increment the answer
            ans++;
            // Initialize a queue for BFS traversal
            queue<int> q;
            // Add the current node to the queue
            q.push(i);
            // Traverse through the graph using BFS
            while (!q.empty()) {
                // Get the next node from the queue
                int node = q.front();
                q.pop();
                // Mark the current node as used
                used[node] = true;
                // Traverse through the neighbors of the current node
                for (int nextnode : edge[node]) {
                    // If the neighbor is not used
                    if (!used[nextnode]) {
                        // Add the neighbor to the queue
                        q.push(nextnode);
                    }
                }
            }
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
