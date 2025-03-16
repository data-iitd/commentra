#include <stdio.h>
#include <stdlib.h>

int* A; // Array to store the input elements

int main() {
    int N; // Read the number of elements
    scanf("%d", &N);
    A = (int*)malloc(N * sizeof(int)); // Initialize the array A with size N

    // Read the elements of A from the input
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Arrays to store the prefix and suffix GCDs
    int* L = (int*)malloc(N * sizeof(int));
    int* R = (int*)malloc(N * sizeof(int));

    // Calculate the prefix GCD array L
    L[0] = A[0];
    for (int i = 1; i < N; i++) {
        L[i] = gcd(L[i - 1], A[i]);
    }

    // Calculate the suffix GCD array R
    R[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        R[i] = gcd(R[i + 1], A[i]);
    }

    // Initialize the answer with the maximum of the GCD of the first and last elements of L and R
    int answer = max(L[N - 2], R[1]);

    // Iterate through the array to find the maximum GCD
    for (int i = 1; i < N - 1; i++) {
        answer = max(answer, gcd(L[i - 1], R[i + 1]));
    }

    // Print the final answer
    printf("%d\n", answer);

    // Free the memory allocated for the arrays
    free(L);
    free(R);

    return 0;
}

// Method to calculate the GCD of two numbers
int gcd(int a, int b) {
    int tmp;
    if (b > a) { // Ensure a is greater than b
        tmp = a;
        a = b;
        b = tmp;
    }
    if (b == 0) { // Base case for GCD
        return a;
    }
    int r = -1;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (r != 0); // Continue until r is 0
    return a;
}

// Method to calculate the maximum of two numbers
int max(int a, int b) {
    return a > b ? a : b;
}

