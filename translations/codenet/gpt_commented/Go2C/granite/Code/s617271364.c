
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define global variables
int N, ss, ans, A, B, C;

// Function to read the next line of input
char* nextLine() {
    char* line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1) {
        return NULL;
    }
    return line;
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return a < b? a : b;
}

// Function to find the absolute value of an integer
int abs(int a) {
    return a < 0? a * -1 : a;
}

// Function to perform depth-first search to find the optimal distribution
void dfs(int* dp, int times, int* arr) {
    // Base case: if all items have been considered
    if (times >= N) {
        ans = min(ans, calc(dp, arr)); // Calculate cost and update answer
        return;
    }

    // Explore all possible distributions (0 to 3)
    for (int i = 0; i < 4; i++) {
        dp[times] = i; // Assign current item to one of the four groups
        dfs(dp, times + 1, arr); // Recur for the next item
    }
}

// Function to calculate the cost of the current distribution
int calc(int* dp, int* arr) {
    int cost = 0, AA = 0, BB = 0, CC = 0; // Initialize cost and group sums

    // Count items in each group and calculate their sums
    int memo[4] = {0};
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

int main() {
    // Read input values and split them into a slice of strings
    char* X = nextLine();
    char** Xs = strsplit(X, " ");

    // Parse the first four values from the input
    N = atoi(Xs[0]); // Number of elements
    A = atoi(Xs[1]); // Target value A
    B = atoi(Xs[2]); // Target value B
    C = atoi(Xs[3]); // Target value C

    // Initialize arrays for dynamic programming and results
    int arr[N]; // Array to hold input values
    int dp[N]; // DP array to store current state
    ans = 10000; // Initialize answer with a large value
    ss = A + B + C; // Sum of target values

    // Read N integers from input and populate the array
    for (int i = 0; i < N; i++) {
        char* Y = nextLine();
        char** Ys = strsplit(Y, " ");
        arr[i] = atoi(Ys[0]); // Store the integer in the array
    }

    // Perform depth-first search to find the optimal distribution
    dfs(dp, 0, arr);

    // Output the final answer
    printf("%d\n", ans);

    return 0;
}

// Additional utility functions and types can be defined below

