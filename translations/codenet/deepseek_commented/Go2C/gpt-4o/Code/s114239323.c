#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read the next integer from the input
int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to read a slice of integers of length N
int* nextInts(int N) {
    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        arr[i] = nextInt();
    }
    return arr;
}

// Utility function to find the absolute value of an integer
int Abs(int a) {
    return a < 0 ? -a : a;
}

// Utility function to find the minimum value in an array of integers
int Min(int a, int b) {
    return a < b ? a : b;
}

// Main function to solve the problem
int main() {
    // Reads the number of steps N
    int N = nextInt();
    
    // Reads the list of heights h
    int* h = nextInts(N);
    
    // Initializes the DP array with zeros
    int* dp = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        dp[i] = 0;
    }
    
    // Sets the cost to reach the second step
    dp[1] = Abs(h[0] - h[1]);
    
    // Computes the minimum cost to reach each step using dynamic programming
    for (int i = 2; i < N; i++) {
        dp[i] = Min(dp[i - 1] + Abs(h[i] - h[i - 1]),
                     dp[i - 2] + Abs(h[i] - h[i - 2]));
    }
    
    // Prints the minimum cost to reach the last step
    printf("%d\n", dp[N - 1]);
    
    // Free allocated memory
    free(h);
    free(dp);
    
    return 0;
}

// <END-OF-CODE>
