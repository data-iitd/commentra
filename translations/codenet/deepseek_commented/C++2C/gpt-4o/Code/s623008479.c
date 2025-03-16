#include <stdio.h>   // Include the standard I/O header for input and output
#include <stdlib.h>  // Include the standard library for memory allocation and sorting
<<<<<<< HEAD
#include <string.h>  // Include the string header for using qsort
=======
#include <string.h>  // Include the string header for using memcpy
>>>>>>> 98c87cb78a (data updated)

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Compare two integers
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k); // Read the values of n and k from the input
    int *l = (int*)malloc(n * sizeof(int)); // Allocate memory for the array of size n
    for(int i = 0; i < n; i++) {
        scanf("%d", &l[i]); // Read the elements of the array l
    }

    qsort(l, n, sizeof(int), compare); // Sort the array l in ascending order

    int ans = 0; // Initialize ans to 0
    for(int i = 0; i < k; i++) {
        ans += l[n - 1 - i]; // Sum the last k elements of the sorted array
    }
    printf("%d\n", ans); // Print the result

    free(l); // Free the allocated memory
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
