#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, k, t;
    scanf("%d %d", &n, &k); // Read the number of elements and the subarray size
<<<<<<< HEAD
    int *vec = (int *)malloc(n * sizeof(int)); // Allocate memory for the array
=======
    int *vec = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for the array
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < n; i++) {
        scanf("%d", &t); // Read each element and add it to the array
        vec[i] = t;
    }
    
    qsort(vec, n, sizeof(int), compare); // Sort the array in ascending order
    int ans = 1000000001; // Initialize the answer with a large number
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i + k - 1 < n; i++) { // Iterate through the sorted array
        int diff = vec[i + k - 1] - vec[i]; // Calculate the difference between the max and min in the subarray
        if (diff < ans) { // Update the answer if the current difference is smaller
            ans = diff;
        }
    }
    
    printf("%d\n", ans); // Output the minimum difference
    free(vec); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
