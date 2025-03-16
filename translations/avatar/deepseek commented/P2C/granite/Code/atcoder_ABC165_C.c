

#include <stdio.h>
#include <stdlib.h>

void solve(int N, int M, int Q, int *a, int *b, int *c, int *d) {
    int res = 0;  // Initialize the result variable to store the maximum score

    // Define the recursive function to generate sequences
    void rec(int *A, int len) {
        if (len == N) {  // If the sequence length is equal to N
            int ans = 0;  // Initialize the answer for this sequence
            for (int i = 0; i < Q; i++) {  // Iterate over all constraints
                if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {  // Check if the constraint is satisfied
                    ans += d[i];  // Add the value of the constraint to the answer
                }
            }
            res = (res > ans)? res : ans;  // Update the result with the maximum score
            return;
        }
        int last_max = (len == 0)? 1 : A[len - 1];  // Determine the starting point for the next number
        for (int i = last_max; i <= M; i++) {  // Generate the next number in the sequence
            A[len] = i;
            rec(A, len + 1);
        }
    }

    int *A = (int *)malloc(sizeof(int) * N);  // Allocate memory for the sequence
    rec(A, 0);  // Start the recursive function with an empty list
    printf("%d\n", res);  // Print the result
    free(A);  // Free the allocated memory
    return;
}

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);  // Read the input values
    int *a = (int *)malloc(sizeof(int) * Q);
    int *b = (int *)malloc(sizeof(int) * Q);
    int *c = (int *)malloc(sizeof(int) * Q);
    int *d = (int *)malloc(sizeof(int) * Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);  // Read the lists a, b, c, d
    }
    solve(N, M, Q, a, b, c, d);  // Call the solve function with the input values
    free(a);
    free(b);
    free(c);
    free(d);
    return 0;
}

