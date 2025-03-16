#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Set the recursion limit for the function call stack to 1 million
#define RECURSION_LIMIT 1000000

// Define the depth-first search function 'dfs'
int dfs(int ** links, int n, int k, int v, int p, int * height_from_leaf, int * cut_count) {
    // Initialize variables for height from leaf node and cut count
    *height_from_leaf = 0;
    *cut_count = 0;

    // Iterate through neighbors of the current node 'v'
    for (int i = 0; i < n; i++) {
        // Skip if the neighbor is not a valid node (0)
        if (links[v][i] == 0) {
            continue;
        }

        // Recursively call the 'dfs' function for the neighbor 'u'
        int hgt, cut;
        dfs(links, n, k, i, v, &hgt, &cut);

        // Update the height from leaf and cut count
        *height_from_leaf = max(*height_from_leaf, hgt);
        *cut_count += cut;
    }

    // Update the height from leaf and cut count for the current node 'v'
    *height_from_leaf += 1;

    // If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
    // then this node is a cut vertex and we need to add 1 to the cut count
    if (p != 0 && *height_from_leaf == k) {
        *height_from_leaf = 0;
        *cut_count += 1;
    }

    // Return the height from leaf and cut count for the current node 'v'
    return *height_from_leaf, *cut_count;
}

// Read input from standard input
int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize the 'links' list with sets for each node
    int ** links = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        links[i] = (int *) malloc(n * sizeof(int));
        memset(links[i], 0, n * sizeof(int));
    }

    // Process the input edges and add them to the 'links' list
    for (int i = 0; i < n - 1; i++) {
        int a;
        scanf("%d", &a);
        a--;
        links[a][i] = 1;
    }

    // Call the 'dfs' function with the initial parameters
    int height_from_leaf, cut_count;
    dfs(links, n, k, 0, 0, &height_from_leaf, &cut_count);

    // If the first node is not a root node, add 1 to the answer
    if (links[0][0] != 1) {
        cut_count += 1;
    }

    // Print the final answer
    printf("%d\n", cut_count);

    // Free the memory allocated for the 'links' list
    for (int i = 0; i < n; i++) {
        free(links[i]);
    }
    free(links);

    return 0;
}

