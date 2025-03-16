#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants to represent indices for time and value
#define TIME 0
#define VAL 1

// Read input from standard input
char* input() {
    char* line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    return line;
}

// Read the number of items (N) and the maximum time (T)
void read_input(int* N, int* T) {
    char* line = input();
    sscanf(line, "%d %d", N, T);
}

// Initialize a list to store time and value pairs, starting with a dummy entry
void init_time_value(int** time_value, int N) {
    *time_value = (int*)malloc(sizeof(int) * (N + 1) * 2);
    (*time_value)[0] = -1;
    (*time_value)[1] = -1;
}

// Read the time and value pairs for each item
void read_time_value(int** time_value, int N) {
    for (int i = 1; i <= N; i++) {
        char* line = input();
        sscanf(line, "%d %d", &(*time_value)[i * 2], &(*time_value)[i * 2 + 1]);
    }
}

// Sort the time_value list based on the value (VAL)
void sort_time_value(int* time_value, int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if ((*time_value)[i * 2 + 1] < (*time_value)[j * 2 + 1]) {
                int temp = (*time_value)[i * 2];
                (*time_value)[i * 2] = (*time_value)[j * 2];
                (*time_value)[j * 2] = temp;

                temp = (*time_value)[i * 2 + 1];
                (*time_value)[i * 2 + 1] = (*time_value)[j * 2 + 1];
                (*time_value)[j * 2 + 1] = temp;
            }
        }
    }
}

// Initialize a 2D list for dynamic programming, with -1 as default values
void init_dp(int** dp, int N, int T) {
    *dp = (int*)malloc(sizeof(int) * (N + 1) * T);
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < T; j++) {
            (*dp)[i * T + j] = -1;
        }
    }
}

// Fill the dynamic programming table
void fill_dp(int** dp, int** time_value, int N, int T) {
    // Base case: If no time is available, the maximum value is 0
    for (int t = 0; t < T; t++) {
        (*dp)[0 * T + t] = 0;
    }

    // Fill the dynamic programming table
    for (int n = 1; n <= N; n++) {
        // Base case: If no time is available, the maximum value is 0
        for (int t = 0; t < T; t++) {
            if ((*time_value)[n * 2] > t) {
                (*dp)[n * T + t] = (*dp)[(n - 1) * T + t];
            } else {
                // Choose the maximum between not taking the item and taking it
                (*dp)[n * T + t] = max((*dp)[(n - 1) * T + t], (*time_value)[n * 2 + 1] + (*dp)[(n - 1) * T + t - (*time_value)[n * 2]]);
            }
        }
    }
}

// Initialize the maximum value with the last item's value
void init_val_acum(int* val_acum, int** time_value, int N) {
    *val_acum = (*time_value)[N * 2 + 1];
}

// Backtrack to find the maximum value considering previous items
void backtrack(int* val_acum, int** dp, int** time_value, int N, int T, int* max_val) {
    for (int n = N - 1; n >= 1; n--) {
        *val_acum += (*time_value)[n * 2 + 1];
        T -= (*time_value)[n * 2];

        // If time goes negative, break the loop
        if (T < 0) {
            break;
        } else {
            // Update the maximum value if a better option is found
            *max_val = max(*max_val, *val_acum + (*dp)[(n - 1) * T + T]);
        }
    }
}

// Print the maximum value achievable within the given time
void print_max_val(int* max_val) {
    printf("%d\n", *max_val);
}

int main() {
    int N, T;
    read_input(&N, &T);

    int* time_value;
    init_time_value(&time_value, N);
    read_time_value(&time_value, N);
    sort_time_value(time_value, N);

    int* dp;
    init_dp(&dp, N, T);
    fill_dp(&dp, &time_value, N, T);

    int val_acum;
    init_val_acum(&val_acum, &time_value, N);

    int max_val = val_acum + dp[(N - 1) * T + T - 1];

    backtrack(&val_acum, &dp, &time_value, N, T, &max_val);

    print_max_val(&max_val);

    return 0;
}

