#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 100000
#define MAX_Q 100000

int main() {
    // Read the values of N, M, and Q from input
    int N = 0;
    int M = 0;
    int Q = 0;
    scanf("%d %d %d", &N, &M, &Q);
    
    // Initialize lists to hold the query parameters
    int a[MAX_Q];
    int b[MAX_Q];
    int c[MAX_Q];
    int d[MAX_Q];
    
    // Read the query parameters from input
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    
    // Initialize the result variable to store the maximum score
    int res = 0;
    
    // Recursive function to explore combinations of numbers
    void rec(int A[], int n) {
        // Base case: if the length of A equals N, calculate the score
        if (n == N) {
            int ans = 0;
            // Check each query to see if it contributes to the score
            for (int i = 0; i < Q; i++) {
                if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                    ans += d[i];  // Add the score from the query if it matches
                }
            }
            // Update the maximum score found
            res = max(res, ans);
            return;
        }
        
        // Determine the starting point for the next number to be added
        int last_max = 1 if (n == 0) else A[n - 1];
        
        // Iterate through possible values to add to the combination
        for (int i = last_max; i <= M; i++) {
            int new_A[MAX_N];
            memcpy(new_A, A, n * sizeof(int));
            new_A[n] = i;
            rec(new_A, n + 1);  // Recursively call with the new number added to A
        }
    }
    
    // Start the recursive exploration with an empty list
    int A[MAX_N];
    rec(A, 0);
    
    // Print the maximum score found
    printf("%d\n", res);
    return 0;
}

