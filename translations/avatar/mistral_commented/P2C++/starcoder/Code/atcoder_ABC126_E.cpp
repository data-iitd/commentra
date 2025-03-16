#include <bits/stdc++.h>

using namespace std;

// Define constant value for INF
const long long INF = 1000000000000000000;

// Define a custom input function
long long input() {
    long long x;
    cin >> x;
    return x;
}

// Define the main function
int main() {
    // Read input values for N and M
    long long N, M;
    cin >> N >> M;

    // Initialize an empty list for edge
    vector<vector<long long>> edge(N);

    // Read edges and add them to the edge list
    for (long long i = 0; i < M; i++) {
        long long X, Y, Z;
        cin >> X >> Y >> Z;
        edge[X - 1].push_back(Y - 1);
        edge[Y - 1].push_back(X - 1);
    }

    // Initialize a list of boolean values for used nodes
    vector<bool> used(N, false);

    // Initialize a variable for answer
    long long ans = 0;

    // Iterate through all nodes
    for (long long i = 0; i < N; i++) {
        // If the current node is not used
        if (!used[i]) {
            // Increment the answer
            ans++;
            // Initialize a queue for DFS traversal
            queue<long long> queue;
            // Add the current node to the queue
            queue.push(i);
            // Traverse through the graph using DFS
            while (!queue.empty()) {
                // Get the next node from the queue
                long long node = queue.front();
                queue.pop();
                // Mark the current node as used
                used[node] = true;
                // Traverse through the neighbors of the current node
                for (long long nextnode : edge[node]) {
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
}

