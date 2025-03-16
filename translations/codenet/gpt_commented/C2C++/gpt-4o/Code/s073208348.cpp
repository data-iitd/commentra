#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))

// Structure to hold edge information
struct Edge {
    ll s, g, c; // start vertex, end vertex, and cost of the edge
};

// Structure to represent the graph
struct Graph {
    int vcnt, ecnt; // number of vertices and edges
    std::vector<Edge> e; // vector to hold edges
    std::vector<int> id; // vector to hold index of edges for each vertex

    Graph(int n) : vcnt(n), ecnt(0), e(2 * n - 2), id(n + 1) {}
};

int esort(const Edge &p, const Edge &q) {
    // Sort edges primarily by start vertex, then by end vertex
    if (p.s < q.s) return -1;
    if (p.s > q.s) return 1;
    if (p.g < q.g) return -1;
    return 1;
}

Graph g(100010); // Global graph variable

// Function to read the graph from input
void readgraph() {
    ll n;
    // Read the number of vertices
    std::cin >> n;
    // Read edges and construct the graph
    rep(i, 0, n - 1) {
        ll x, y, c;
        std::cin >> x >> y >> c;
        // Add edge from x to y
        g.e[2 * i] = {x, y, c};
        // Add edge from y to x (undirected graph)
        g.e[2 * i + 1] = {y, x, c};
    }
    g.vcnt = n; // Set vertex count
    g.ecnt = 2 * n - 2; // Set edge count (undirected edges)
    // Sort edges based on start and end vertices
    std::sort(g.e.begin(), g.e.begin() + g.ecnt, esort);

    int p = 0;
    // Create an index for edges for each vertex
    rep(i, 0, g.vcnt) {
        while (p < g.ecnt && g.e[p].s < i) p++;
        g.id[i] = p; // Store the index of the first edge for vertex i
    }
    g.id[g.vcnt] = g.ecnt; // Sentinel value for the last vertex
}

// Function to perform DFS and find the diameter of the tree
std::vector<int> tyokkeitemp; // Temporary array to store distances during DFS

// Recursive DFS function to explore the tree
void tyokkeidfs(ll s) {
    for (int i = g.id[s]; i < g.id[s + 1]; i++) {
        // If the vertex has not been visited
        if (tyokkeitemp[g.e[i].g] == 0) {
            // Update the distance and continue DFS
            tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c;
            tyokkeidfs(g.e[i].g);
        }
    }
}

// Function to calculate the diameter of the tree
int tyokkei() {
    // Allocate memory for distance array
    tyokkeitemp.assign(g.vcnt + 10, 0);
    tyokkeitemp[0] = 1; // Start DFS from vertex 0
    tyokkeidfs(0); // First DFS to find the farthest vertex

    int M = 0, Mi; // Variables to track maximum distance and corresponding vertex
    rep(i, 0, g.vcnt) {
        // Find the vertex with the maximum distance
        if (tyokkeitemp[i] > M) {
            M = tyokkeitemp[i];
            Mi = i;
        }
    }
    
    // Reset distances for the second DFS
    rep(i, 0, g.vcnt) tyokkeitemp[i] = 0;
    tyokkeitemp[Mi] = 1; // Start DFS from the farthest vertex found
    tyokkeidfs(Mi); // Second DFS to find the diameter

    // Find the maximum distance from the second DFS
    rep(i, 0, g.vcnt) M = max(M, tyokkeitemp[i]);
    return M - 1; // Return the diameter (subtract 1 for edge count)
}

int main() {
    readgraph(); // Read the graph input
    std::cout << tyokkei() << std::endl; // Calculate and print the diameter of the tree
}

// <END-OF-CODE>
