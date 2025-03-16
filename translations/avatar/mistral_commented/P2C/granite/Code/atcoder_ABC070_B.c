
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create an array 'A' from the input, which is a sequence of space-separated integers
    int A[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &A[i]);
    }

    // Check if the second or third element of the array 'A' is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        // If the condition is true, print '0'
        printf("0\n");
    } else {
        // If the condition is false, sort the array 'A' in ascending order
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (A[i] > A[j]) {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
        }

        // Print the difference between the third and second elements of the sorted array
        printf("%d\n", A[2] - A[1]);
    }

    return 0;
}
