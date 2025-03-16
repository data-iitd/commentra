#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation
#include <limits.h> // Including limits for integer types

int main() {
    int N; // Variable to store the number of elements

    // Taking input for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    // Allocating memory for the array of integers
    int *n = (int *)malloc(N * sizeof(int));

    // Taking input for the elements
    printf("Enter the elements separated by spaces: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }

    // Initializing a counter 'a' to count the number of elements that are less than the current element
    int a = 1;

    // Initializing 'pos' to keep track of the position of the last element that was smaller
    int pos = 0;

    // Looping through the array starting from the second element
    for (int i = 1; i < N; i++) {
        // Checking if the current element is smaller than the element at 'pos'
        if (n[pos] > n[i]) {
            a++; // Incrementing the counter if the condition is met
            pos = i; // Updating 'pos' to the current index
        }
    }

    // Printing the final count of elements that were smaller than the previous ones
    printf("%d\n", a);

    // Freeing the allocated memory
    free(n);

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
