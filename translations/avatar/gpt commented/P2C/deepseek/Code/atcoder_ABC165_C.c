#include <stdio.h>
#include <stdlib.h>

// Function to solve the problem
void solve(int N, int M, int Q, int* a, int* b, int* c, int* d) {
    // Initialize the result variable to store the maximum score
    int res = 0;
    
    // Recursive function to explore combinations of numbers
    void rec(int* A, int len) {
        // Base case: if the length of A equals N, calculate the score
        if (len == N) {
            int ans = 0;
            // Check each query to see if it contributes to the score
            for (int i = 0; i < Q; i++) {
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
        int last_max = (len == 0) ? 1 : A[len - 1];
        
        // Iterate through possible values to add to the combination
        for (int i = last_max; i <= M; i++) {
            A[len] = i;  // Add the number to the combination
            rec(A, len + 1);  // Recursively call with the new number added to A
        }
    }
    
    // Initialize the array to hold the current combination
    int* A = (int*)malloc(N * sizeof(int));
    
    // Start the recursive exploration with an empty list
    rec(A, 0);
    
    // Free the allocated memory
    free(A);
    
    // Print the maximum score found
    printf("%d\n", res);
}

// Main function to read input and call solve
int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    
    // Initialize arrays to hold the query parameters
    int* a = (int*)malloc(Q * sizeof(int));
    int* b = (int*)malloc(Q * sizeof(int));
    int* c = (int*)malloc(Q * sizeof(int));
    int* d = (int*)malloc(Q * sizeof(int));
    
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
