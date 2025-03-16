#include <stdio.h>  // Include the standard input-output library for standard input and output operations.
#include <stdlib.h> // Include the standard library for using functions like qsort for sorting.

// Comparison function for qsort to sort integers in ascending order.
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);  // Read the number of elements N from the standard input.
    int X[N], Y[N];   // Declare arrays X and Y of size N to store the elements.

    // Read N elements into array X and simultaneously copy them to array Y.
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        Y[i] = X[i];
    }

    // Sort the array Y in ascending order using qsort.
    qsort(Y, N, sizeof(int), compare);

    // Calculate the median of the sorted array Y. The median is the middle element for odd N, and the average of the two middle elements for even N.
    int y = Y[N / 2];

    // Iterate through each element in array X and output the appropriate median value based on the comparison with y.
    for (int i = 0; i < N; i++) {
        if (X[i] < y) {
            printf("%d\n", y);  // If the element in X is less than the median, output the median.
        } else {
            printf("%d\n", y - 1);  // Otherwise, output the median minus one.
        }
    }

    return 0;  // Return 0 to indicate successful execution.
}
