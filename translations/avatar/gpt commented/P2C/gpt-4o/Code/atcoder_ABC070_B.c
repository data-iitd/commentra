#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int A[4];

    // Read a line of input and store it in the array A
    for (int i = 0; i < 4; i++) {
        scanf("%d", &A[i]);
    }

    // Check if the second element is less than or equal to the third element,
    // or if the fourth element is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        // If the condition is true, print 0
        printf("0\n");
    } else {
        // If the condition is false, sort the array A in ascending order
        qsort(A, 4, sizeof(int), compare);
        // Calculate the difference between the largest and the second largest elements in the sorted array and print the result
        printf("%d\n", A[2] - A[1]);
    }

    return 0;
}

// <END-OF-CODE>
