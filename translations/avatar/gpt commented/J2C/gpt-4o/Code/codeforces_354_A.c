#include <stdio.h>
#include <limits.h>

int main() {
    // Read the number of elements (N) and the values for L, R, QL, QR
    int N, L, R, QL, QR;
    scanf("%d %d %d %d %d", &N, &L, &R, &QL, &QR);
    
    // Initialize an array to hold the weights and a prefix sum array
    int W[N]; // Array to store weights
    long sum[N + 1]; // Prefix sum array
    sum[0] = 0; // Initialize the first element of the prefix sum array
    
    // Read weights and compute the prefix sum
    for (int n = 0; n < N; n++) {
        scanf("%d", &W[n]); // Read weight for each element
        sum[n + 1] = sum[n] + W[n]; // Update prefix sum
    }
    
    // Initialize a variable to track the minimum cost
    long min = LONG_MAX; // Start with the maximum possible value
    
    // Iterate over possible counts of elements assigned to the left side
    for (int firstR = 0; firstR <= N; firstR++) {
        int lCount = firstR; // Count of elements on the left
        int rCount = N - lCount; // Count of elements on the right
        
        // Calculate the candidate cost based on current left and right counts
        long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;
        
        // Calculate excess counts for left and right
        int llCount = (lCount > rCount + 1) ? (lCount - rCount - 1) : 0; // Excess left count
        int rrCount = (rCount > lCount + 1) ? (rCount - lCount - 1) : 0; // Excess right count
        
        // Add additional costs for excess elements
        cand += llCount * QL; // Add cost for excess left elements
        cand += rrCount * QR; // Add cost for excess right elements
        
        // Update the minimum cost found
        if (cand < min) {
            min = cand; // Keep track of the minimum cost
        }
    }
    
    // Output the minimum cost
    printf("%ld\n", min); // Print the result
    return 0;
}

// <END-OF-CODE>
