

#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[4];  // Declaring an array of 4 integers
    for (int i = 0; i < 4; i++) {
        scanf("%d", &A[i]);  // Taking input from the user and storing it in the array
    }

    // Checking if the second element is less than or equal to the third element or if the fourth element is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        printf("0\n");  // If either condition is true, print 0
    } else {
        qsort(A, 4, sizeof(int), NULL);  // Sorting the array
        printf("%d\n", A[2] - A[1]);  // Printing the difference between the third and second elements
    }

    return 0;
}

