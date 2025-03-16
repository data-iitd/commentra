#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the number of nodes 'n' and the number of edges 'm'
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize an output array 'out' of size 'n' with zeros
    int *out = (int *)calloc(n, sizeof(int));

    // Initialize a complement array 'comp' of size 'n' with values 'i+2' for 'i' in range(n)
    int *comp = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        comp[i] = i + 2;
    }

    // Process each edge in the given 'm' edges
    for (int i = 0; i < m; i++) {
        // Read the left node 'l', right node 'r', and value 'x' of the current edge
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        
        // Set the initial index 't' to the left node 'l'
        int t = l;

        // Iterate through the nodes from 'l' to 'r'
        while (t <= r) {
            // Get the next value in the complement array 'comp'
            int next_val = comp[t - 1];
            
            // If the current node 't' in the output array 'out' is zero and it's not the value 'x'
            if (out[t - 1] == 0 && t != x) {
                // Update the output array 'out' with the value 'x' at index 't-1'
                out[t - 1] = x;
            }
            
            // Update the complement array 'comp' with the next value or the value 'x' depending on the condition
            comp[t - 1] = (t >= x) ? (r + 1) : x;
            
            // Update the index 't' to the next value in the complement array 'comp'
            t = next_val;
        }
    }

    // Print the output array 'out'
    for (int i = 0; i < n; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");

    // Free allocated memory
    free(out);
    free(comp);

    return 0;
}

// <END-OF-CODE>
