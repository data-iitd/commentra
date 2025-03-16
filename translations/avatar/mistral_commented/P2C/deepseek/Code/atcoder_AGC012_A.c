#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read integers from the standard input
int* readInts() {
    int n = 0;
    int* arr = malloc(n * sizeof(int));
    int num;
    while (scanf("%d", &num) != EOF) {
        arr = realloc(arr, (n + 1) * sizeof(int));
        arr[n++] = num;
    }
    return arr;
}

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Main function
void main() {
    int n;
    scanf("%d", &n);
    int* A = readInts();
    qsort(A, n, sizeof(int), compare);
    int ans = 0;
    for (int i = n - 2; i >= n - 2 * n - 1; i -= 2) {
        ans += A[i];
    }
    printf("%d\n", ans);
    free(A);
}
