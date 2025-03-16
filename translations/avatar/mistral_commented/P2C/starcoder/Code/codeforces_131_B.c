#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to read input from standard input
int read_int() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read input from standard input
int read_int_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return n;
}

// Function to count occurrences of numbers
int count_occurrences(int *arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += arr[i];
    }
    return count;
}

// Function to count the number of pairs
int count_pairs(int *arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            count += arr[i] * (arr[i] - 1) / 2;
        }
        if (arr[i] < 0) {
            count += arr[i] * arr[-i] / 2;
        }
    }
    return count;
}

// Driver function
int main() {
    int n = read_int();
    int arr[n];
    read_int_array(arr, n);
    int count = count_pairs(arr, n);
    printf("%d\n", count);
    return 0;
}

