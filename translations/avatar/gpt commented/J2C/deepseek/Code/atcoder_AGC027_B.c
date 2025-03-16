#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void solve() {
    int N;
    long long X;
    
    // Read the number of elements N and the multiplier X
    scanf("%d %lld", &N, &X);
    
    // Initialize an array to store the elements and a prefix sum array
    long long x[N];
    long long xsum[N + 1];
    
    // Read the elements into the array and compute the prefix sums
    xsum[0] = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &x[i]);
        xsum[i + 1] = xsum[i] + x[i];
    }
    
    // Initialize the answer with the cost of processing all elements with the base cost
    long long ans = X * N + 5 * xsum[N];
    
    // Iterate through possible splits of the array
    for (int i = 1; i < N; i++) {
        // Calculate the cost for the current split
        long long cost = X * i + 5 * (xsum[N] - xsum[N - i]);
        
        // Incrementally add costs based on the current split
        for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) {
            // If the current cost exceeds the best answer found, break out of the loop
            if (cost > ans) {
                break;
            }
            // Update the cost based on the prefix sums
            cost += j * (xsum[k] - xsum[k - i > 0 ? k - i : 0]);
        }
        // Update the answer with the minimum cost found
        if (cost < ans) {
            ans = cost;
        }
    }
    
    // Output the final answer, which includes the base cost
    printf("%lld\n", ans + N * X);
}

int main() {
    // Call the solve method to execute the program
    solve();
    return 0;
}
