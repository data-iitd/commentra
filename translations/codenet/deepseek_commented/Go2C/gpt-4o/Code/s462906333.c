#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 100000000000000 // Define a large value to represent infinity for cost comparisons

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x); // Read the number of elements and parameter x
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
    int *a = (int *)malloc(n * sizeof(int)); // Initialize the array a with size n
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Fill the array a with integers from input
    }

    int *v = (int *)malloc(n * sizeof(int)); // Create a copy of array a named v
    int ans = INF; // Initialize the answer with a large value

    for (int k = 0; k < n; k++) { // Iterate over possible values of k
        int kans = 0; // Initialize the temporary answer for the current k
        for (int i = 0; i < n; i++) { // Iterate over each element in the array
            if (i - k < 0) { // If the index is out of bounds, wrap around
                v[i] = min(v[i], a[n + i - k]); // Update the value in v
            } else {
                v[i] = min(v[i], a[i - k]); // Update the value in v
            }
            kans += v[i]; // Add the updated value to the temporary answer
        }
        ans = min(ans, kans + k * x); // Update the final answer with the minimum cost
    }

    printf("%d\n", ans); // Print the minimum cost found

    free(a); // Free allocated memory
    free(v); // Free allocated memory
    return 0;
}

// <END-OF-CODE>
