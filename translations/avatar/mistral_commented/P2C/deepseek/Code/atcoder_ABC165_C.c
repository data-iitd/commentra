#include <stdio.h>
#include <stdlib.h>

// Function to solve the problem
void solve(int N, int M, int Q, int* a, int* b, int* c, int* d) {
    // Initialize result to 0
    int res = 0;

    // Helper function to calculate the answer recursively
    void rec(int* A, int index) {
        // Base case: if all elements of A are placed, calculate the answer
        if (index == N) {
            int ans = 0;
            for (int i = 0; i < Q; i++) {
                // Check if the condition is satisfied
                if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                    ans += d[i];
                }
            }
            // Update the result with the maximum answer
            if (ans > res) {
                res = ans;
            }
            return;
        }

        // Recursive call: try placing elements from last_max to M
        int last_max = (index == 0) ? 1 : A[index - 1];
        for (int i = last_max; i <= M; i++) {
            A[index] = i;
            rec(A, index + 1);
        }
    }

    // Allocate memory for the array A
    int* A = (int*)malloc(N * sizeof(int));

    // Call the helper function with the first index
    rec(A, 0);

    // Free the allocated memory
    free(A);

    // Print the result
    printf("%d\n", res);
}

// Main function to read input and call the solve function
int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);

    // Allocate memory for the arrays a, b, c, and d
    int* a = (int*)malloc(Q * sizeof(int));
    int* b = (int*)malloc(Q * sizeof(int));
    int* c = (int*)malloc(Q * sizeof(int));
    int* d = (int*)malloc(Q * sizeof(int));

    // Read the arrays a, b, c, and d
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }

    // Call the solve function with the given input
    solve(N, M, Q, a, b, c, d);

    // Free the allocated memory for the arrays a, b, c, and d
    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}
