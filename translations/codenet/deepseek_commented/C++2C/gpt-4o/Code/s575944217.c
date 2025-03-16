#include <stdio.h>  // For input and output operations
#include <stdlib.h> // For memory allocation
#define MAX_V 100001 // Define a constant for the maximum number of vertices

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements or nodes
<<<<<<< HEAD
    int *ans = (int *)malloc(n * sizeof(int)); // Allocate memory for the count of incoming edges for each node
    for (int i = 0; i < n; i++) {
        ans[i] = 0; // Initialize the incoming edge count to 0
    }
    
=======
    int *ans = (int *)calloc(n, sizeof(int)); // Initialize an array to store the count of incoming edges for each node

>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < n - 1; i++) { // Loop to read edges and populate the array
        int a;
        scanf("%d", &a); // Read an integer
        a--; // Decrement by 1 to convert to 0-based indexing
        ans[a]++; // Increment the count of incoming edges for the node
    }
<<<<<<< HEAD
    
    for (int i = 0; i < n; i++) { // Loop to output the results
        printf("%d\n", ans[i]); // Print the number of incoming edges for each node
    }
    
    free(ans); // Free the allocated memory
    return 0; // Return 0 to indicate successful completion
=======

    for (int i = 0; i < n; i++) { // Loop to output the results
        printf("%d\n", ans[i]); // Print the number of incoming edges for each node
    }

    free(ans); // Free the allocated memory
    return 0; // Return success
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
