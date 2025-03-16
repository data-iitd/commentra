#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); // Read an integer input N (not used in further calculations)

    int a[N]; // Declare an array of integers with size N
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]); // Read the list of integers from input
    }

    int total = 0; // Initialize total for XOR operation
    for (int i = 0; i < N; i++) {
        total ^= a[i]; // Calculate the total using the XOR operation across all elements
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", a[i] ^ total); // Compute the XOR with total and print the results
    }
    printf("\n"); // Print a newline at the end

    return 0;
} // <END-OF-CODE>
