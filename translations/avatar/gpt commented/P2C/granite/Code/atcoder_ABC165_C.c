
#include <stdio.h>
#include <stdlib.h>

void solve(int N, int M, int Q, int *a, int *b, int *c, int *d) {
    // Initialize the result variable to store the maximum score
    int res = 0;
    
    // Recursive function to explore combinations of numbers
    void rec(int *A, int len) {
        int i;
        int ans = 0;
        
        // Base case: if the length of A equals N, calculate the score
        if (len == N) {
            for (i = 0; i < Q; i++) {
                if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                    ans += d[i];  // Add the score from the query if it matches
                }
            }
            // Update the maximum score found
            if (ans > res) {
                res = ans;
            }
            return;
        }
        
        // Determine the starting point for the next number to be added
        int last_max = (len == 0)? 1 : A[len - 1];
        
        // Iterate through possible values to add to the combination
        for (i = last_max; i <= M; i++) {
            int *new_A = (int *)malloc(sizeof(int) * (len + 1));
            for (int j = 0; j < len; j++) {
                new_A[j] = A[j];
            }
            new_A[len] = i;
            rec(new_A, len + 1);
            free(new_A);
        }
    }
    
    // Start the recursive exploration with an empty list
    int *A = (int *)malloc(sizeof(int) * 0);
    rec(A, 0);
    free(A);
    
    // Print the maximum score found
    printf("%d\n", res);
}

int main() {
    // Generator function to iterate through input tokens
    int N, M, Q;
    int *a, *b, *c, *d;
    
    // Read the values of N, M, and Q from input
    scanf("%d %d %d", &N, &M, &Q);
    
    // Initialize lists to hold the query parameters
    a = (int *)malloc(sizeof(int) * Q);
    b = (int *)malloc(sizeof(int) * Q);
    c = (int *)malloc(sizeof(int) * Q);
    d = (int *)malloc(sizeof(int) * Q);
    
    // Read the query parameters from input
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    
    // Call the solve function with the parsed input
    solve(N, M, Q, a, b, c, d);
    
    // Free the allocated memory for the query parameters
    free(a);
    free(b);
    free(c);
    free(d);
    
    return 0;
}

