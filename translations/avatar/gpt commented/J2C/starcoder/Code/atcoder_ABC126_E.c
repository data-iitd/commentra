#include <stdio.h>
#include <stdlib.h>

// Constant for modulo operation
#define MOD 1000000007

// Union-Find data structure
typedef struct {
    int n; // Number of elements
    int *par; // Parent array
    int *rank; // Rank array for union by rank
} UnionFindTree;

// Constructor to initialize the Union-Find structure
UnionFindTree *uf_init(int n) {
    UnionFindTree *uf = (UnionFindTree *)malloc(sizeof(UnionFindTree));
    uf->n = n;
    uf->par = (int *)malloc(n * sizeof(int));
    uf->rank = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->par[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}

// Find the root of the set containing x with path compression
int uf_find(UnionFindTree *uf, int x) {
    if (uf->par[x] == x) {
        return x;
    } else {
        return uf->par[x] = uf_find(uf, uf->par[x]);
    }
}

// Unite the sets containing x and y
void uf_unite(UnionFindTree *uf, int x, int y) {
    x = uf_find(uf, x);
    y = uf_find(uf, y);
    // If they are already in the same set, do nothing
    if (x == y) return;
    // Union by rank
    if (uf->rank[x] < uf->rank[y]) {
        uf->par[x] = y;
    } else {
        uf->par[y] = x;
        if (uf->rank[x] == uf->rank[y]) {
            uf->rank[x]++;
        }
    }
}

// Check if x and y are in the same set
int uf_same(UnionFindTree *uf, int x, int y) {
    return uf_find(uf, x) == uf_find(uf, y);
}

// Main method to start the program
int main(int argc, char *argv[]) {
    // Read the number of elements (nodes)
    int n = atoi(argv[1]);
    // Initialize Union-Find data structure with n elements
    UnionFindTree *uf = uf_init(n);
    // Read the number of connections (edges)
    int m = atoi(argv[2]);

    // Process each connection
    for (int i = 0; i < m; i++) {
        // Read the two nodes to unite and the weight (not used in this implementation)
        int x = atoi(argv[3 + 3 * i]) - 1;
        int y = atoi(argv[4 + 3 * i]) - 1;
        int z = atoi(argv[5 + 3 * i]);
        // Unite the two nodes
        uf_unite(uf, x, y);
    }

    // Count the number of unique connected components
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // Check if the current node is a root of a component
        if (uf_find(uf, i) == i) {
            cnt++;
        }
    }

    // Output the count of unique connected components
    printf("%d\n", cnt);
    return 0;
}

