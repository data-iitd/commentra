<<<<<<< HEAD
#include <stdio.h>   // Include the standard I/O library for input and output
=======
#include <stdio.h>   // Include the standard input/output library
>>>>>>> 98c87cb78a (data updated)
#include <stdlib.h>  // Include the standard library for memory allocation and sorting
#include <string.h>  // Include the string library for memory manipulation

// Comparison function for qsort
int compare(const void *a, const void *b) {
<<<<<<< HEAD
    return (*(int *)a - *(int *)b); // Compare two integers
=======
    return (*(int*)a - *(int*)b); // Compare two integers
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int n, k; // Declare variables for the number of elements and the number of largest elements to sum
    scanf("%d %d", &n, &k); // Read the values of n and k from standard input

<<<<<<< HEAD
    int *l = (int *)malloc(n * sizeof(int)); // Dynamically allocate an array of size n to store the elements
=======
    int *l = (int*)malloc(n * sizeof(int)); // Allocate memory for the array of size n
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]); // Read each element into the array
    }

    qsort(l, n, sizeof(int), compare); // Sort the array in ascending order

    int ans = 0; // Initialize a variable to hold the sum of the largest k elements
    for (int i = 0; i < k; i++) {
        ans += l[n - 1 - i]; // Add the largest k elements to ans
    }

    printf("%d\n", ans); // Output the result

    free(l); // Free the allocated memory
<<<<<<< HEAD
    return 0; // Return 0 to indicate successful completion
=======
    return 0; // Return success
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
