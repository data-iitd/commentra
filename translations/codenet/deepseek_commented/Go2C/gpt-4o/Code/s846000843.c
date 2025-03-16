#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* CumSum(int* nums, int n) {
    int* sums = (int*)malloc((n + 1) * sizeof(int));
    sums[0] = 0;
    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    return sums;
}

int Abs(int a) {
    return a >= 0 ? a : -a;
}

int Min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of integers.

    int* aa = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &aa[i]); // Read each integer and store it in the array.
    }

    int* cumsum = CumSum(aa, n); // Compute the cumulative sum of the integers.

    int ans = 2020202020;
    for (int i = 1; i < n; i++) {
        ans = Min(ans, Abs(cumsum[n] - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    printf("%d\n", ans); // Print the minimum absolute difference.

    free(aa); // Free the allocated memory for the array.
    free(cumsum); // Free the allocated memory for the cumulative sum.
    return 0;
}

// <END-OF-CODE>
