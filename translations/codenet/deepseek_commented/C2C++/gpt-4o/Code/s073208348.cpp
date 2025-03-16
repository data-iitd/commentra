#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
#define rep(i,l,r) for(ll i=(l); i<(r); i++)
#define max(p,q) ((p)>(q) ? (p) : (q))

// Edge structure
struct Edge {
    ll s, g, c; // start, end, cost
};

// Graph structure
struct Graph {
    int vcnt, ecnt;
    std::vector<Edge> e; // Vector to hold edges
    std::vector<int> id; // Vector to hold indices

    Graph(int n) : vcnt(n), ecnt(0), e(2 * (n - 1)), id(n + 1) {} // Initialize graph
};

// Comparator function for sorting edges
bool esort(const Edge &p, const Edge &q) {
    if (p.s < q.s) return true;
    if (p.s > q.s) return false;
    return p.g < q.g; // Compare based on end vertex
}

Graph g(100010); // Global graph variable
int *tyokkeitemp; // Temporary array for DFS

void readgraph() {
    ll n;
    std::cin >> n; // Read number of vertices
    rep(i, 0, n - 1) {
        ll x, y, c;
        std::cin >> x >> y >> c; // Read each edge
        g.e[2 * i] = {x, y, c};
        g.e[2 * i + 1] = {y, x, c}; // Add reverse edge
    }
    g.ecnt = 2 * (n - 1); // Set number of edges
    std::sort(g.e.begin(), g.e.begin() + g.ecnt, esort); // Sort edges

    int p = 0;
    rep(i, 0, g.vcnt) {
        while (p < g.ecnt && g.e[p].s < i) p++;
        g.id[i] = p; // Populate id array
    }
    g.id[g.vcnt] = g.ecnt; // Set sentinel value
}

void tyokkeidfs(ll s) {
    for (int i = g.id[s]; i < g.id[s + 1]; i++) {
        if (tyokkeitemp[g.e[i].g] == 0) {
            tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c;
            tyokkeidfs(g.e[i].g); // Recursive DFS
        }
    }
}

int tyokkei() {
    tyokkeitemp = new int[g.vcnt + 10]; // Allocate memory
    std::memset(tyokkeitemp, 0, (g.vcnt + 10) * sizeof(int)); // Initialize
    tyokkeitemp[0] = 1; // Start from root
    tyokkeidfs(0); // Perform DFS

    int M = 0, Mi; // Variables to find max distance
    rep(i, 0, g.vcnt) {
        if (tyokkeitemp[i] > M) {
            M = tyokkeitemp[i];
            Mi = i; // Farthest vertex
        }
    }
    std::memset(tyokkeitemp, 0, (g.vcnt + 10) * sizeof(int)); // Reset
    tyokkeitemp[Mi] = 1; // Start from farthest vertex
    tyokkeidfs(Mi); // Perform DFS again

    rep(i, 0, g.vcnt) M = max(M, tyokkeitemp[i]); // Find max distance
    delete[] tyokkeitemp; // Free memory
    return M - 1; // Return diameter
}

int main() {
    readgraph(); // Read the graph
    std::cout << tyokkei() << std::endl; // Print the diameter
}

// <END-OF-CODE>
