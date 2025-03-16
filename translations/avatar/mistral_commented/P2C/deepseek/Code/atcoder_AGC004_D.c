#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000

// Define the depth-first search function 'dfs'
int dfs(int** links, int n, int k, int* v, int p) {
    // Initialize variables for height from leaf node and cut count
    int height_from_leaf = 0;
    int cut_count = 0;

    // Iterate through neighbors of the current node 'v'
    for (int i = 0; i < n; i++) {
        int u = links[v][i];

        // Skip if the neighbor is not a valid node (0)
        if (u == 0) {
            continue;
        }

        // Recursively call the 'dfs' function for the neighbor 'u'
        int hgt, cut;
        hgt = dfs(links, n, k, &links[u], v);
        cut = cut_count;

        // Update the height from leaf and cut count
        height_from_leaf = height_from_leaf > hgt ? height_from_leaf : hgt;
        cut_count += cut;
    }

    // Update the height from leaf and cut count for the current node 'v'
    height_from_leaf += 1;

    // If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
    // then this node is a cut vertex and we need to add 1 to the cut count
    if (p != 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count += 1;
    }

    // Return the height from leaf and cut count for the current node 'v'
    return height_from_leaf;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize the 'links' array with malloc
    int* aaa = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &aaa[i]);
        aaa[i]--;
    }

    // Initialize the 'links' array with malloc
    int** links = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        links[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            links[i][j] = 0;
        }
    }

    // Process the input edges and add them to the 'links' array
    for (int i = 0; i < n; i++) {
        int a = aaa[i];
        links[a][i] = i;
    }

    // Call the 'dfs' function with the initial parameters
    int ans = dfs(links, n, k, &links[0], 0);

    // If the first node is not a root node, add 1 to the answer
    if (aaa[0] != 1) {
        ans += 1;
    }

    // Print the final answer
    printf("%d\n", ans);

    // Free the allocated memory
    free(aaa);
    for (int i = 0; i < n; i++) {
        free(links[i]);
    }
    free(links);

    return 0;
}
