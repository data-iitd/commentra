#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define INF 10000

int N, A, B, C;
int arr[MAX_N];
int dp[MAX_N];
int ans;

void dfs(int times, int *arr);
int calc(int *dp, int *arr);

int main() {
    // Read the first line which contains the number of tests and the number of elements in the array
    char line[100];
    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " ");
    N = atoi(token);
    token = strtok(NULL, " ");
    A = atoi(token);
    token = strtok(NULL, " ");
    B = atoi(token);
    token = strtok(NULL, " ");
    C = atoi(token);

    // Read the next N lines which contain the elements of the array
    for (int i = 0; i < N; i++) {
        fgets(line, sizeof(line), stdin);
        arr[i] = atoi(line);
    }

    // Initialize the answer variable
    ans = INF;

    // Call the dfs function to find the minimum cost
    dfs(0, arr);

    // Print the answer
    printf("%d\n", ans);

    return 0;
}

// dfs function is used for depth-first search
void dfs(int times, int *arr) {
    // Base case: if the number of elements processed is equal to N, calculate the cost and update the answer if necessary
    if (times >= N) {
        int cost = calc(dp, arr);
        if (cost < ans) {
            ans = cost;
        }
        return;
    }

    // Recursive case: try all possible values for the current element
    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(times + 1, arr);
    }
}

// calc function is used to calculate the cost
int calc(int *dp, int *arr) {
    // Initialize the cost and the variables to store the sum of elements with each value in dp
    int cost = 0;
    int AA = 0, BB = 0, CC = 0;

    // Initialize the memo array to store the number of elements with each value in dp
    int memo[4] = {0};

    // Iterate through the dp array and update the variables
    for (int i = 0; i < N; i++) {
        // Update the variables based on the current value in dp
        int a = dp[i];
        memo[a]++;
        if (a == 1) {
            AA += arr[i];
        } else if (a == 2) {
            BB += arr[i];
        } else if (a == 3) {
            CC += arr[i];
        }
    }

    // Calculate the cost based on the variables
    cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

    // Update the cost based on the number of elements with each value in dp
    for (int i = 1; i < 4; i++) {
        if (memo[i] < 1) {
            cost += INF;
        } else {
            cost += (memo[i] - 1) * 10;
        }
    }

    // Return the cost
    return cost;
}

// Helper functions
int abs(int a) {
    return a < 0 ? -a : a;
}
