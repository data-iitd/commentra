#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &A[i]);
    }

    // Checking if the second element is less than or equal to the third element or if the fourth element is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        printf("0\n");  // If either condition is true, print 0
    } else {
        // Sorting the array
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (A[i] > A[j]) {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
        }
        printf("%d\n", A[2] - A[1]);  // Printing the difference between the third and second elements
    }

    return 0;
}
