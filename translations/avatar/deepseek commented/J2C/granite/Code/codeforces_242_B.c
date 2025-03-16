
#include <stdio.h> // Including standard input/output library
#include <stdlib.h> // Including standard library for dynamic memory allocation
#include <limits.h> // Including limits for maximum and minimum values

int main() {
    // Declaring variables to store the number of elements and the minimum and maximum values
    int n, left = INT_MAX, right = INT_MIN;

    // Reading the integer value of n from standard input
    scanf("%d", &n);

    // Declaring dynamic arrays to store the elements of lists a and b
    int *a = (int *) malloc(n * sizeof(int));
    int *b = (int *) malloc(n * sizeof(int));

    // Looping through n elements to read and update the lists and variables
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Reading element into array a
        scanf("%d", &b[i]); // Reading element into array b
        left = (left < a[i])? left : a[i]; // Updating left with the minimum value
        right = (right > b[i])? right : b[i]; // Updating right with the maximum value
    }

    // Looping through the arrays to find the target element
    for (int i = 0; i < n; i++) {
        if (left == a[i] && right == b[i]) {
            printf("%d\n", i + 1); // Printing the 1-based index of the target element
            free(a); // Freeing the memory allocated for array a
            free(b); // Freeing the memory allocated for array b
            return 0; // Returning from the function after finding the target
        }
    }

    // If no such element is found, print -1
    printf("-1\n");
    free(a); // Freeing the memory allocated for array a
    free(b); // Freeing the memory allocated for array b
    return 0;
}
