#include <stdio.h>
#include <stdlib.h>

int N, M, Q;
int *a, *b, *c, *d;
int res = 0;

// Function to solve the problem
void rec(int *A, int len) {
    // Base case: if all elements of A are placed, calculate the answer
    if (len == N) {
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
    int last_max = (len == 0) ? 1 : A[len - 1];
    for (int i = last_max; i <= M; i++) {
        A[len] = i; // Place the current element
        rec(A, len + 1); // Recur with the new length
    }
}

// Main function to read input and call the solve function
int main() {
    // Read number of elements in the array and number of queries
    scanf("%d %d %d", &N, &M, &Q);

    // Allocate memory for arrays a, b, c, and d
    a = (int *)malloc(Q * sizeof(int));
    b = (int *)malloc(Q * sizeof(int));
    c = (int *)malloc(Q * sizeof(int));
    d = (int *)malloc(Q * sizeof(int));

    // Read the arrays a, b, c, and d
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }

    // Allocate memory for the array A
    int *A = (int *)malloc(N * sizeof(int));

    // Call the helper function with an empty list
    rec(A, 0);

    // Print the result
    printf("%d\n", res);

    // Free allocated memory
    free(a);
    free(b);
    free(c);
    free(d);
    free(A);

    return 0;
}

// <END-OF-CODE>
