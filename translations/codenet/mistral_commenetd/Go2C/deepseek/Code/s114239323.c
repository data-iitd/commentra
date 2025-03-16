#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to read a single string from standard input
char* nextString() {
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    return line;
}

// Helper function to read a single integer from standard input
int nextInt() {
    char *line = nextString();
    return atoi(line);
}

// Helper function to read an array of N integers from standard input
int* nextInts(int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    char *line = nextString();
    char *token = strtok(line, " ");
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(line);
    return arr;
}

// Helper functions to calculate the maximum, minimum, sum, and absolute difference of integers
int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int sum(int *a, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
    }
    return s;
}

int abs(int a) {
    return a < 0 ? -a : a;
}

int main() {
    // Read the number of test cases N from standard input
    int N = nextInt();

    // Read an array h of N integers from standard input
    int *h = nextInts(N);

    // Initialize a dp array of size N with zeros
    int *dp = (int*)calloc(N, sizeof(int));
    if (dp == NULL) {
        perror("calloc");
        exit(EXIT_FAILURE);
    }

    // Set the first element of dp to the absolute difference between the first and second elements of h
    dp[1] = abs(h[0] - h[1]);

    // Iterate over the array h from the second element to the last
    for (int i = 2; i < N; i++) {
        // Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    // Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
    printf("%d\n", dp[N-1]);

    // Free allocated memory
    free(h);
    free(dp);

    return 0;
}
