
###
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
###

###
// Function to read integers from the standard input
###

int* readInts(int* n) {
    int* A = (int*)malloc(sizeof(int) * (*n));
    for (int i = 0; i < *n; i++) {
        scanf("%d", &A[i]);
    }
    return A;
}

###
// Main function
###

int main() {
    int n;
    scanf("%d", &n);
    int* A = readInts(&n);
    qsort(A, n, sizeof(int), cmpfunc);
    int ans = 0;
    for (int i = n - 2; i >= n - 2 * n - 1; i -= 2) {
        ans += A[i];
    }
    printf("%d\n", ans);
    free(A);
    return 0;
}

