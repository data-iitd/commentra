#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of nodes
#define MAX_N 100000

// Global variables to store parent and rank arrays
int par[MAX_N];
int rank[MAX_N];
int size[MAX_N];

// Function to find the root of a node using path compression
int root(int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = root(par[x]);
}

// Function to check if two nodes have the same root
int same(int x, int y) {
    return root(x) == root(y);
}

// Function to merge two trees into one
void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
}

int main() {
    int n, *a, *b, c = 0;
    int i, k, l, r;

    // Read input from standard input
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(n * sizeof(int));

    // Initialize parent and rank arrays
    for (i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 1;
        size[i] = 1;
    }

    // Read the input array a
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[a[i] - 1] = i;
    }

    // Iterate through the list b from the second element to the first
    for (k = n - 1; k >= 0; k--) {
        l = 1;
        r = 1;

        // Check if the current node k has a larger element to its left
        if (b[k] > 0 && a[b[k] - 1] > a[b[k]]) {
            l += size[root(b[k] - 1)];
            unite(b[k] - 1, b[k]);
        }

        // Check if the current node k has a larger element to its right
        if (b[k] + 1 < n && a[b[k] + 1] > a[b[k]]) {
            r += size[root(b[k] + 1)];
            unite(b[k] + 1, b[k]);
        }

        // Update the result variable c
        c += l * r * a[b[k]];
    }

    // Print the result
    printf("%d\n", c);

    // Free allocated memory
    free(a);
    free(b);

    return 0;
}
