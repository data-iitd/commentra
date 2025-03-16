#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007

// Function to read integers from input
int* readInts() {
    int* arr = (int*)malloc(100000 * sizeof(int)); // Allocate memory for array
    char str[100000];
    fgets(str, 100000, stdin);
    char* token = strtok(str, " ");
    int i = 0;
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to compare two integers for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Main function
void main() {
    int n;
    scanf("%d", &n);
    int* A = readInts();
    qsort(A, n, sizeof(int), compare);
    int ans = 0;

    // Calculate the sum of every second element from the end
    for (int i = n * 2 - 2; i >= n; i -= 2) {
        ans += A[i];
    }

    printf("%d\n", ans);
    free(A); // Free allocated memory
}
