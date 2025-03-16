#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, X, i, j, k;
    scanf("%d %d", &N, &X);
    int A[N], S[N];
    
    // Read the list of integers A
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    // Calculate the cumulative sum of the list A
    S[0] = A[0];
    for (i = 1; i < N; i++) {
        S[i] = S[i - 1] + A[i];
    }
    
    // Initialize the answer to a very large number (infinity)
    int ans = 1e9;
    
    // Iterate through the cumulative sums with an index starting from 1
    for (k = 1; k <= N; k++) {
        int E = k * X + 2 * (S[N - k - 1] - (k > 1 ? S[k - 2] : 0));
        
        // Update the answer with the minimum value found so far
        if (E < ans) {
            ans = E;
        }
    }
    
    // Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
    printf("%d\n", ans + N * X + 5 * S[N - 1]);
    
    return 0;
}
