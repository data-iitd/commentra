#include <stdio.h>
#include <stdlib.h>

// Define the root function which returns the root of a tree node
// This function uses recursion to find the root of a node by traversing up the tree
// until it reaches the root node or a node with the same parent
int root(int x, int *par) {
    return x == par[x] ? x : root(par[x], par);
}

// Define the same function which checks if two nodes have the same root
// This function is used to check if two nodes belong to the same tree
int same(int x, int y, int *par) {
    return root(x, par) == root(y, par);
}

// Define the unite function which merges two trees into one
// This function sets the parent of the smaller tree to the root of the larger tree
// and updates the size of the root node accordingly
void unite(int x, int y, int *par, int *rank, int *size) {
    x = root(x, par);
    y = root(y, par);
    if (x != y) {
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) {
                rank[x] += 1;
            }
        }
    }
}

int main() {
    // Read input from standard input and initialize variables
    int n, *a, *par, *rank, *size, *b, c, k, l, r;
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    par = (int *)malloc(n * sizeof(int));
    rank = (int *)malloc(n * sizeof(int));
    size = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[a[i] - 1] = i;
    }

    // Initialize the result variable c
    c = 0;

    // Iterate through the list b from the second element to the first
    for (k = n - 1; k >= 0; k--) {
        // Initialize variables l and r to store the sizes of the left and right subtrees
        l = 1;
        r = 1;

        // Check if the current node k has a larger element to its left
        if (k > 0 && a[k - 1] > a[k]) {
            // If yes, update l with the size of the left subtree
            l += size[root(k - 1, par)];
            // Merge the left and current subtrees
            unite(k - 1, k, par, rank, size);
        }

        // Check if the current node k has a larger element to its right
        if (k + 1 < n && a[k + 1] > a[k]) {
            // If yes, update r with the size of the right subtree
            r += size[root(k + 1, par)];
            // Merge the right and current subtrees
            unite(k + 1, k, par, rank, size);
        }

        // Update the result variable c with the product of the sizes of the left and right subtrees
        // and the value of the current element
        c += l * r * a[k];
    }

    // Print the result
    printf("%d\n", c);

    // Free memory
    free(a);
    free(par);
    free(rank);
    free(size);
    free(b);

    return 0;
}

