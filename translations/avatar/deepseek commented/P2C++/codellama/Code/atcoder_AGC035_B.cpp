#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    // Step 1: Input Reading and Initialization
    // Read the number of nodes N and the number of edges M
    int N, M;
    cin >> N >> M;

    // Initialize adjacency lists for each node
    vector<set<int>> edges(N);

    // Initialize degrees for each node
    vector<int> degs(N);

    // Initialize parity for each node
    vector<int> parity(N);

    // Initialize flag to mark visited nodes
    vector<bool> flag(N);

    // Step 2: Edge and Degree Calculation
    // Read each edge and update adjacency lists and degree lists
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].insert(b - 1);
        edges[b - 1].insert(a - 1);
        degs[a - 1]++;
        degs[b - 1]++;
    }

    // If the number of edges M is odd, print -1 and exit
    if (M % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    // Step 3: Heap Initialization
    // Initialize a heap Q with nodes based on their degrees
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    for (int i = 0; i < N; i++) {
        Q.push(make_pair(degs[i], i));
    }

    // Step 4: Main Loop
    // Process nodes from the heap
    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();

        // If the node has already been processed, skip to the next iteration
        if (flag[u]) {
            continue;
        }

        // Mark the node as processed
        flag[u] = true;

        // For each neighbor of the node, update the adjacency list and degree list
        for (int v : edges[u]) {
            edges[v].erase(u);

            // Print the edge in the required format, alternating the direction based on the parity
            if (parity[u] != 0) {
                cout << u + 1 << " " << v + 1 << endl;
                parity[u] = 1 - parity[u];
            } else {
                cout << v + 1 << " " << u + 1 << endl;
                parity[v] = 1 - parity[v];
            }

            // Update the degree and push the updated node back into the heap
            degs[v]--;
            Q.push(make_pair(degs[v], v));
        }
    }

    // Step 5: Output
    // The code prints the edges in the required format, alternating the direction based on the parity

    // 