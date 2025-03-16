#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[4];
    
    // Read input
    for (int i = 0; i < 4; i++) {
        scanf("%d", &A[i]);
    }

    // Check the conditions
    if (A[1] <= A[2] || A[3] <= A[0]) {
        printf("0\n");
    } else {
        // Sort the array
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
        // Print the difference
        printf("%d\n", A[2] - A[1]);
    }

    return 0;
}

// <END-OF-CODE>
