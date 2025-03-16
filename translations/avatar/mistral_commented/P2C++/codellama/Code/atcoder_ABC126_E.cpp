#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// Define constant value for INF
const int INF = 1000000000;

// Define a custom input function
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Define the main function
int main() {
    // Read input values for N and M
    int N, M;
    cin >> N >> M;

    // Initialize an empty list for edge
    vector<vector<int>> edge(N);

    // Read edges and add them to the edge list
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        edge[X - 1].push_back(Y - 1);
        edge[Y - 1].push_back(X - 1);
    }

    // Initialize a list of boolean values for used nodes
    vector<bool> used(N, false);

    // Initialize a variable for answer
    int ans = 0;

    // Iterate through all nodes
    for (int i = 0; i < N; i++) {
        // If the current node is not used
        if (!used[i]) {
            // Increment the answer
            ans++;
            // Initialize a queue for DFS traversal
            queue<int> queue;
            // Add the current node to the queue
            queue.push(i);
            // Traverse through the graph using DFS
            while (!queue.empty()) {
                // Get the next node from the queue
                int node = queue.front();
                // Mark the current node as used
                used[node] = true;
                // Traverse through the neighbors of the current node
                for (int nextnode : edge[node]) {
                    // If the neighbor is not used
                    if (!used[nextnode]) {
                        // Add the neighbor to the queue
                        queue.push(nextnode);
                    }
                }
                // Remove the current node from the queue
                queue.pop();
            }
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// 