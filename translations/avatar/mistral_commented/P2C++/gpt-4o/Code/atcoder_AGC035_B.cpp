#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    // Take input number of vertices N and number of edges M
    int N, M;
    cin >> N >> M;

    // Initialize empty sets for each vertex representing its adjacent vertices
    vector<set<int>> edges(N);

    // Initialize degree array to keep track of number of edges for each vertex
    vector<int> degs(N, 0);

    // Initialize parity array to keep track of parity of each vertex
    vector<int> parity(N, 0);

    // Initialize flag array to keep track of visited vertices
    vector<bool> flag(N, false);

    // Read edges from input and add them to their respective sets and update their degrees
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        // Add edge between vertices a and b in both their sets
        edges[a - 1].insert(b - 1);
        edges[b - 1].insert(a - 1);
        // Update degrees of both vertices
        degs[a - 1]++;
        degs[b - 1]++;
    }

    // Check if number of edges is even, if not print -1 and exit
    if (M % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    // Initialize priority queue to store vertices based on their degrees
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    // Iterate through all vertices and add them to Q based on their degrees
    for (int i = 0; i < N; i++) {
        Q.push({degs[i], i});
    }

    // Iterate through Q until it is empty
    while (!Q.empty()) {
        // Get vertex with minimum degree from Q
        auto [d, u] = Q.top();
        Q.pop();
        // Skip if vertex is already visited
        if (flag[u]) {
            continue;
        }
        // Mark vertex as visited
        flag[u] = true;
        // Iterate through all adjacent vertices and print their edges and update their parity
        for (auto v : edges[u]) {
            // Skip if vertex is already visited
            if (flag[v]) {
                continue;
            }
            // Print edge and update parity of both vertices
            if (parity[u] != 0) {
                cout << u + 1 << " " << v + 1 << endl;
                parity[u] = 1 - parity[u];
            } else {
                cout << v + 1 << " " << u + 1 << endl;
                parity[v] = 1 - parity[v];
            }
            // Decrease degree of adjacent vertex and add it to Q
            degs[v]--;
            Q.push({degs[v], v});
        }
    }

    return 0;
}
// <END-OF-CODE>
