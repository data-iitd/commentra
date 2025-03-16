
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int to, cost;
};

int dijkstra(const vector<vector<Edge>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (const Edge& e : graph[u]) {
            if (dist[e.to] > dist[u] + e.cost) {
                dist[e.to] = dist[u] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist[n - 1];
}

int main() {
    int n, u, k;
    cin >> n;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v, cost;
            cin >> v >> cost;
            graph[i].push_back({v, cost});
        }
    }
    int ans = dijkstra(graph, 0);
    cout << ans << endl;
    return 0;
}

