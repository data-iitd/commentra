#include <stdio.h>
#include <stdlib.h>

// Define a function to calculate the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N;

    // Ask the user for the number of elements in the list
    scanf("%d", &N);

    // Get a list of integers from the user input
    int* A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Initialize the result with the first element of the list
    int result = A[0];

    // Use a loop to calculate the GCD of all integers in the list A
    for (int i = 1; i < N; i++) {
        result = gcd(A[i], result);
    }

    // Print the result, which is the GCD of all the integers in the list A
    printf("%d\n", result);

    // Free the allocated memory
    free(A);

    return 0;
}
