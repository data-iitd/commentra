#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N;
    int A[5];
    int i;
    int minA = 1000000; // Initialize with a large number
    int result;

    // Read input
    scanf("%d", &N);
    for (i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
        if (A[i] < minA) {
            minA = A[i];
        }
    }

    // Calculate the result
    result = (int)ceil((double)N / minA) + 4;

    // Print the result
    printf("%d\n", result);

    return 0;
}
