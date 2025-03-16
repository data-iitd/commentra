
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a directed edge with a cost
struct Edge {
    int to;  // Destination node
    int cost;  // Cost of the edge
};

int main() {
    int n;  // Number of nodes
    cin >> n;

    vector<vector<Edge>> graph(n);  // Adjacency list representation of the graph
    vector<int> dist(n, numeric_limits<int>::max());  // Array to store the shortest distances

    // Read edges for each node
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v, c;
            cin >> v >> c;
            graph[u].push_back({v, c});
        }
    }

    // Initialize the source node with distance 0
    dist[0] = 0;

    // Use Dijkstra's algorithm to compute shortest paths
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});  // Push the source node with distance 0 into the priority queue

    while (!pq.empty()) {
        int u = pq.top().second;  // Get the node with the minimum distance
        pq.pop();
        for (auto& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.cost;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;  // Update the shortest distance
                pq.push({dist[v], v});  // Push the updated node into the priority queue
            }
        }
    }

    // Print the shortest distances from the source node to each node
    for (int i = 0; i < n; i++) {
        cout << i << " " << dist[i] << endl;  // Output the node index and its distance
    }

    return 0;  // Exit the program
}

// Translate the above C++ code to Java and end with comment "