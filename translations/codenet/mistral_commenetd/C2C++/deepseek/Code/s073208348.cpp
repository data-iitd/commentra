#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

#define ll long long
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define max(p, q) ((p) > (q) ? (p) : (q))

// Define the structure for the edge and graph.
struct Edge {
    ll s, g, c;
};

struct Graph {
    int vcnt, ecnt; // Number of vertices and edges in the graph.
    vector<Edge> e; // Vector to store edges.
    vector<int> id; // Vector to store the index of each vertex in the sorted edge list.
};

// Initialize the graph structure.
Graph g;

// Read the graph from the standard input.
void readgraph() {
    // Read the number of vertices.
    ll n;
    cin >> n;
    // Allocate memory for the vertices and edges.
    g.vcnt = n;
    g.ecnt = 2 * n - 2;
    // Allocate memory for the edge array and sort it.
    g.e.resize(g.ecnt);
    g.id.resize(g.vcnt + 1);
    // Read the edges.
    rep(i, 0, n - 1) {
        ll x, y, c;
        cin >> x >> y >> c;
        // Add an edge from x to y and y to x with the given cost.
        g.e[i] = {x, y, c};
        g.e[i + g.ecnt] = {y, x, c};
    }
    // Set the number of edges.
    g.ecnt *= 2;
    // Sort the edges using sort.
    sort(g.e.begin(), g.e.end(), [](const Edge& a, const Edge& b) {
        if (a.s != b.s) return a.s < b.s;
        return a.g < b.g;
    });
    // Initialize the id array.
    int p = 0;
    rep(i, 0, g.vcnt) {
        // Find the index of the current vertex in the sorted edge list.
        while (p < g.ecnt && g.e[p].s < i) p++;
        g.id[i] = p;
    }
    // Set the last index as a sentinel.
    g.id[g.vcnt] = g.ecnt;
}

// Function to find the diameter of the tree using DFS algorithm.
// *tyokkeitemp is an array to store the depth of each vertex from the root.
int* tyokkeitemp;
void tyokkeidfs(ll s) {
    // Iterate through the edges connected to the current vertex.
    for (int i = g.id[s]; i < g.id[s + 1]; i++) {
        // If the destination vertex has not been visited yet, recursively call tyokkeidfs.
        if (tyokkeitemp[g.e[i].g] == 0) {
            tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c;
            tyokkeidfs(g.e[i].g);
        }
    }
}

int tyokkei() {
    // Allocate memory for tyokkeitemp array.
    tyokkeitemp = new int[g.vcnt + 10];
    memset(tyokkeitemp, 0, sizeof(int) * (g.vcnt + 10));
    // Initialize the root vertex depth to 1.
    tyokkeitemp[0] = 1;
    // Perform DFS from the root vertex.
    tyokkeidfs(0);
    // Find the maximum depth.
    int M = 0, Mi;
    rep(i, 0, g.vcnt) {
        // If the current vertex depth is greater than the maximum depth, update it.
        if (tyokkeitemp[i] > M) {
            M = tyokkeitemp[i];
            Mi = i;
        }
    }
    // Free the memory allocated for tyokkeitemp.
    delete[] tyokkeitemp;
    // Return the diameter which is the maximum depth minus 1.
    return M - 1;
}

// Main function to read the graph and print the diameter.
int main() {
    // Read the graph.
    readgraph();
    // Call the tyokkei function to find the diameter.
    cout << tyokkei() << endl;
    return 0;
}
