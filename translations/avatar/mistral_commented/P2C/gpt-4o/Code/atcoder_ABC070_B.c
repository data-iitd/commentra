#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[4];

    // Create a list 'A' from the input, which is a sequence of space-separated integers
    for (int i = 0; i < 4; i++) {
        scanf("%d", &A[i]);
    }

    // Check if the second or third element of the list 'A' is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        // If the condition is true, print '0'
        printf("0\n");
    } else {
        // If the condition is false, sort the list 'A' in ascending order
        for (int i = 0; i < 4 - 1; i++) {
            for (int j = 0; j < 4 - i - 1; j++) {
                if (A[j] > A[j + 1]) {
                    // Swap A[j] and A[j + 1]
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }

        // Print the difference between the third and second elements of the sorted list
        printf("%d\n", A[2] - A[1]);
    }

    return 0;
}
// <END-OF-CODE>
