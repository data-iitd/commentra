
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 100000

int N;
int h[MAX_N];
int dp[MAX_N];

int min(int a, int b) {
    return a < b ? a : b;
}

int abs(int a) {
    return a < 0 ? -a : a;
}

int main() {
    // Read the number of elements
    scanf("%d", &N);
    // Read the heights into a slice
    for (int i = 0; i < N; i++) {
        scanf("%d", &h[i]);
    }

    // Initialize a dynamic programming slice to store minimum costs
    for (int i = 0; i < N; i++) {
        dp[i] = 0; // Set initial values to zero
    }
    
    // Base case: cost to jump from the first to the second height
    dp[1] = abs(h[0] - h[1]);

    // Fill the dp slice with minimum costs for each position
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }

    // Output the minimum cost to reach the last height
    printf("%d\n", dp[N-1]);

    return 0;
}

