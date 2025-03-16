

#include <stdio.h>
#include <stdlib.h>

// Function to cut a list of tuples based on a given index
void cut(int **array, int *length, int index) {
    if (index < 1) {
        *length = 0;
        return;
    }
    if (index <= (*array)[0][0]) {
        (*array)[0][0] = index;
        *length = 1;
        return;
    }
    int i;
    for (i = *length - 1; i > 0; i--) {
        if ((*array)[i - 1][0] < index) {
            (*array)[i][0] = index;
            *length = i + 1;
            return;
        }
    }
}

// Function to check if a given value of K is possible by modifying the list dp
int is_possible(int *A, int N, int K) {
    int **dp = (int **)malloc(sizeof(int *) * N);
    int *length = (int *)malloc(sizeof(int));
    int i;
    for (i = 0; i < N; i++) {
        dp[i] = (int *)malloc(sizeof(int) * 2);
    }
    dp[0][0] = A[0];
    dp[0][1] = 0;
    *length = 1;
    for (i = 1; i < N; i++) {
        if (A[i] <= dp[0][0]) {
            cut(dp, length, A[i]);
        } else {
            dp[*length][0] = A[i];
            dp[*length][1] = 0;
            *length += 1;
        }
        int is_added = 0;
        int j;
        for (j = *length - 1; j >= 0; j--) {
            if (dp[j][1] < K - 1) {
                cut(dp, length, dp[j][0] - 1);
                dp[*length][0] = dp[j][0];
                dp[*length][1] = dp[j][1] + 1;
                if (dp[*length][0] < A[i]) {
                    dp[*length + 1][0] = A[i];
                    dp[*length + 1][1] = 0;
                    *length += 2;
                }
                is_added = 1;
                break;
            }
        }
        if (!is_added) {
            return 0;
        }
    }
    return 1;
}

// Function to perform a binary search to find the maximum possible value of K
int bis(int *A, int N) {
    int x = 0;
    int y = N;
    while (y!= x + 1) {
        int m = (x + y) / 2;
        if (is_possible(A, N, m)) {
            x = m;
        } else {
            y = m;
        }
    }
    return x;
}

int main() {
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(sizeof(int) * N);
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int result = bis(A, N);
    printf("%d\n", result);
    return 0;
}

