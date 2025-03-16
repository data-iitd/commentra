#include <stdio.h>
#include <stdlib.h>

// Function to compute the GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the GCD of an array of numbers
int array_gcd(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
    }
    return result;
}

int main() {
    int N;
    scanf("%d", &N);  // Take an integer input N
    int *A = (int *)malloc(N * sizeof(int));  // Dynamically allocate memory for the array A

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);  // Take space-separated integers as input
    }

    int result = array_gcd(A, N);  // Compute the GCD of the array
    printf("%d\n", result);  // Print the computed GCD

    free(A);  // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
