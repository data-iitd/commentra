#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation and other utilities
#include <stdbool.h> // Including library for boolean type

// Function to compare two integers for use in qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Returning the difference for sorting
}

// Main function is the entry point of the C application
int main() {
    int N; // Variable to store the number of elements
    scanf("%d", &N); // Reading the number of elements in the array

    int *arr = (int*)malloc(N * sizeof(int)); // Dynamically allocating memory for the array

    // Using for loop to read and store elements in the array
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]); // Reading an integer and storing it in the array at the current index
    }

    int sum = 0; // Initializing sum variable to 0

    // Sorting the array
    qsort(arr, N, sizeof(int), compare);

    // Using for loop to iterate through the array
    for (int i = 0; i < N; i++) {
        // Checking if the current element is smaller than or equal to the current element in the sorted array
        if (arr[i] <= arr[i]) {
            sum++; // Incrementing sum if the condition is true
        }
    }

    // Freeing the allocated memory for the array
    free(arr);

    // Printing the sum as the solution
    printf("%d\n", sum);

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
