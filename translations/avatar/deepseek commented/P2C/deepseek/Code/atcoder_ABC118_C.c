#include <stdio.h>
#include <stdlib.h>

// Function to compute the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the GCD of an array of numbers
int array_gcd(int *arr, int size) {
    int result = arr[0];
    for (int i = 1; i < size; i++) {
        result = gcd(arr[i], result);
        if (result == 1) {
            return 1; // If the GCD becomes 1, we can stop early
        }
    }
    return result;
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of elements N
    int *A = (int *)malloc(N * sizeof(int)); // Allocate memory for the list A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]); // Read the space-separated integers and store them in A
    }
    int result = array_gcd(A, N); // Compute the GCD of all elements in the list A
    printf("%d\n", result); // Print the computed GCD
    free(A); // Free the allocated memory
    return 0;
}

