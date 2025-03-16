#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

<<<<<<< HEAD
#define MAX_N 100 // Assuming a maximum size for N

// Global variables
int N, A, B, C, ans, ss;
int arr[MAX_N];
int dp[MAX_N];

// Function prototypes
void dfs(int times);
int calc();
=======
int N, ss, ans, A, B, C;

// Function prototypes
void dfs(int *dp, int times, int *arr);
int calc(int *dp, int *arr);
>>>>>>> 98c87cb78a (data updated)
int min(int a, int b);
int abs(int a);

int main() {
    // Read input values
    scanf("%d %d %d %d", &N, &A, &B, &C);
    
<<<<<<< HEAD
    // Read N integers from input
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize answer with a large value
    ans = 10000;
    ss = A + B + C;

    // Perform depth-first search to find the optimal distribution
    dfs(0);

    // Output the final answer
    printf("%d\n", ans);
    
=======
    // Initialize arrays for dynamic programming and results
    int *arr = (int *)malloc(N * sizeof(int)); // Array to hold input values
    int *dp = (int *)malloc(N * sizeof(int));  // DP array to store current state
    ans = 10000; // Initialize answer with a large value
    ss = A + B + C; // Sum of target values

    // Read N integers from input and populate the array
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]); // Store the integer in the array
    }

    // Perform depth-first search to find the optimal distribution
    dfs(dp, 0, arr);

    // Output the final answer
    printf("%d\n", ans);

    // Free allocated memory
    free(arr);
    free(dp);

>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// Recursive function to explore all distributions of items
<<<<<<< HEAD
void dfs(int times) {
    // Base case: if all items have been considered
    if (times >= N) {
        ans = min(ans, calc()); // Calculate cost and update answer
=======
void dfs(int *dp, int times, int *arr) {
    // Base case: if all items have been considered
    if (times >= N) {
        ans = min(ans, calc(dp, arr)); // Calculate cost and update answer
>>>>>>> 98c87cb78a (data updated)
        return;
    }

    // Explore all possible distributions (0 to 3)
    for (int i = 0; i < 4; i++) {
        dp[times] = i; // Assign current item to one of the four groups
<<<<<<< HEAD
        dfs(times + 1); // Recur for the next item
=======
        dfs(dp, times + 1, arr); // Recur for the next item
>>>>>>> 98c87cb78a (data updated)
    }
}

// Calculate the cost of the current distribution
<<<<<<< HEAD
int calc() {
=======
int calc(int *dp, int *arr) {
>>>>>>> 98c87cb78a (data updated)
    int cost = 0, AA = 0, BB = 0, CC = 0; // Initialize cost and group sums
    int memo[4] = {0}; // Count items in each group

    // Count items in each group and calculate their sums
    for (int i = 0; i < N; i++) {
        memo[dp[i]]++; // Count items in each group
        if (dp[i] == 1) {
            AA += arr[i]; // Sum for group A
        } else if (dp[i] == 2) {
            BB += arr[i]; // Sum for group B
        } else if (dp[i] == 3) {
            CC += arr[i]; // Sum for group C
        }
    }

    // Calculate the cost based on the differences from target values
    cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

    // Penalize for missing groups and excess items
    for (int i = 1; i < 4; i++) {
        int a = memo[i];
        if (a < 1) {
            cost += 10000; // High penalty for missing group
        } else {
            cost += (a - 1) * 10; // Penalty for excess items
        }
    }

    return cost; // Return the calculated cost
}

// Helper function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Helper function to find the absolute value of an integer
int abs(int a) {
    return (a < 0) ? -a : a;
}

<<<<<<< HEAD
// <END-OF-CODE>
=======
// Additional utility functions and types can be defined below

>>>>>>> 98c87cb78a (data updated)
