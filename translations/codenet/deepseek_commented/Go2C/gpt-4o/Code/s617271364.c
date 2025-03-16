#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int N, ss, ans, A, B, C;

// Function prototypes
void dfs(int *dp, int times, int *arr);
int calc(int *dp, int *arr);
int min(int a, int b);
int abs(int a);

int main() {
    // Read the input values for N, A, B, and C
    scanf("%d %d %d %d", &N, &A, &B, &C);

    // Initialize the array to store the values and a dp array for choices
    int arr[N];
    int dp[N];
    ans = 10000;
    ss = A + B + C;

    // Read the array values from input
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Start the depth-first search to find the minimum cost
    dfs(dp, 0, arr);

    // Print the minimum cost found
    printf("%d\n", ans);
    return 0;
}

// Depth-first search function to explore different combinations of choices
void dfs(int *dp, int times, int *arr) {
    if (times >= N) {
        ans = min(ans, calc(dp, arr));
        return;
    }

    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(dp, times + 1, arr);
    }
}

// Function to calculate the cost based on the chosen combinations
int calc(int *dp, int *arr) {
    int cost = 0, AA = 0, BB = 0, CC = 0;

    // Create a memoization array to count the occurrences of each choice
    int memo[4] = {0};
    for (int i = 0; i < N; i++) {
        memo[dp[i]]++;
        if (dp[i] == 1) {
            AA += arr[i];
        } else if (dp[i] == 2) {
            BB += arr[i];
        } else if (dp[i] == 3) {
            CC += arr[i];
        }
    }
    cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

    // Add additional cost for each choice that appears more than once
    for (int i = 1; i < 4; i++) {
        int a = memo[i];
        if (a < 1) {
            cost += 10000;
        } else {
            cost += (a - 1) * 10;
        }
    }

    return cost;
}

// Helper functions to calculate minimum and absolute value
int min(int a, int b) {
    return (a < b) ? a : b;
}

int abs(int a) {
    return (a < 0) ? -a : a;
}
