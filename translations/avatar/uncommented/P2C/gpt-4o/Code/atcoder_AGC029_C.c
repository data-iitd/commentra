#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first;
    int second;
} Pair;

Pair* cut(Pair* array, int* size, int index) {
    if (index < 1) {
        return NULL;
    }
    if (index <= array[0].first) {
        Pair* result = malloc(sizeof(Pair));
        result[0] = (Pair){index, array[0].second};
        *size = 1;
        return result;
    }
    for (int i = *size - 1; i > 0; i--) {
        if (array[i - 1].first < index) {
            Pair* result = malloc((*size + 1) * sizeof(Pair));
            for (int j = 0; j < i; j++) {
                result[j] = array[j];
            }
            result[i] = (Pair){index, array[i].second};
            for (int j = i + 1; j <= *size; j++) {
                result[j] = array[j - 1];
            }
            *size += 1;
            return result;
        }
    }
    return NULL;
}

int is_possible(int K, Pair* A, int N) {
    Pair* dp = malloc(N * sizeof(Pair));
    dp[0] = (Pair){A[0].first, 0};
    int dp_size = 1;

    for (int i = 1; i < N; i++) {
        int a = A[i].first;
        if (a <= dp[dp_size - 1].first) {
            dp = cut(dp, &dp_size, a);
        } else {
            dp[dp_size++] = (Pair){a, 0};
        }
        int is_added = 0;
        for (int j = dp_size - 1; j >= 0; j--) {
            if (dp[j].second < K - 1) {
                dp = cut(dp, &dp_size, dp[j].first - 1);
                dp[dp_size - 1] = (Pair){dp[j].first, dp[j].second + 1};
                if (dp[dp_size - 1].first < a) {
                    dp[dp_size++] = (Pair){a, 0};
                }
                is_added = 1;
                break;
            }
        }
        if (!is_added) {
            free(dp);
            return 0;
        }
    }
    free(dp);
    return 1;
}

int bis(int x, int y, Pair* A, int N) {
    if (y == x + 1) {
        return y;
    } else if (is_possible((x + y) / 2, A, N)) {
        return bis(x, (x + y) / 2, A, N);
    } else {
        return bis((x + y) / 2, y, A, N);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Pair* A = malloc(N * sizeof(Pair));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i].first);
        A[i].second = 0; // Initialize second value if needed
    }

    // Process the array A to remove non-increasing elements
    Pair* temp = malloc(N * sizeof(Pair));
    int temp_size = 0;
    temp[temp_size++] = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i].first <= temp[temp_size - 1].first) {
            continue;
        }
        temp[temp_size++] = A[i];
    }
    free(A);
    A = temp;

    int result = bis(0, temp_size, A, temp_size);
    printf("%d\n", result);

    free(A);
    return 0;
}

// <END-OF-CODE>
