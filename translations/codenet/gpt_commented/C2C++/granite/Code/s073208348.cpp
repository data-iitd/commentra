
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Edge {
    ll s, g, c; // start vertex, end vertex, and cost of the edge
};

struct Graph {
    int vcnt, ecnt; // number of vertices and edges
    vector<Edge> e; // array to hold edges
    vector<int> id; // array to hold index of edges for each vertex
};

bool cmp(const Edge &a, const Edge &b) {
    // Sort edges primarily by start vertex, then by end vertex
    if (a.s < b.s) return true;
    if (a.s > b.s) return false;
    return a.g < b.g;
}

int main() {
    ll n;
    cin >> n;
    Graph g;
    g.vcnt = n;
    g.ecnt = 2 * n - 2;
    g.e.resize(g.ecnt);
    g.id.resize(g.vcnt + 1);

    for (int i = 0; i < g.ecnt; i++) {
        ll x, y, c;
        cin >> x >> y >> c;
        // Add edge from x to y
        g.e[i].s = x;
        g.e[i].g = y;
        g.e[i].c = c;
        // Add edge from y to x (undirected graph)
        g.e[i + g.ecnt / 2].s = y;
        g.e[i + g.ecnt / 2].g = x;
        g.e[i + g.ecnt / 2].c = c;
    }

    sort(g.e.begin(), g.e.end(), cmp);

    int p = 0;
    // Create an index for edges for each vertex
    for (int i = 0; i < g.vcnt; i++) {
        while (p < g.ecnt && g.e[p].s < i) p++;
        g.id[i] = p; // Store the index of the first edge for vertex i
    }
    g.id[g.vcnt] = g.ecnt; // Sentinel value for the last vertex

    vector<int> tyokkeitemp(g.vcnt + 10);
    tyokkeitemp[0] = 1; // Start DFS from vertex 0
    function<void(int)> tyokkeidfs = [&](int s) {
        for (int i = g.id[s]; i < g.id[s + 1]; i++) {
            // If the vertex has not been visited
            if (tyokkeitemp[g.e[i].g] == 0) {
                // Update the distance and continue DFS
                tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c;
                tyokkeidfs(g.e[i].g);
            }
        }
    };
    tyokkeidfs(0); // First DFS to find the farthest vertex

    int M = 0, Mi; // Variables to track maximum distance and corresponding vertex
    for (int i = 0; i < g.vcnt; i++) {
        // Find the vertex with the maximum distance
        if (tyokkeitemp[i] > M) {
            M = tyokkeitemp[i];
            Mi = i;
        }
    }

    // Reset distances for the second DFS
    fill(tyokkeitemp.begin(), tyokkeitemp.end(), 0);
    tyokkeitemp[Mi] = 1; // Start DFS from the farthest vertex found
    tyokkeidfs(Mi); // Second DFS to find the diameter

    // Find the maximum distance from the second DFS
    M = 0;
    for (int i = 0; i < g.vcnt; i++) M = max(M, tyokkeitemp[i]);

    cout << M - 1 << endl; // Print the diameter (subtract 1 for edge count)

    return 0;
}

