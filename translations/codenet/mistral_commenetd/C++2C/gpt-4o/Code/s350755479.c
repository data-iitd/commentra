#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005 // maximum number of nodes in the graph

struct Node {
    int x, y, id; // x and y coordinates, id of each node
} node[MAXN];

struct Edge {
    int u, v, val; // u and v are the ids of the nodes connected by the edge, the value of the edge
} e[MAXN << 1];

int par[MAXN]; // parent array to keep track of the parent of each node in the disjoint set data structure
int n; // number of nodes in the graph

// Comparator function for sorting nodes based on their x-coordinates
int cmp1(const void *a, const void *b) {
    return ((struct Node *)a)->x - ((struct Node *)b)->x;
}

// Comparator function for sorting nodes based on their y-coordinates
int cmp2(const void *a, const void *b) {
    return ((struct Node *)a)->y - ((struct Node *)b)->y;
}

// Initialization function for the disjoint set data structure
void init() {
    for (int i = 0; i <= n; i++)
        par[i] = i; // each node initially belongs to its own set
}

// Function to find the representative of a set
int findpar(int x) {
    if (par[x] != x) {
        par[x] = findpar(par[x]); // path compression is used to reduce the height of the tree
    }
    return par[x];
}

// Function to merge two sets
void unite(int x, int y) {
    x = findpar(x);
    y = findpar(y);
    if (x != y) {
        par[x] = y; // merge by making the root of set y as the parent of the root of set x
    }
}

int main() {
    scanf("%d", &n); // read the number of nodes in the graph

    init(); // initialize the disjoint set data structure

    // Read the coordinates of each node and assign an id to it
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &node[i].x, &node[i].y);
        node[i].id = i; // id is just the index of the node in the node array
    }

    // Sort the nodes based on their x-coordinates
    qsort(node + 1, n, sizeof(struct Node), cmp1);

    int cnt = 0; // initialize the counter for the number of edges
    // Create edges between adjacent nodes based on their x-coordinates
    for (int i = 2; i <= n; i++) {
        e[cnt++] = (struct Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x};
    }

    // Sort the nodes based on their y-coordinates
    qsort(node + 1, n, sizeof(struct Node), cmp2);
    // Create edges between adjacent nodes based on their y-coordinates
    for (int i = 2; i <= n; i++) {
        e[cnt++] = (struct Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y};
    }

    // Sort the edges based on their values
    qsort(e, cnt, sizeof(struct Edge), cmp1); // Using cmp1 for sorting edges based on val

    long long ans = 0; // initialize the answer to 0
    // Process each edge in the sorted order
    for (int i = 0; i < cnt; i++) {
        int u = e[i].u, v = e[i].v, val = e[i].val;
        // Skip if the nodes are already in the same set
        if (findpar(u) == findpar(v)) continue;
        // Merge the sets of the nodes and add the value of the edge to the answer
        unite(u, v);
        ans += val;
    }

    printf("%lld\n", ans); // print the final answer

    return 0;
}

// <END-OF-CODE>
