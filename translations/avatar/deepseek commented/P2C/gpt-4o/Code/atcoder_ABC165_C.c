#include <stdio.h>
#include <stdlib.h>

int res = 0;  // Global variable to store the maximum score

void rec(int *A, int len, int N, int M, int Q, int *a, int *b, int *c, int *d) {
    if (len == N) {  // If the sequence length is equal to N
        int ans = 0;  // Initialize the answer for this sequence
        for (int i = 0; i < Q; i++) {  // Iterate over all constraints
            if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {  // Check if the constraint is satisfied
                ans += d[i];  // Add the value of the constraint to the answer
            }
        }
        if (ans > res) {  // Update the result with the maximum score
            res = ans;
        }
        return;
    }
    int last_max = (len == 0) ? 1 : A[len - 1];  // Determine the starting point for the next number
    for (int i = last_max; i <= M; i++) {  // Generate the next number in the sequence
        A[len] = i;  // Add the next number to the sequence
        rec(A, len + 1, N, M, Q, a, b, c, d);  // Recursive call
    }
}

void solve(int N, int M, int Q, int *a, int *b, int *c, int *d) {
    int *A = (int *)malloc(N * sizeof(int));  // Allocate memory for the sequence
    rec(A, 0, N, M, Q, a, b, c, d);  // Start the recursive function with an empty list
    printf("%d\n", res);  // Print the result
    free(A);  // Free the allocated memory
}

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);  // Read the values of N, M, and Q
    int *a = (int *)malloc(Q * sizeof(int));  // Allocate memory for list a
    int *b = (int *)malloc(Q * sizeof(int));  // Allocate memory for list b
    int *c = (int *)malloc(Q * sizeof(int));  // Allocate memory for list c
    int *d = (int *)malloc(Q * sizeof(int));  // Allocate memory for list d

    for (int i = 0; i < Q; i++) {
        scanf("%d", &a[i]);  // Read the list a
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &b[i]);  // Read the list b
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &c[i]);  // Read the list c
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &d[i]);  // Read the list d
    }

    solve(N, M, Q, a, b, c, d);  // Call the solve function with the input values

    free(a);  // Free the allocated memory for list a
    free(b);  // Free the allocated memory for list b
    free(c);  // Free the allocated memory for list c
    free(d);  // Free the allocated memory for list d

    return 0;
}

// <END-OF-CODE>
