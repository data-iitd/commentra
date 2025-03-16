#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from standard input
int getInt() {
    int ret;
    scanf("%d", &ret);
    return ret;
}

// Function to read n integers from standard input and return them as an array
int* getIntArray(int n) {
    int* ret = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ret[i]);
    }
    return ret;
}

// Function to calculate the absolute value of an integer
int abs(int n) {
    return n < 0 ? -n : n;
}

// Function to solve the problem
void solve() {
    int n = getInt();
    int* as = getIntArray(n);

    int* xs = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    // Sort the array xs
    qsort(xs, n, sizeof(int), (int (*)(const void*, const void*))compare);

    int b = xs[n / 2]; // Choose the median as b
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    // Free allocated memory
    free(as);
    free(xs);
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Main function
int main() {
    solve();
    return 0;
}
