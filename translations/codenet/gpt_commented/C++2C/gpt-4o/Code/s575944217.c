#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
=======
>>>>>>> 98c87cb78a (data updated)

#define MAX_V 100001
#define MOD 1000000007

int main() {
    // Read the number of vertices (or nodes)
    int n;
    scanf("%d", &n);

    // Initialize an array to store the count of edges for each vertex
<<<<<<< HEAD
    int *ans = (int *)calloc(n, sizeof(int));
=======
    int ans[MAX_V] = {0}; // Initialize to 0
>>>>>>> 98c87cb78a (data updated)

    // Read n-1 edges and count the occurrences for each vertex
    for (int i = 0; i < n - 1; i++) {
        int a;
        scanf("%d", &a); // Read the vertex index
        a--; // Convert to 0-based index
        ans[a]++; // Increment the count for the corresponding vertex
    }

    // Output the count of edges for each vertex
    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]); // Print the count for vertex i
    }

<<<<<<< HEAD
    // Free allocated memory
    free(ans);

=======
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
