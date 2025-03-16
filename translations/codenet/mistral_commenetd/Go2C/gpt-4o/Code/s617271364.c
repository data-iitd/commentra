#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 100

// Global variables
int N, A, B, C, ss, ans;
int arr[MAX_N];
int dp[MAX_N];

// Function prototypes
void dfs(int times);
int calc();
int min(int a, int b);
int abs(int a);
char* nextLine();

int main() {
    // Read the first line which contains the number of tests and the number of elements in the array
    char *line = nextLine();
    sscanf(line, "%d %d %d %d", &N, &A, &B, &C);
    ss = A + B + C;

    // Read the next N lines which contain the elements of the array
    for (int i = 0; i < N; i++) {
        line = nextLine();
        sscanf(line, "%d", &arr[i]);
    }

    // Initialize the answer variable
    ans = 10000;

    // Call the dfs function to find the minimum cost
    dfs(0);

    // Print the answer
    printf("%d\n", ans);

    return 0;
}

// dfs function is used for depth-first search
void dfs(int times) {
    // Base case: if the number of elements processed is equal to N, calculate the cost and update the answer if necessary
    if (times >= N) {
        ans = min(ans, calc());
        return;
    }

    // Recursive case: try all possible values for the current element
    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(times + 1);
    }
}

// calc function is used to calculate the cost
int calc() {
    int cost = 0, AA = 0, BB = 0, CC = 0;
    int memo[4] = {0};

    // Iterate through the dp array and update the variables
    for (int i = 0; i < N; i++) {
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
        int a = memo[i];
        if (a < 1) {
            cost += 10000;
        } else {
            cost += (a - 1) * 10;
        }
    }

    // Return the cost
    return cost;
}

// Helper functions
int min(int a, int b) {
    return (a < b) ? a : b;
}

int abs(int a) {
    return (a < 0) ? -a : a;
}

char* nextLine() {
    static char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    return buffer;
}
