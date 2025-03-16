#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Read input variables
    int N, X;
    scanf("%d %d", &N, &X);
    
    // Allocate memory for the array A
    int *A = (int *)malloc(N * sizeof(int));
    
    // Read the array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Create the S array using accumulate logic
    long long *S = (long long *)malloc(N * sizeof(long long));
    S[0] = A[0];
    for (int i = 1; i < N; i++) {
        S[i] = S[i - 1] + A[i];
    }

    // Initialize ans with a large value
    long long ans = LLONG_MAX;

    // Iterate through each element s in the list S
    for (int k = 1; k <= N / 2; k++) {
        // Calculate the energy consumption E for the current index k
        long long E = k * X;

        // Calculate the sum for the energy consumption
        for (int j = N - 2 * k - 1; j >= 0; j -= k) {
            E += 2 * S[j];
        }

        // Update the minimum energy consumption ans if the current energy consumption E is smaller
        if (E < ans) {
            ans = E;
        }
    }

    // Print the result
    printf("%lld\n", ans + N * X + 5 * S[N - 1]);

    // Free allocated memory
    free(A);
    free(S);

    return 0;
}

// <END-OF-CODE>
