#include <stdio.h>
#include <stdlib.h>

// Function to cut a list of tuples based on a given index
int** cut(int** array, int* size, int index) {
    if (index < 1) {
        return NULL;
    }
    if (index <= array[0][0]) {
        int** new_array = (int**)malloc(1 * sizeof(int*));
        new_array[0] = (int*)malloc(2 * sizeof(int));
        new_array[0][0] = index;
        new_array[0][1] = array[0][1];
        return new_array;
    }
    for (int i = *size - 1; i > 0; i--) {
        if (array[i - 1][0] < index) {
            int** new_array = (int**)malloc((i) * sizeof(int*));
            for (int j = 0; j < i; j++) {
                new_array[j] = (int*)malloc(2 * sizeof(int));
                new_array[j][0] = array[j][0];
                new_array[j][1] = array[j][1];
            }
            new_array[i - 1] = (int*)malloc(2 * sizeof(int));
            new_array[i - 1][0] = index;
            new_array[i - 1][1] = array[i][1];
            return new_array;
        }
    }
    return array;
}

// Function to check if a given value of K is possible by modifying the list dp
int is_possible(int* A, int size, int K) {
    int** dp = (int**)malloc(1 * sizeof(int*));
    dp[0] = (int*)malloc(2 * sizeof(int));
    dp[0][0] = A[0];
    dp[0][1] = 0;
    for (int i = 1; i < size; i++) {
        if (A[i] <= dp[0][0]) {
            dp = cut(dp, &size, A[i]);
        } else {
            int** new_dp = (int**)malloc((size + 1) * sizeof(int*));
            for (int j = 0; j < size; j++) {
                new_dp[j] = (int*)malloc(2 * sizeof(int));
                new_dp[j][0] = dp[j][0];
                new_dp[j][1] = dp[j][1];
            }
            new_dp[size] = (int*)malloc(2 * sizeof(int));
            new_dp[size][0] = A[i];
            new_dp[size][1] = 0;
            free(dp);
            dp = new_dp;
            size++;
        }
        int is_added = 0;
        for (int j = size - 1; j >= 0; j--) {
            if (dp[j][1] < K - 1) {
                dp = cut(dp, &size, dp[j][0] - 1);
                int** new_dp = (int**)malloc((size + 1) * sizeof(int*));
                for (int k = 0; k < size; k++) {
                    new_dp[k] = (int*)malloc(2 * sizeof(int));
                    new_dp[k][0] = dp[k][0];
                    new_dp[k][1] = dp[k][1];
                }
                new_dp[size] = (int*)malloc(2 * sizeof(int));
                new_dp[size][0] = dp[j][0];
                new_dp[size][1] = dp[j][1] + 1;
                free(dp);
                dp = new_dp;
                size++;
                if (dp[size - 1][0] < A[i]) {
                    int** new_dp2 = (int**)malloc((size + 1) * sizeof(int*));
                    for (int k = 0; k < size; k++) {
                        new_dp2[k] = (int*)malloc(2 * sizeof(int));
                        new_dp2[k][0] = dp[k][0];
                        new_dp2[k][1] = dp[k][1];
                    }
                    new_dp2[size] = (int*)malloc(2 * sizeof(int));
                    new_dp2[size][0] = A[i];
                    new_dp2[size][1] = 0;
                    free(dp);
                    dp = new_dp2;
                    size++;
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
int bis(int* A, int size, int x, int y) {
    if (y == x + 1) {
        return y;
    } else if (is_possible(A, size, (x + y) / 2)) {
        return bis(A, size, x, (x + y) / 2);
    } else {
        return bis(A, size, (x + y) / 2, y);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int* A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int result = bis(A, N, 0, N);
    printf("%d\n", result);

    free(A);
    return 0;
}
