#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
#define MAXN 100005
=======
#define maxn 100005
>>>>>>> 98c87cb78a (data updated)

// Structure to represent a node with coordinates and an ID
struct Node {
    int x, y, id;
<<<<<<< HEAD
} node[MAXN];
=======
} node[maxn];
>>>>>>> 98c87cb78a (data updated)

// Structure to represent an edge with two nodes and a weight
struct Edge {
    int u, v, val;
};

// Array to store the parent of each node for union-find
<<<<<<< HEAD
int par[MAXN];
int n; // Number of nodes

// Comparison function for sorting edges based on their weight
int cmp_edge(const void *a, const void *b) {
    return ((struct Edge *)a)->val - ((struct Edge *)b)->val;
}

// Comparison function for sorting nodes based on their x-coordinate
int cmp_x(const void *a, const void *b) {
    return ((struct Node *)a)->x - ((struct Node *)b)->x;
}

// Comparison function for sorting nodes based on their y-coordinate
int cmp_y(const void *a, const void *b) {
=======
int par[maxn];
int n; // Number of nodes

// Comparison function for sorting edges based on their weight
int cmp(const void *a, const void *b) {
    return ((struct Edge *)a)->val - ((struct Edge *)b)->val;
}

// Comparison function for sorting nodes based on x-coordinate
int cmp1(const void *a, const void *b) {
    return ((struct Node *)a)->x - ((struct Node *)b)->x;
}

// Comparison function for sorting nodes based on y-coordinate
int cmp2(const void *a, const void *b) {
>>>>>>> 98c87cb78a (data updated)
    return ((struct Node *)a)->y - ((struct Node *)b)->y;
}

// Function to initialize the union-find structure
void init() {
    for (int i = 0; i <= n; i++)
        par[i] = i; // Each node is its own parent initially
}

// Function to find the representative parent of a node
int findpar(int x) {
    if (par[x] != x) {
        par[x] = findpar(par[x]); // Path compression
    }
    return par[x];
}

// Function to unite two nodes in the union-find structure
void unite(int x, int y) {
    x = findpar(x);
    y = findpar(y);
    if (x != y) {
        par[x] = y; // Union the sets by making one parent of the other
    }
}

int main() {
    // Read the number of nodes
    scanf("%d", &n);

    // Initialize the union-find structure
    init();

    // Read the coordinates of each node and assign an ID
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &node[i].x, &node[i].y);
        node[i].id = i; // Assign ID to the node
    }

<<<<<<< HEAD
    struct Edge e[MAXN * 2]; // Array to store edges
    int cnt = 0; // Counter for edges

    // Sort nodes based on their x-coordinate
    qsort(node + 1, n, sizeof(struct Node), cmp_x);

=======
    // Create an array for edges
    struct Edge e[maxn * 2];
    int cnt = 0; // Counter for edges

    // Sort nodes based on their x-coordinate
    qsort(node + 1, n, sizeof(struct Node), cmp1);
>>>>>>> 98c87cb78a (data updated)
    // Create edges based on x-coordinates
    for (int i = 2; i <= n; i++) {
        e[cnt++] = (struct Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x};
    }

    // Sort nodes based on their y-coordinate
<<<<<<< HEAD
    qsort(node + 1, n, sizeof(struct Node), cmp_y);
    
=======
    qsort(node + 1, n, sizeof(struct Node), cmp2);
>>>>>>> 98c87cb78a (data updated)
    // Create edges based on y-coordinates
    for (int i = 2; i <= n; i++) {
        e[cnt++] = (struct Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y};
    }

    // Sort edges based on their weight
<<<<<<< HEAD
    qsort(e, cnt, sizeof(struct Edge), cmp_edge);

    long long ans = 0; // Variable to store the total weight of the minimum spanning tree

=======
    qsort(e, cnt, sizeof(struct Edge), cmp);

    long long ans = 0; // Variable to store the total weight of the minimum spanning tree
>>>>>>> 98c87cb78a (data updated)
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

// <END-OF-CODE>
