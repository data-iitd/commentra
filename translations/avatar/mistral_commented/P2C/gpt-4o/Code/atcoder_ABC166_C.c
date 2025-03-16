#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    // Read the first line of input containing the number of nodes 'n' and edges 'm'
    scanf("%d %d", &n, &m);

    // Initialize an array 'p' of numbers from 1 to 'n'
    int *p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    // Read the second line of input containing the heights of the nodes
    int *h = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    // Create an array 'hp' to store node number as index and height as value
    int *hp = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        hp[p[i] - 1] = h[i]; // p[i] is 1-based, so we use p[i] - 1 for 0-based index
    }

    // Initialize an array of lists to store the graph
    int **path = (int **)malloc((n + 1) * sizeof(int *));
    int *path_size = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        path[i] = (int *)malloc(n * sizeof(int)); // Allocate maximum size
        path_size[i] = 0; // Initialize size of each list
    }

    // Read 'm' lines of input containing edges and add them to the 'path' array
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        path[a][path_size[a]++] = b; // Add b to the adjacency list of a
        path[b][path_size[b]++] = a; // Add a to the adjacency list of b
    }

    // Initialize a counter 'c' to store the number of valid paths
    int c = 0;

    // Iterate through each node in the graph and check if it forms a valid path
    for (int i = 1; i <= n; i++) {
        // Initialize a flag 'f' to check if the current node is a valid starting point
        int f = 0;
        // Iterate through each neighbor of the current node and check if it is a valid ending point
        for (int j = 0; j < path_size[i]; j++) {
            int neighbor = path[i][j];
            // If the height of the current node is less than or equal to the height of its neighbor,
            // then it is not a valid path and we set the flag 'f' to 1 and break the loop
            if (hp[i] <= hp[neighbor]) {
                f = 1;
                break;
            }
        }
        // If the flag 'f' is still 0 after checking all neighbors, then this node forms a valid path
        // and we increment the counter 'c'
        if (f == 0) {
            c++;
        }
    }

    // Print the final result, i.e., the number of valid paths
    printf("%d\n", c);

    // Free allocated memory
    free(p);
    free(h);
    free(hp);
    for (int i = 1; i <= n; i++) {
        free(path[i]);
    }
    free(path);
    free(path_size);

    return 0;
}
