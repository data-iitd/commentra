#include <stdio.h>
#include <stdlib.h>

// Function to calculate the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    // Ask the user for the number of elements in the list
    int N;
    scanf("%d", &N);

    // Allocate memory for the list of integers
    int *A = (int *)malloc(N * sizeof(int));

    // Get a list of integers from the user input
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Calculate the GCD of all integers in the list A
    int result = A[0];
    for (int i = 1; i < N; i++) {
        result = gcd(result, A[i]);
    }

    // Print the result, which is the GCD of all the integers in the list A
    printf("%d\n", result);

    // Free the allocated memory
    free(A);

    return 0;
}

// <END-OF-CODE>
