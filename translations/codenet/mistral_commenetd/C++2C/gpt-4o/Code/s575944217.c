#include <stdio.h> // Header file for input and output operations
#include <stdlib.h> // Header file for standard library functions

#define MAX_V 100001 // Maximum number of vertices in the graph

// Main function starts here
int main() {
    // Read the number of vertices from the input
    int n;
    scanf("%d", &n);

    // Initialize an answer array of size n
    int *ans = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ans[i] = 0; // Initialize the count of each vertex to 0
    }

    // Read the edges and increment the count of each vertex in the answer array
    for (int i = 0; i < n - 1; i++) {
        int a;
        scanf("%d", &a);
        a--; // Decrement the vertex index as it is 0-indexed
        ans[a]++; // Increment the count of the vertex
    }

    // Print the answer array
    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }

    // Free the allocated memory
    free(ans);
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
