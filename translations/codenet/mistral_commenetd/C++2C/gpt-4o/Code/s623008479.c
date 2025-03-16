#include <stdio.h>    // Include the standard input/output library
#include <stdlib.h>   // Include the standard library for memory allocation and sorting
#include <string.h>   // Include the string library for memory manipulation

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k; // Declare two integer variables, n and k

    scanf("%d %d", &n, &k); // Read the number of elements and the size of the subarray

    int *l = (int*)malloc(n * sizeof(int)); // Dynamically allocate an array of size n

    for(int i = 0; i < n; i++) { // Read each element into the array
        scanf("%d", &l[i]);
    }

    qsort(l, n, sizeof(int), compare); // Sort the array in ascending order

    int ans = 0; // Initialize an integer variable ans to 0

    for(int i = 0; i < k; i++) { // Sum the last k elements (largest elements)
        ans += l[n - 1 - i];
    }

    printf("%d\n", ans); // Output the result

    free(l); // Free the allocated memory
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
