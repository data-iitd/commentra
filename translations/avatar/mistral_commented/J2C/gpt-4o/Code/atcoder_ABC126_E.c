#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    int *par; // Parent array
    int *rank; // Rank array
    int n; // Number of vertices
} UnionFindTree;

UnionFindTree* createUnionFindTree(int n) {
    UnionFindTree *utf = (UnionFindTree *)malloc(sizeof(UnionFindTree));
    utf->n = n;
    utf->par = (int *)malloc(n * sizeof(int));
    utf->rank = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        utf->par[i] = i; // Initialize each vertex as its own parent
        utf->rank[i] = 0; // Initialize rank to 0
    }
    return utf;
}

int find(UnionFindTree *utf, int x) {
    if (utf->par[x] == x) {
        return x; // Base case: if x is the root
    } else {
        return utf->par[x] = find(utf, utf->par[x]); // Path compression
    }
}

void unite(UnionFindTree *utf, int x, int y) {
    x = find(utf, x);
    y = find(utf, y);
    if (x == y) return; // Already connected
    if (utf->rank[x] < utf->rank[y]) {
        utf->par[x] = y; // Make x the parent of y
    } else {
        utf->par[y] = x; // Make y the parent of x
        if (utf->rank[x] == utf->rank[y]) {
            utf->rank[x]++; // Increment rank if they are the same
        }
    }
}

int main() {
    int n, m;
    scanf("%d", &n); // Read number of vertices
    UnionFindTree *utf = createUnionFindTree(n);
    scanf("%d", &m); // Read number of edges

    // Processing the edges
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        unite(utf, x - 1, y - 1); // Unite the vertices (0-indexed)
    }

    int cnt = 0; // Counter for connected components
    for (int i = 0; i < n; i++) {
        if (utf->par[i] == i) { // Check if it's a root
            cnt++; // Increment counter
        }
    }
    printf("%d\n", cnt); // Print the number of connected components

    // Free allocated memory
    free(utf->par);
    free(utf->rank);
    free(utf);

    return 0;
}

// <END-OF-CODE>
