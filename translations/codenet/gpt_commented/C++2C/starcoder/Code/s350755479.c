#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <limits.h>

// Define a constant for the maximum number of nodes
#define maxn 1e5 + 5

// Structure to represent a node with coordinates and an ID
struct Node {
    int x, y, id;
} node[maxn];

// Structure to represent an edge with two nodes and a weight
struct Edge {
    int u, v, val;
    // Overloading the less-than operator for sorting edges based on their weight
    bool operator <(const Edge& rhs) const {
        return val < rhs.val;
    }
} e[maxn << 1];

// Array to store the parent of each node for union-find
int par[maxn];
int n; // Number of nodes

// Comparison function to sort nodes based on their x-coordinate
bool cmp1(const Node &a, const Node &b) {
    return a.x < b.x;
}

// Comparison function to sort nodes based on their y-coordinate
bool cmp2(const Node &a, const Node &b) {
    return a.y < b.y;
}

// Function to initialize the union-find structure
void init() {
    for (int i = 0; i <= n; i++)
        par[i] = i; // Each node is its own parent initially
}

// Function to find the representative parent of a node
int findpar(int x) {
    return par[x] = (par[x] == x? x : findpar(par[x])); // Path compression
}

// Function to unite two nodes in the union-find structure
void unite(int x, int y) {
    x = findpar(x), y = findpar(y); // Find the parents of both nodes
    if (x == y) return; // If they are already in the same set, do nothing
    par[x] = y; // Union the sets by making one parent of the other
}

int main(int argc, char const *argv[]) {
    
    // Read the number of nodes
    scanf("%d", &n);

    // Initialize the union-find structure
    init();

    // Read the coordinates of each node and assign an ID
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &node[i].x, &node[i].y);
        node[i].id = i; // Assign ID to the node
    }

    // Sort nodes based on their x-coordinate
    qsort(node + 1, n, sizeof(Node), cmp1);

    int cnt = 0; // Counter for edges
    // Create edges based on x-coordinates
    for (int i = 2; i <= n; i++)
        e[cnt++] = (Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x};
    
    // Sort nodes based on their y-coordinate
    qsort(node + 1, n, sizeof(Node), cmp2);
    // Create edges based on y-coordinates
    for (int i = 2; i <= n; i++)
        e[cnt++] = (Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y};

    // Sort edges based on their weight
    qsort(e, cnt, sizeof(Edge), cmp1);

    long long ans = 0; // Variable to store the total weight of the minimum spanning tree
    // Process each edge in sorted order
    for (int i = 0; i < cnt; i++) {
        int u = e[i].u, v = e[i].v, val = e[i].val;
        // If u and v are already connected, skip this edge
        if (findpar(u) == findpar(v)) continue;
        unite(u, v); // Union the two nodes
        ans += val; // Add the weight of this edge to the total
    }

    // Output the total weight of the minimum spanning tree
    printf("%lld\n", ans);

    return 0; // End of the program
}

