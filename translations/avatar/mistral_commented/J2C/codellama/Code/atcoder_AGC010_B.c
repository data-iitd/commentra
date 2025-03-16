
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize scanner to read input from standard input
    int N;
    scanf("%d", &N);

    // Allocate memory for the array A of size N
    int *A = (int *) malloc(N * sizeof(int));

    // Read each element of the array A from standard input
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Check if the conditions for a possible solution are met
    if (possible(N, A)) {
        // Print "YES" if the conditions are met
        printf("YES\n");
    } else {
        // Print "NO" if the conditions are not met
        printf("NO\n");
    }

    // Free memory allocated for the array A
    free(A);

    return 0;
}

// Check if the given conditions for a possible solution are met
int possible(int N, int *A) {
    long sum = 0; // Initialize sum to 0

    // Calculate the sum of all elements in the array A
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }

    // Calculate the expected sum based on the number of elements in the array
    long NS = (long) N * (N + 1) / 2;

    // Check if the sum of all elements is equal to the expected sum
    if (sum % NS != 0) {
        return 0;
    }

    // Calculate the common difference between consecutive elements
    long K = sum / NS;

    // Check each pair of consecutive elements to see if their difference is valid
    for (int i = 0; i < N; i++) {
        int j = (i == 0) ? (N - 1) : (i - 1);
        long d = K - (A[i] - A[j]); // Calculate the difference

        // Check if the difference is valid
        if (d < 0 || d % N != 0) {
            return 0;
        }
    }

    // If all checks pass, return true
    return 1;
}

