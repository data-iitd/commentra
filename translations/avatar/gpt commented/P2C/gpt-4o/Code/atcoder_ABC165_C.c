#include <stdio.h>
#include <stdlib.h>

int res = 0; // Global variable to store the maximum score

void rec(int *A, int len, int N, int M, int Q, int *a, int *b, int *c, int *d) {
    // Base case: if the length of A equals N, calculate the score
    if (len == N) {
        int ans = 0;
        // Check each query to see if it contributes to the score
        for (int i = 0; i < Q; i++) {
            if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                ans += d[i]; // Add the score from the query if it matches
            }
        }
        // Update the maximum score found
        if (ans > res) {
            res = ans;
        }
        return;
    }

    // Determine the starting point for the next number to be added
    int last_max = (len == 0) ? 1 : A[len - 1];

    // Iterate through possible values to add to the combination
    for (int i = last_max; i <= M; i++) {
        A[len] = i; // Add the new number to A
        rec(A, len + 1, N, M, Q, a, b, c, d); // Recursively call with the new number added to A
    }
}

void solve(int N, int M, int Q, int *a, int *b, int *c, int *d) {
    int *A = (int *)malloc(N * sizeof(int)); // Allocate memory for A
    rec(A, 0, N, M, Q, a, b, c, d); // Start the recursive exploration
    printf("%d\n", res); // Print the maximum score found
    free(A); // Free allocated memory
}

int main() {
    int N, M, Q;

    // Read the values of N, M, and Q from input
    scanf("%d %d %d", &N, &M, &Q);

    // Initialize arrays to hold the query parameters
    int *a = (int *)malloc(Q * sizeof(int));
    int *b = (int *)malloc(Q * sizeof(int));
    int *c = (int *)malloc(Q * sizeof(int));
    int *d = (int *)malloc(Q * sizeof(int));

    // Read the query parameters from input
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }

    // Call the solve function with the parsed input
    solve(N, M, Q, a, b, c, d);

    // Free allocated memory for query parameters
    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}

// <END-OF-CODE>
