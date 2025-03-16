#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define inp(x) cin >> x
#define inpl(x) for(int i = 0; i < x.size(); i++) cin >> x[i]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, ta, ao;
    cin >> n >> ta >> ao;

    // Adjust indices to be zero-based
    ta--;
    ao--;

    // Initialize the graph as a list of lists, each representing adjacency list of a node
    vector<vector<int>> g(n);

    // Read edges to construct the graph
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);  // Append the zero-based index of the neighbor
        g[b - 1].push_back(a - 1);  // Append the zero-based index of the neighbor
    }

    // Initialize distance arrays to -1, will be populated during BFS
    vector<int> ta_dist(n, -1);
    vector<int> ao_dist(n, -1);

    // Breadth-First Search (BFS) function to compute distances from Ta
    auto ta_bfs = [&](int start) {
        queue<int> q;
        q.push(start);
        ta_dist[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int v : g[node]) {
                if (ta_dist[v] != -1) {  // If already visited, skip
                    continue;
                }
                ta_dist[v] = ta_dist[node] + 1;  // Update distance
                q.push(v);  // Push the neighbor to the queue
            }
        }
    };

    // Breadth-First Search (BFS) function to compute distances from Ao
    auto ao_bfs = [&](int start) {
        queue<int> q;
        q.push(start);
        ao_dist[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int v : g[node]) {
                if (ao_dist[v] != -1) {  // If already visited, skip
                    continue;
                }
                ao_dist[v] = ao_dist[node] + 1;  // Update distance
                q.push(v);  // Push the neighbor to the queue
            }
        }
    };

    // Start BFS from Ao to compute distances
    ao_bfs(ao);

    // Start BFS from Ta to compute distances
    ta_bfs(ta);

    // Initialize result variable
    int res = 0;

    // Iterate over all nodes to find the maximum distance where Ta's distance is less than or equal to Ao's distance
    for (int i = 0; i < n; i++) {
        if (ta_dist[i] > ao_dist[i]) {  // Skip if Ta's distance is greater
            continue;
        }
        res = max(res, ao_dist[i]);  // Update result with the maximum distance
    }

    // Print the result, which is the maximum distance minus one
    cout << res - 1 << '\n';

    return 0;
}
