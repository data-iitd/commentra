#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000

int n, k;
int links[MAX_N][MAX_N]; // Adjacency list representation
int link_count[MAX_N]; // To keep track of the number of children for each node

void dfs(int v, int p, int *height_from_leaf, int *cut_count) {
    *height_from_leaf = 0; // Initialize the height from the leaf node
    *cut_count = 0; // Initialize the count of cuts

    for (int i = 0; i < link_count[v]; i++) { // Traverse the tree
        int u = links[v][i];
        if (u == 0) continue; // Skip if the node is the root (0)

        int hgt, cut;
        dfs(u, v, &hgt, &cut); // Recursively call DFS
        *height_from_leaf = (*height_from_leaf > hgt) ? *height_from_leaf : hgt; // Update the height from the leaf
        *cut_count += cut; // Count the number of cuts
    }

    (*height_from_leaf)++; // Increment the height from the leaf node

    if (p != 0 && *height_from_leaf == k) { // Check if a cut is needed
        *height_from_leaf = 0; // Reset the height
        (*cut_count)++; // Increment the cut count
    }
}

int main() {
    scanf("%d %d", &n, &k); // Read input data
    for (int i = 0; i < n; i++) {
        link_count[i] = 0; // Initialize the number of children
    }

    int a;
    for (int i = 1; i < n; i++) { // Build the tree
        scanf("%d", &a);
        a--; // Convert to 0-based index
        links[a][link_count[a]++] = i; // Add the edge
    }

    int ans = 0;
    int height_from_leaf, cut_count;
    dfs(0, -1, &height_from_leaf, &cut_count); // Perform DFS starting from the root
    ans = cut_count;

    if (n > 1) { // Adjust the answer if necessary
        ans++;
    }

    printf("%d\n", ans); // Output the final result
    return 0;
} // <END-OF-CODE>
