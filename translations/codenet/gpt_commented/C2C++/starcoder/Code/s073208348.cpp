#include <bits/stdc++.h>

using namespace std;

// Structure to hold edge information
struct edge {
    ll s, g, c; // start vertex, end vertex, and cost of the edge
};

// Structure to represent the graph
struct graph {
    int vcnt, ecnt; // number of vertices and edges
    edge e[200010];    // array to hold edges
    int id[100010]; // array to hold index of edges for each vertex
};

// Function to read the graph from input
void readgraph() {
    ll n;
    // Read the number of vertices
    scanf("%lld", &n);
    // Read edges and construct the graph
    rep(i, 0, n - 1) {
        ll x, y, c;
        scanf("%lld%lld%lld", &x, &y, &c);
        // Add edge from x to y
        g.e[2 * i].s = x;
        g.e[2 * i].g = y;
        g.e[2 * i].c = c;
        // Add edge from y to x (undirected graph)
        g.e[2 * i + 1].s = y;
        g.e[2 * i + 1].g = x;
        g.e[2 * i + 1].c = c;
    }
    g.vcnt = n; // Set vertex count
    g.ecnt = 2 * n - 2; // Set edge count (undirected edges)
    // Sort edges based on start and end vertices
    sort(g.e, g.e + g.ecnt, [](edge a, edge b) {
        return a.s < b.s;
    });

    int p = 0;
    // Create an index for edges for each vertex
    rep(i, 0, g.vcnt) {
        while (p < g.ecnt && g.e[p].s < i) p++;
        g.id[i] = p; // Store the index of the first edge for vertex i
    }
    g.id[g.vcnt] = g.ecnt; // Sentinel value for the last vertex
}

// Function to perform DFS and find the diameter of the tree
int *tyokkeitemp; // Temporary array to store distances during DFS

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
    tyokkeitemp = (int *)calloc(g.vcnt + 10, sizeof(int));
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
    free(tyokkeitemp); // Free allocated memory
    return M - 1; // Return the diameter (subtract 1 for edge count)
}

int main() {
    readgraph(); // Read the graph input
    printf("%d\n", tyokkei()); // Calculate and print the diameter of the tree
}

