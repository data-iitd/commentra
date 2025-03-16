#include <stdio.h>
#include <stdlib.h>

// Define the root function which returns the root of a tree node
// This function uses recursion to find the root of a node by traversing up the tree
// until it reaches the root node or a node with the same parent
int root(int x) {
    return x == par[x]? x : root(par[x]);
}

// Define the same function which checks if two nodes have the same root
// This function is used to check if two nodes belong to the same tree
int same(int x, int y) {
    return root(x) == root(y);
}

// Define the unite function which merges two trees into one
// This function sets the parent of the smaller tree to the root of the larger tree
// and updates the size of the root node accordingly
void unite(int x, int y) {
    int x_root = root(x), y_root = root(y);
    if (x_root!= y_root) {
        if (rank[x_root] < rank[y_root]) {
            par[x_root] = y_root;
            size[y_root] += size[x_root];
        } else {
            par[y_root] = x_root;
            size[x_root] += size[y_root];
            if (rank[x_root] == rank[y_root]) {
                rank[x_root]++;
            }
        }
    }
}

// Read input from standard input and initialize variables
int n, *a, *par, *rank, *size, *b, c;
scanf("%d", &n);
a = (int *) malloc(n * sizeof(int));
par = (int *) malloc(n * sizeof(int));
rank = (int *) malloc(n * sizeof(int));
size = (int *) malloc(n * sizeof(int));
b = (int *) malloc(n * sizeof(int));
for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[a[i] - 1] = i;
}

// Initialize a variable c to store the result
c = 0;

// Iterate through the list b from the second element to the first
for (int k = n - 1; k >= 1; k--) {
    // Initialize variables l and r to store the sizes of the left and right subtrees
    int l = 1, r = 1;
    
    // Check if the current node k has a larger element to its left
    if (k > 0 && a[k - 1] > a[k]) {
        // If yes, update l with the size of the left subtree
        l += size[root(k - 1)];
        // Merge the left and current subtrees
        unite(k - 1, k);
    }

    // Check if the current node k has a larger element to its right
    if (k + 1 < n && a[k + 1] > a[k]) {
        // If yes, update r with the size of the right subtree
        r += size[root(k + 1)];
        // Merge the right and current subtrees
        unite(k + 1, k);
    }

    // Update the result variable c with the product of the sizes of the left and right subtrees
    // and the value of the current element
    c += l * r * a[k];
}

// Print the result
printf("%d\n", c);

// 