#include <stdio.h> // Including the standard input-output library
#include <stdlib.h> // Including the standard library for memory allocation and other utilities
#include <stdbool.h> // Including the library for boolean type
#include <string.h> // Including the string library for sorting

// Function to compare two long integers for qsort
int compare(const void *a, const void *b) {
    return (*(long *)a - *(long *)b);
}

int main() { // Defining the main function
    int N; // Variable to store the number of elements
    long x; // Variable to store the target value

    scanf("%d", &N); // Reading the number of elements from standard input
    scanf("%ld", &x); // Reading the target value from standard input

    long *sweet = (long *)malloc(N * sizeof(long)); // Dynamically allocating memory for N long integers

    for (int i = 0; i < N; i++) { // Loop to read N elements
        scanf("%ld", &sweet[i]); // Reading each element from standard input
    }

    qsort(sweet, N, sizeof(long), compare); // Sorting the array in ascending order using qsort

    int num = 0; // Variable to keep track of the number of elements that can be subtracted from x

    for (int i = 0; i < N; i++) { // Loop to find the number of elements that can be subtracted from x
        if (x - sweet[num] >= 0) { // Checking if x is greater than or equal to the current element
            x -= sweet[num]; // Subtracting the current element from x
            num++; // Incrementing the num variable
        } else { // If x is less than the current element
            break; // Exiting the loop
        }
    }

    if ((num == N) && (x > 0)) { // Checking if all elements have been subtracted and x is still greater than 0
        num -= 1; // Decrementing num by 1
    }

    printf("%d\n", num); // Printing the number of elements that can be subtracted from x

    free(sweet); // Freeing the allocated memory
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
