
#include <stdio.h>
#include <stdlib.h>

// Constants for the program
#define MOD 1000000000 + 7
#define ALPHABET_NUM 26

int main() {
    // Read input values for n and x
    int n, x;
    scanf("%d %d", &n, &x);

    // Declare and initialize array A
    int* A = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Sort the array A
    qsort(A, n, sizeof(int), compare);

    // Initialize answer variable
    int ans = 0;
    // Count how many elements can be taken from A without exceeding x
    for (int i = 0; i < n; i++) {
        if (x >= A[i]) {
            ans++;
            x -= A[i];
        } else {
            break;
        }
    }
    // Adjust answer if all elements are taken and there is still remaining x
    if (ans == n && x > 0) {
        ans--;
    }
    // Print the final answer
    printf("%d\n", ans);

    // Free memory allocated for array A
    free(A);

    return 0;
}

int compare(const void* a, const void* b) {
    int* x = (int*)a;
    int* y = (int*)b;

    if (*((int*)a) > *((int*)b) {
        return 1;
    } else if (*((int*)a) < *((int*)b) {
        return -1;
    } else {
        return 0;
    }
}