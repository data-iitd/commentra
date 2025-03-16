#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements N and the multiplier X
    int N;
    long X;
    scanf("%d %ld", &N, &X);
    
    // Initialize an array to store the elements and a prefix sum array
    long* x = (long*) malloc(N * sizeof(long));
    long* xsum = (long*) malloc((N + 1) * sizeof(long));
    
    // Read the elements into the array and compute the prefix sums
    for (int i = 0; i < N; i++) {
        scanf("%ld", &x[i]);
        xsum[i + 1] = xsum[i] + x[i];
    }
    
    // Initialize the answer with the cost of processing all elements with the base cost
    long ans = X * N + 5 * xsum[N];
    
    // Iterate through possible splits of the array
    for (int i = 1; i < N; i++) {
        // Calculate the cost for the current split
        long cost = X * i + 5 * (xsum[N] - xsum[N - i]);
        
        // Incrementally add costs based on the current split
        for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) {
            // If the current cost exceeds the best answer found, break out of the loop
            if (cost > ans) {
                break;
            }
            // Update the cost based on the prefix sums
            cost += j * (xsum[k] - xsum[k - i]);
        }
        // Update the answer with the minimum cost found
        ans = min(ans, cost);
    }
    
    // Output the final answer, which includes the base cost
    printf("%ld\n", ans + N * X);
    
    return 0;
}

