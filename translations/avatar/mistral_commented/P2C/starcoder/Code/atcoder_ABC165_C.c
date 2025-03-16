#include <stdio.h>
#include <stdlib.h>

// Function to solve the problem
void solve(int N, int M, int Q, int a[], int b[], int c[], int d[]) {
    // Initialize result to 0
    int res = 0;

    // Helper function to calculate the answer recursively
    void rec(int A[]) {
        // Nonlocal variable to update the result from the recursive calls
        int *res = &res;

        // Base case: if all elements of A are placed, calculate the answer
        if (A[0] == N) {
            int ans = 0;
            for (int i = 0; i < Q; i++) {
                // Check if the condition is satisfied
                if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                    ans += d[i];
                }
            }
            // Update the result with the maximum answer
            *res = max(*res, ans);
            return;
        }

        // Recursive call: try placing elements from last_max to M
        int last_max = 1;
        if (A[0] > 0) {
            last_max = A[0];
        }
        for (int i = last_max; i <= M; i++) {
            rec(A + 1);
        }
    }

    // Call the helper function with an empty list
    rec(malloc(sizeof(int) * 1));

    // Print the result
    printf("%d\n", res);
}

// Main function to read input and call the solve function
int main() {
    // Function to generate tokens from standard input
    char *next_token() {
        static char buf[1024];
        static int i = 0;
        if (i == 0) {
            fgets(buf, 1024, stdin);
        }
        char *ret = buf + i;
        i = i + strlen(ret) + 1;
        return ret;
    }

    // Read number of test cases
    int N = atoi(next_token());

    // Read number of elements in the array and number of queries
    int M = atoi(next_token());
    int Q = atoi(next_token());

    // Read the arrays a, b, c, and d
    int a[Q];
    int b[Q];
    int c[Q];
    int d[Q];
    for (int i = 0; i < Q; i++) {
        a[i] = atoi(next_token());
        b[i] = atoi(next_token());
        c[i] = atoi(next_token());
        d[i] = atoi(next_token());
    }

    // Call the solve function with the given input
    solve(N, M, Q, a, b, c, d);

    // Print the end of code marker
    printf("