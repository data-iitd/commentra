#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables to store input values
int N, ss, ans, A, B, C;

// Function to calculate the cost based on the chosen combinations
int calc(int dp[], int arr[]) {
    int cost, AA, BB, CC;

    // Create a memoization array to count the occurrences of each choice
    int memo[4];
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
    cost = abs(A - AA) + abs(B - BB) + abs(C - CC);

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

// Depth-first search function to explore different combinations of choices
void dfs(int dp[], int times, int arr[]) {
    if (times >= N) {
        ans = min(ans, calc(dp, arr));
        return;
    }

    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(dp, times + 1, arr);
    }
}

// Helper functions to read input, calculate minimum, and absolute value
int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int abs(int a) {
    if (a < 0) {
        return a * -1;
    }
    return a;
}

int main() {
    // Read the input values for N, A, B, and C
    char X[100];
    scanf("%s", X);
    N = atoi(strtok(X, " "));
    A = atoi(strtok(NULL, " "));
    B = atoi(strtok(NULL, " "));
    C = atoi(strtok(NULL, " "));

    // Initialize the array to store the values and a dp array for choices
    int arr[N];
    int dp[N];
    ans = 10000;
    ss = A + B + C;

    // Read the array values from input
    for (int i = 0; i < N; i++) {
        char Y[100];
        scanf("%s", Y);
        arr[i] = atoi(strtok(Y, " "));
    }

    // Start the depth-first search to find the minimum cost
    dfs(dp, 0, arr);

    // Print the minimum cost found
    printf("%d\n", ans);

    return 0;
}

