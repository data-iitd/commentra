#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    // Read the number of nodes (N) and edges (M) from input
    int N, M;
    cin >> N >> M;

    // Initialize adjacency list for edges, degree count, parity, and visited flag
    vector<set<int>> edges(N);
    vector<int> degs(N, 0);
    vector<int> parity(N, 0);
    vector<bool> flag(N, false);

    // Read edges and populate the adjacency list and degree counts
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].insert(b - 1);  // Add edge from a to b
        edges[b - 1].insert(a - 1);  // Add edge from b to a
        degs[a - 1]++;                // Increment degree of node a
        degs[b - 1]++;                // Increment degree of node b
    }

    // If the number of edges is odd, it's impossible to pair them
    if (M % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    // Initialize a priority queue with degrees of nodes
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    for (int i = 0; i < N; ++i) {
        Q.push({degs[i], i});  // Push degree and node index to the queue
    }

    // Process the nodes in the priority queue
    while (!Q.empty()) {
        auto [d, u] = Q.top();  // Get the node with the smallest degree
        Q.pop();                // Remove it from the queue

        // If the node has already been processed, skip it
        if (flag[u]) {
            continue;
        }

        flag[u] = true;  // Mark the node as processed

        // Iterate through the neighbors of the current node
        int i = 0;
        for (int v : edges[u]) {
            edges[v].erase(u);  // Remove the edge from v to u
            // Check the parity to determine the output format
            if (parity[u] != 0 && i == 0) {
                cout << (u + 1) << " " << (v + 1) << endl;  // Print the edge in one format
                parity[u] = 1 - parity[u];  // Toggle parity for u
            } else {
                cout << (v + 1) << " " << (u + 1) << endl;  // Print the edge in the alternate format
                parity[v] = 1 - parity[v];  // Toggle parity for v
            }

            degs[v]--;  // Decrement the degree of neighbor v
            Q.push({degs[v], v});  // Push updated degree back to the queue
            i++;
        }
    }

    return 0;
}

// <END-OF-CODE>
