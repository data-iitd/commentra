#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation and other utilities
#include <stdbool.h> // Including library for boolean type
#include <string.h> // Including string library for string manipulation

#define MAX_N 100000 // Defining a maximum size for the array

int main() { // Defining the main function
    int n; // Variable to store the number of elements
    long k; // Variable to store the long integer k
    long arr[MAX_N]; // Array to store long integer values
    bool set[MAX_N] = {false}; // Boolean array to simulate a HashSet for unique values
    int count = 0; // Initializing the count variable to 0

    scanf("%d", &n); // Reading the first integer value n from standard input
    scanf("%ld", &k); // Reading the long integer value k from standard input

    for (int i = 0; i < n; i++) { // Iterating through the array arr from index 0 to n-1
        scanf("%ld", &arr[i]); // Reading a long integer value and storing it in arr[i]
    }

    // Sorting the array using qsort
    qsort(arr, n, sizeof(long), (int (*)(const void *, const void *))compare);

    for (int i = 0; i < n; i++) { // Iterating through the sorted arr array
        if (arr[i] % k != 0) { // Checking if arr[i] is not divisible by k
            count++; // Incrementing the count variable
            set[arr[i]] = true; // Marking the value as present in the set
        } else if (!set[arr[i] / k]) { // Checking if arr[i] is divisible by k and its quotient is not present in the set
            count++; // Incrementing the count variable
            set[arr[i]] = true; // Marking the value as present in the set
        }
    }

    printf("%d\n", count); // Printing the count value to standard output
    return 0; // Returning 0 to indicate successful execution
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(long *)a - *(long *)b); // Comparing two long integers
}

