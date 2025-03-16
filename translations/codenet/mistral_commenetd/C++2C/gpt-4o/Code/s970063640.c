#include <stdio.h>
#include <stdlib.h> // Include the stdlib library for sorting

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Comparison function for qsort
}

int main() {
    // Declare and initialize variables
    int n; // Number of elements in the array
    scanf("%d", &n); // Read the number of elements from the user
    int a; // Size of the subarray to be summed
    scanf("%d", &a); // Read the size of the subarray from the user
    int sum = 0; // Initialize the sum variable to zero
    int *s = (int*)malloc(n * sizeof(int)); // Dynamically allocate an array of size n

    // Read the elements of the array from the user
    for(int i = 0; i < n; i++) {
        scanf("%d", &s[i]); // Read the i-th element of the array
    }

    // Sort the array in ascending order
    qsort(s, n, sizeof(int), compare); // Sort the array using qsort

    // Calculate the sum of the last 'a' elements of the sorted array
    for(int i = n - 1; i > n - a - 1; i--) {
        sum += s[i]; // Add the current element to the sum
    }

    // Print the result
    printf("%d\n", sum); // Print the sum of the last 'a' elements

    free(s); // Free the dynamically allocated memory
    return 0; // Indicate successful termination of the program
}

// <END-OF-CODE>
