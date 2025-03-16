#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e18

// Custom input function
string input() {
    string line;
    getline(cin, line);
    return line;
}

// Main function
void main() {
    // Read input values for N and M
    int N, M;
    sscanf(input().c_str(), "%d %d", &N, &M);

    // Initialize an empty vector for edge
    vector<vector<int>> edge(N);

    // Read edges and add them to the edge vector
    for (int i = 0; i < M; ++i) {
        int X, Y, Z;
        sscanf(input().c_str(), "%d %d %d", &X, &Y, &Z);
        --X; --Y;
        edge[X].push_back(Y);
        edge[Y].push_back(X);
    }

    // Initialize a vector of boolean values for used nodes
    vector<bool> used(N, false);

    // Initialize a variable for answer
    int ans = 0;

    // Iterate through all nodes
    for (int i = 0; i < N; ++i) {
        // If the current node is not used
        if (!used[i]) {
            // Increment the answer
            ++ans;
            // Initialize a queue for BFS traversal
            queue<int> queue;
            // Add the current node to the queue
            queue.push(i);
            // Traverse through the graph using BFS
            while (!queue.empty()) {
                // Get the next node from the queue
                int node = queue.front();
                queue.pop();
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
            }
        }
    }

    // Print the answer
    cout << ans << endl;
}

// Run the main function if the script is run directly
int main() {
    main();
    return 0;
}
