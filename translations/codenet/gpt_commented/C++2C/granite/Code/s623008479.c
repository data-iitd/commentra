
#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library for memory allocation and sorting

int cmpfunc (const void * a, const void * b) {
   return (*(int*)a - *(int*)b); // Define a comparison function for sorting
}

int main() {
    int n, k; // Declare variables for the number of elements and the number of largest elements to sum
    scanf("%d %d", &n, &k); // Read the values of n and k from standard input

    int *l = (int*)malloc(n * sizeof(int)); // Allocate memory for the vector of size n
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]); // Read each element into the vector
    }

    qsort(l, n, sizeof(int), cmpfunc); // Sort the vector in ascending order

    int ans = 0; // Initialize a variable to hold the sum of the largest k elements
    for (int i = 0; i < k; i++) {
        ans += l[n - 1 - i]; // Add the largest k elements to ans
    }

    printf("%d\n", ans); // Output the result

    free(l); // Free the allocated memory
    return 0;
}
