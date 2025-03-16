#include <stdio.h>
#include <stdlib.h>

int* read_input(int* size) {
    int capacity = 10;
    int* array = malloc(capacity * sizeof(int));
    *size = 0;

    while (1) {
        int num;
        if (scanf("%d", &num) != 1) break;
        if (*size >= capacity) {
            capacity *= 2;
            array = realloc(array, capacity * sizeof(int));
        }
        array[(*size)++] = num;
    }
    return array;
}

int* modify_list(int* A, int size, int* new_size) {
    int* modified = malloc(size * sizeof(int));
    modified[0] = A[0];
    int count = 1;

    for (int i = 1; i < size; i++) {
        if (A[i - 1] >= A[i]) {
            modified[count++] = A[i];
        }
    }
    *new_size = count;
    return modified;
}

typedef struct {
    int value;
    int count;
} Tuple;

Tuple* cut(Tuple* array, int* length, int index) {
    if (index < 1) {
        *length = 0;
        return NULL;
    }
    if (index <= array[0].value) {
        Tuple* result = malloc(sizeof(Tuple));
        result[0] = (Tuple){index, array[0].count};
        *length = 1;
        return result;
    }
    for (int i = *length - 1; i > 0; i--) {
        if (array[i - 1].value < index) {
            Tuple* result = malloc((*length + 1) * sizeof(Tuple));
            for (int j = 0; j < i; j++) {
                result[j] = array[j];
            }
            result[i] = (Tuple){index, array[i].count};
            *length = i + 1;
            return result;
        }
    }
    return NULL;
}

int is_possible(int* A, int N, int K) {
    Tuple* dp = malloc(N * sizeof(Tuple));
    dp[0] = (Tuple){A[0], 0};
    int dp_length = 1;

    for (int i = 1; i < N; i++) {
        int a = A[i];
        if (a <= dp[dp_length - 1].value) {
            dp_length = cut(dp, &dp_length, a);
        } else {
            dp[dp_length++] = (Tuple){a, 0};
        }
        int is_added = 0;

        for (int j = dp_length - 1; j >= 0; j--) {
            if (dp[j].count < K - 1) {
                dp = cut(dp, &dp_length, dp[j].value - 1);
                dp[dp_length++] = (Tuple){dp[j].value, dp[j].count + 1};
                if (dp[dp_length - 1].value < a) {
                    dp[dp_length++] = (Tuple){a, 0};
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

int bis(int x, int y, int N, int* A) {
    if (y == x + 1) {
        return y;
    } else if (is_possible(A, N, (x + y) / 2)) {
        return bis(x, (x + y) / 2, N, A);
    } else {
        return bis((x + y) / 2, y, N, A);
    }
}

int main() {
    int size;
    int* A = read_input(&size);
    int new_size;
    int* modified_A = modify_list(A, size, &new_size);
    int result = bis(0, new_size, new_size, modified_A);
    printf("%d\n", result);
    
    free(A);
    free(modified_A);
    return 0;
}

// <END-OF-CODE>
