#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N, X;
    
    // Read input values: N (number of elements), X (a constant)
    scanf("%d %d", &N, &X);
    
    // Allocate memory for the array A
    int *A = (int *)malloc(N * sizeof(int));
    long long *S = (long long *)malloc(N * sizeof(long long));
    
    // Read the list of integers A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    // Calculate the cumulative sum of the list A
    S[0] = A[0];
    for (int i = 1; i < N; i++) {
        S[i] = S[i - 1] + A[i];
    }
    
    // Initialize the answer to a very large number (infinity)
    long long ans = LLONG_MAX;

    // Iterate through the cumulative sums with an index starting from 1
    for (int k = 1; k <= N; k++) {
        long long E = k * X;
        
        // Calculate the second part of the expression E
        for (int j = N - 2 * k - 1; j >= 0; j -= k) {
            E += 2 * S[j];
        }
        
        // Update the answer with the minimum value found so far
        if (E < ans) {
            ans = E;
        }
    }

    // Print the final result
    printf("%lld\n", ans + N * X + 5 * S[N - 1]);

    // Free allocated memory
    free(A);
    free(S);
    
    return 0;
}

// <END-OF-CODE>
