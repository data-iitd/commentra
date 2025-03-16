#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define input function
char* input() {
    int size = 1000;
    char* line = (char*)malloc(size * sizeof(char));
    fgets(line, size, stdin);
    return line;
}

// Define time_value struct
typedef struct {
    int time;
    int value;
} time_value;

// Define dp matrix
int** dp;

// Define N and T
int N, T;

// Define time_value list
time_value* time_value;

// Define function to sort time_value based on their VAL (end time)
int compare(const void* a, const void* b) {
    return ((time_value*)b)->value - ((time_value*)a)->value;
}

// Define function to calculate maximum value
int calculate_max_val(int n, int t) {
    if (n == 0) {
        return 0;
    }
    if (time_value[n].time > t) {
        return dp[n-1][t];
    }
    return max(dp[n-1][t], time_value[n].value + dp[n-1][t-time_value[n].time]);
}

// Define main function
int main() {
    // Initialize variables
    N = T = 0;

    // Read N and T
    char* line = input();
    sscanf(line, "%d %d", &N, &T);

    // Initialize time_value list
    time_value = (time_value*)malloc((N+1) * sizeof(time_value));

    // Read time_value for each activity
    for (int i = 1; i <= N; i++) {
        line = input();
        sscanf(line, "%d %d", &time_value[i].time, &time_value[i].value);
    }

    // Sort time_value based on their VAL (end time)
    qsort(time_value+1, N, sizeof(time_value), compare);

    // Initialize dp matrix
    dp = (int**)malloc((N+1) * sizeof(int*));
    for (int i = 0; i <= N; i++) {
        dp[i] = (int*)malloc(T * sizeof(int));
    }

    // Initialize first row and column of dp matrix
    for (int t = 0; t < T; t++) {
        dp[0][t] = 0;
    }
    dp[0][0] = 0;
    for (int n = 1; n <= N; n++) {
        dp[n][0] = 0;
    }

    // Fill dp matrix
    for (int n = 1; n <= N; n++) {
        for (int t = 1; t < T; t++) {
            dp[n][t] = calculate_max_val(n, t);
        }
    }

    // Calculate maximum value that can be obtained
    int val_acum = time_value[N].value;
    int t = T - 1;
    int max_val = val_acum + dp[N-1][t];

    // Calculate maximum value by considering all activities
    for (int n = N-1; n >= 1; n--) {
        val_acum += time_value[n].value;
        t -= time_value[n+1].time;
        if (t < 0) {
            break;
        }
        else {
            max_val = max(max_val, val_acum + dp[n-1][t]);
        }
    }

    // Print the maximum value
    printf("%d\n", max_val);

    // Free memory
    free(time_value);
    for (int i = 0; i <= N; i++) {
        free(dp[i]);
    }
    free(dp);

    return 0;
}

