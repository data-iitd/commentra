#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to read input line
char* input() {
    char* str = (char*)malloc(1000000 * sizeof(char));
    scanf("%s", str);
    return str;
}

// Function to read integer input
int INT() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read map of integers
int* MAP() {
    int* arr = (int*)malloc(1000000 * sizeof(int));
    int n = INT();
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to read list of integers
int* LIST() {
    int* arr = (int*)malloc(1000000 * sizeof(int));
    int n = INT();
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to read zip of n maps
int** ZIP(int n) {
    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(1000000 * sizeof(int));
        int m = INT();
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    return arr;
}

// Function to remove consecutive duplicates from list A
void removeConsecutiveDuplicates(int* A, int* N) {
    int i = 1;
    while (i < *N - 1) {
        if (A[i - 1] == A[i] && A[i] == A[i + 1]) {
            for (int j = i; j < *N - 1; j++) {
                A[j] = A[j + 1];
            }
            *N -= 1;
        } else {
            i += 1;
        }
    }
}

// Function to find peaks
int findPeaks(int* A, int N) {
    int i = 1;
    int ans = 0;
    while (i < N - 1) {
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans += 1;
            i += 2;
        } else {
            i += 1;
        }
    }
    return ans;
}

int main() {
    // Reading number of elements
    int N = INT();
    // Reading list of elements
    int* A = LIST();
    // Removing consecutive duplicates from list A
    removeConsecutiveDuplicates(A, &N);
    // Finding peaks
    int ans = findPeaks(A, N);
    // Output the total number of peaks found
    printf("%d\n", ans + 1);
    return 0;
}

