#include <stdio.h>
#include <stdlib.h>

#define maxn 100005 // Define a constant for the maximum number of nodes

struct Node {
    int x, y, id; // Define a structure for nodes with x, y coordinates and an id
} node[maxn];

struct Edge {
    int u, v, val; // Define a structure for edges with u, v nodes and a value
};

// Comparison function for sorting edges by value
int cmp_edge(const void *a, const void *b) {
    return ((struct Edge *)a)->val - ((struct Edge *)b)->val;
}

int par[maxn]; // Define an array for storing the parent of each node
int n; // Define an integer for the number of nodes

// Comparison function to sort nodes by x coordinate
int cmp_x(const void *a, const void *b) {
    return ((struct Node *)a)->x - ((struct Node *)b)->x;
}

// Comparison function to sort nodes by y coordinate
int cmp_y(const void *a, const void *b) {
    return ((struct Node *)a)->y - ((struct Node *)b)->y;
}

void init() { // Define a function to initialize the parent array
    for (int i = 0; i <= n; i++)
        par[i] = i;
}

int findpar(int x) { // Define a function to find the root of a node using path compression
    if (par[x] != x) {
        par[x] = findpar(par[x]);
    }
    return par[x];
}

void unite(int x, int y) { // Define a function to merge two sets
    x = findpar(x);
    y = findpar(y);
    if (x != y) {
        par[x] = y;
    }
}

int main() {
    scanf("%d", &n); // Read the number of nodes

    init(); // Initialize the parent array

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &node[i].x, &node[i].y); // Read the coordinates of each node
        node[i].id = i; // Assign an id to each node
    }

    // Sort nodes by x coordinate and create edges based on x differences
    qsort(node + 1, n, sizeof(struct Node), cmp_x);
    struct Edge e[maxn * 2]; // Define an array for edges with a size of up to 2*maxn
    int cnt = 0; // Initialize a counter for edges
    for (int i = 2; i <= n; i++)
        e[cnt++] = (struct Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x}; // Create edges based on x differences

    // Sort nodes by y coordinate and create edges based on y differences
    qsort(node + 1, n, sizeof(struct Node), cmp_y);
    for (int i = 2; i <= n; i++)
        e[cnt++] = (struct Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y}; // Create edges based on y differences

    // Sort all edges by their values
    qsort(e, cnt, sizeof(struct Edge), cmp_edge);

    long long ans = 0; // Initialize a variable to store the total weight of the minimum spanning tree
    for (int i = 0; i < cnt; i++) {
        int u = e[i].u, v = e[i].v, val = e[i].val;
        if (findpar(u) == findpar(v)) continue; // Skip if u and v are already in the same set
        unite(u, v); // Merge u and v
        ans += val; // Add the edge value to the total weight
    }

    printf("%lld\n", ans); // Output the total weight of the minimum spanning tree

    return 0;
}

// <END-OF-CODE>
