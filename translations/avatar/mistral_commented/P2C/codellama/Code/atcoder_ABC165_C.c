#include <stdio.h>
#include <stdlib.h>

// Function to solve the problem
void solve(int N, int M, int Q, int a[], int b[], int c[], int d[]) {
    // Initialize result to 0
    int res = 0;

    // Helper function to calculate the answer recursively
    void rec(int A[], int n) {
        // Nonlocal variable to update the result from the recursive calls
        nonlocal res;

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
            res = max(res, ans);
            return;
        }

        // Recursive call: try placing elements from last_max to M
        int last_max = 1;
        if (n > 0) {
            last_max = A[n - 1];
        }
        for (int i = last_max; i <= M; i++) {
            A[n] = i;
            rec(A, n + 1);
        }
    }

    // Call the helper function with an empty list
    int A[N];
    rec(A, 0);

    // Print the result
    printf("%d\n", res);
}

// Main function to read input and call the solve function
int main() {
    // Function to generate tokens from standard input
    char* next_token() {
        static char line[100000];
        static char* p = line;
        if (p == line) {
            fgets(line, sizeof(line), stdin);
        }
        while (*p == ' ' || *p == '\t' || *p == '\n') {
            p++;
        }
        char* token = p;
        while (*p != ' ' && *p != '\t' && *p != '\n' && *p != '\0') {
            p++;
        }
        if (*p != '\0') {
            *p = '\0';
            p++;
        }
        return token;
    }

    // Read input tokens
    int N = atoi(next_token());
    int M = atoi(next_token());
    int Q = atoi(next_token());
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

    // End of code
    printf("