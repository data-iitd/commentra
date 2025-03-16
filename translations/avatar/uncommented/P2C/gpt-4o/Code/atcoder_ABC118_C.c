#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate GCD of an array
int gcd_of_array(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
    }
    return result;
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of elements
    int *A = (int *)malloc(N * sizeof(int)); // Dynamically allocate memory for the array

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]); // Read the elements of the array
    }

    int result = gcd_of_array(A, N); // Calculate GCD of the array
    printf("%d\n", result); // Print the result

    free(A); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
