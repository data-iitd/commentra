#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the minimum value among a variable number of integers
int min(int count, ...) {
    if (count == 0) {
        fprintf(stderr, "len == 0\n");
        exit(EXIT_FAILURE); // Exit if no arguments are provided
    }
    
    va_list args;
    va_start(args, count);
    
    int r = va_arg(args, int); // Initialize result with the first element
    for (int i = 1; i < count; i++) {
        int current = va_arg(args, int);
        if (current < r) { // Update result if a smaller element is found
            r = current;
        }
    }
    
    va_end(args);
    return r; // Return the minimum value
}

int main() {
    int H, N, A, B; // Declare variables to store input values
    scanf("%d %d", &H, &N); // Read the values of H and N from standard input
    
    int *dp = (int *)malloc((H + 10001) * sizeof(int)); // Create a dynamic array for dynamic programming
    for (int l = 1; l < H + 10001; l++) {
        dp[l] = INT_MAX; // Initialize the array with a large value
    }
    
    int amax = 0; // Initialize variable to keep track of the maximum attack value
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A, &B); // Read the attack value A and the cost B for each attack
        if (A >= amax) {
            amax = A; // Update amax if the current attack value is greater than or equal to the current amax
        }
        dp[A] = min(2, dp[A], B); // Update the cost for attack value A
<<<<<<< HEAD
        for (int j = A + 1; j <= H + amax + 1; j++) {
=======
        for (int j = A + 1; j <= H + A + 1; j++) {
>>>>>>> 98c87cb78a (data updated)
            dp[j] = min(3, dp[j], dp[j - A] + B); // Update the cost for all possible health values using the current attack
        }
    }
    
    int result = min(amax + 1, dp[H], dp[H + 1], dp[H + 2], dp[H + 3]); // Find the minimum cost to reduce health H to zero or below
    printf("%d\n", result); // Print the minimum cost
    free(dp); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
