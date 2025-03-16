
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read a line of input, split it into components, and convert each component to an integer, storing them in an array A
    int A[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &A[i]);
    }

    // Check if the second element is less than or equal to the third element, or if the fourth element is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        // If the condition is true, print 0
        printf("0\n");
    } else {
        // If the condition is false, sort the array A in ascending order
        qsort(A, 4, sizeof(int), cmpfunc);
        // Calculate the difference between the largest and the second largest elements in the sorted array and print the result
        printf("%d\n", A[3] - A[2]);
    }

    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

