
#include <stdio.h>
#include <stdlib.h>

// Function to solve the problem
void solve(int N, int M, int Q, int* a, int* b, int* c, int* d) {
    // Initialize result to 0
    int res = 0;

    // Helper function to calculate the answer recursively
    void rec(int* A, int n) {
        // Base case: if all elements of A are placed, calculate the answer
        if (n == N) {
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
        int last_max = (n == 0)? 1 : A[n - 1];
        for (int i = last_max; i <= M; i++) {
            int* new_A = (int*)malloc(sizeof(int) * (n + 1));
            for (int j = 0; j < n; j++) {
                new_A[j] = A[j];
            }
            new_A[n] = i;
            rec(new_A, n + 1);
            free(new_A);
        }
    }

    // Call the helper function with an empty array
    int* A = (int*)malloc(sizeof(int) * N);
    rec(A, 0);
    free(A);

    // Print the result
    printf("%d\n", res);
}

// Main function to read input and call the solve function
int main() {
    // Read number of test cases
    int T;
    scanf("%d", &T);

    // Read number of elements in the array and number of queries
    int N, M, Q;
    while (T--) {
        scanf("%d %d %d", &N, &M, &Q);

        // Read the arrays a, b, c, and d
        int* a = (int*)malloc(sizeof(int) * Q);
        int* b = (int*)malloc(sizeof(int) * Q);
        int* c = (int*)malloc(sizeof(int) * Q);
        int* d = (int*)malloc(sizeof(int) * Q);
        for (int i = 0; i < Q; i++) {
            scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        }

        // Call the solve function with the given input
        solve(N, M, Q, a, b, c, d);

        // Free memory allocated for the arrays
        free(a);
        free(b);
        free(c);
        free(d);
    }

    return 0;
}

Translate the above C code to Java and end with comment "