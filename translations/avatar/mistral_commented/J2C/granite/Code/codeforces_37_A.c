

#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library for dynamic memory allocation
#include <string.h> // Include the string library for string manipulation functions

int main() {
    int n; // Declare an integer variable to store the number of integers
    scanf("%d", &n); // Read the number of integers from the standard input

    // Declare a pointer to an array of integers
    int *arr = (int *)malloc(n * sizeof(int)); // Allocate memory for an array of n integers

    // Iterate through the given number of integers and read each integer from the standard input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Read the next integer from the standard input and store it in the corresponding index of the array
    }

    // Initialize minimum value and maximum value variables
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        // Update the maximum value if the current element is greater than the maximum value
        max = (arr[i] > max)? arr[i] : max;
    }

    // Print the maximum value and the size of the array
    printf("%d %d\n", max, n);

    // Free the allocated memory for the array
    free(arr);

    return 0; // Return 0 to indicate successful execution of the program
}

These comments should provide a clear understanding of the code's functionality and logic.