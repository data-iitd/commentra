#include <stdio.h>
#include <stdlib.h>

// Function to calculate the greatest common divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Read an integer input N, which represents the number of elements in the list
    int N;
    scanf("%d", &N);

    // Allocate memory for the array A
    int *A = (int *)malloc(N * sizeof(int));

    // Read the elements into the array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Calculate the GCD of all elements in the array A
    int result = A[0];
    for (int i = 1; i < N; i++) {
        result = gcd(result, A[i]);
    }

    // Print the calculated GCD
    printf("%d\n", result);

    // Free the allocated memory
    free(A);

    return 0;
}

// <END-OF-CODE>
