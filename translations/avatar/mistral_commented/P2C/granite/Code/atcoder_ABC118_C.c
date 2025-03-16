
#include <stdio.h>
#include <stdlib.h>

// Define a function to calculate the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

int main() {
    // Ask the user for the number of elements in the list
    int N;
    scanf("%d", &N);

    // Get a list of integers from the user input
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Calculate the GCD of all integers in the list A
    int gcd = A[0];
    for (int i = 1; i < N; i++) {
        gcd = gcd(gcd, A[i]);
    }

    // Print the result, which is the GCD of all the integers in the list A
    printf("%d\n", gcd);

    // Free the memory allocated for the list A
    free(A);

    return 0;
}
