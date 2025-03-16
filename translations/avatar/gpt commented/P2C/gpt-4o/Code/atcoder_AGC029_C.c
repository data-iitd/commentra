#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int count;
} Element;

Element* cut(Element* array, int* size, int index) {
    if (index < 1) {
        *size = 0;
        return NULL;
    }
    
    if (index <= array[0].value) {
        Element* result = malloc(sizeof(Element));
        result[0].value = index;
        result[0].count = array[0].count;
        *size = 1;
        return result;
    }
    
    for (int i = *size - 1; i > 0; i--) {
        if (array[i - 1].value < index) {
            Element* result = malloc((*size + 1) * sizeof(Element));
            for (int j = 0; j < i; j++) {
                result[j] = array[j];
            }
            result[i].value = index;
            result[i].count = array[i].count;
            *size = i + 1;
            return result;
        }
    }
    
    return NULL; // Should not reach here
}

int is_possible(int* A, int N, int K) {
    Element* dp = malloc(N * sizeof(Element));
    dp[0].value = A[0];
    dp[0].count = 0;
    int dp_size = 1;

    for (int i = 1; i < N; i++) {
        int a = A[i];
        if (a <= dp[dp_size - 1].value) {
            int new_size;
            Element* new_dp = cut(dp, &dp_size, a);
            if (new_dp) {
                free(dp);
                dp = new_dp;
            }
        } else {
            dp[dp_size].value = a;
            dp[dp_size].count = 0;
            dp_size++;
        }

        int is_added = 0;

        for (int j = dp_size - 1; j >= 0; j--) {
            if (dp[j].count < K - 1) {
                int new_size;
                Element* new_dp = cut(dp, &dp_size, dp[j].value - 1);
                if (new_dp) {
                    free(dp);
                    dp = new_dp;
                }
                dp[dp_size].value = dp[j].value;
                dp[dp_size].count = dp[j].count + 1;
                dp_size++;

                if (dp[dp_size - 1].value < a) {
                    dp[dp_size].value = a;
                    dp[dp_size].count = 0;
                    dp_size++;
                }

                is_added = 1;
                break;
            }
        }

        if (!is_added) {
            free(dp);
            return 0; // False
        }
    }

    free(dp);
    return 1; // True
}

int bis(int x, int y, int* A, int N) {
    if (y == x + 1) {
        return y;
    } else {
        int mid = (x + y) / 2;
        if (is_possible(A, N, mid)) {
            return bis(x, mid, A, N);
        } else {
            return bis(mid, y, A, N);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int* A = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Filter the list to keep only non-increasing elements
    int* filtered = malloc(N * sizeof(int));
    int filtered_size = 0;
    filtered[filtered_size++] = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i] <= filtered[filtered_size - 1]) {
            filtered[filtered_size++] = A[i];
        }
    }

    int result = bis(0, filtered_size, filtered, filtered_size);
    printf("%d\n", result);

    free(A);
    free(filtered);
    return 0;
}

// <END-OF-CODE>
