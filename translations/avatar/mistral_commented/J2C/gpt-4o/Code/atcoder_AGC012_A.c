#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation and sorting
#include <string.h> // Including string library for comparison function

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Comparing two integers
}

int main() {
    int n; // Variable to store the number of elements
    scanf("%d", &n); // Reading the number of elements in the array from standard input
    int array[3 * n]; // Creating an integer array of size 3 times the number of elements

    // Initializing the array with input values
    for (int i = 0; i < 3 * n; i++) {
        scanf("%d", &array[i]); // Reading each element into the array
    }

    // Sorting the array in ascending order
    qsort(array, 3 * n, sizeof(int), compare); // Using qsort to sort the array

    int head = 3 * n - 2; // Index of the last element to be considered in the current iteration
    long long res = 0; // Result variable to store the sum of the last two elements in each subarray

    // Calculating the sum of the last two elements in each subarray of size n and adding it to the result
    for (int i = 0; i < n; i++) {
        res += array[head]; // Adding the last element of the current subarray to the result
        head -= 2; // Decreasing the index of the last element by 2 to consider the next subarray
    }

    // Printing the result
    printf("%lld\n", res); // Printing the result

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
