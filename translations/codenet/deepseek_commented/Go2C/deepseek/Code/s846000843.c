#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the cumulative sum of an array
int* cumsum(int* nums, int size) {
    int* sums = (int*)malloc((size + 1) * sizeof(int));
    sums[0] = 0;
    for (int i = 0; i < size; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    return sums;
}

// Function to compute the absolute value of an integer
int abs(int a) {
    return a >= 0 ? a : -a;
}

// Function to find the minimum value among the given integers
int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int aa[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
    }

    int* cumsum_aa = cumsum(aa, n);

    int ans = 2020202020;
    for (int i = 1; i < n; i++) {
        ans = min(ans, abs(cumsum_aa[n] - cumsum_aa[i] - (cumsum_aa[i] - cumsum_aa[0])));
    }

    printf("%d\n", ans);

    free(cumsum_aa);
    return 0;
}
