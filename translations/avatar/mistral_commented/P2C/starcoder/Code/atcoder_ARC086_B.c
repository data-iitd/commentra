
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to read input from standard input
int I() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to return an integer input
int III() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to create a list of lists based on the given number of rows and columns
int **Line(int N, int num) {
    int **arr = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        arr[i] = (int *)malloc(num * sizeof(int));
        for (int j = 0; j < num; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    return arr;
}

// Function to return the sign of the given number
int my_sign(int n) {
    if (n > 0) {
        return 1;
    } else if (n < 0) {
        return -1;
    } else {
        return 0;
    }
}

// Function to return the maximum value and its index
int max_index(int *a, int n) {
    int max_val = 0;
    int max_index = -1;
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_index = i;
        }
    }
    return max_index;
}

int main() {
    int N = I();
    int *a = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int max_index = max_index(a, N);
    int max_sign = my_sign(a[max_index]);
    if (max_sign == 0) {
        printf("0\n");
    } else if (max_sign == 1) {
        printf("%d\n", 2 * N - 1);
        printf("%d %d\n", max_index + 1, 1);
        for (int i = 1; i < N; i++) {
            printf("%d %d\n", i + 1, i + 2);
        }
    } else {
        printf("%d\n", 2 * N - 1);
        printf("%d %d\n", max_index + 1, 1);
        for (int i = N - 1; i > 0; i--) {
            printf("%d %d\n", i + 1, i);
        }
    }
    return 0;
}

