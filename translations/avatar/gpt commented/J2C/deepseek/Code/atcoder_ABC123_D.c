#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

int main() {
    int x[3];
    int max = 0;
    int k;
    int i, j, m;

    // Read the sizes of the three lists from user input
    for (i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        if (x[i] > max) {
            max = x[i];
        }
    }

    // Read the maximum product limit
    scanf("%d", &k);

    // Initialize an array of pointers to store the elements for each of the three lists
    long long *a[3];
    for (i = 0; i < 3; ++i) {
        a[i] = (long long*)malloc(x[i] * sizeof(long long));
    }

    // Read the elements for each list and sort them
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < x[i]; ++j) {
            scanf("%lld", &a[i][j]);
        }
        qsort(a[i], x[i], sizeof(long long), compare); // Sort the list using qsort
    }

    // List to store the valid sums
    long long ans[1000000];
    int ans_size = 0;

    // Generate all combinations of elements from the three lists
    for (i = 0; i < x[0]; ++i) {
        for (j = 0; j < x[1]; ++j) {
            for (m = 0; m < x[2]; ++m) {
                // Check if the product of the indices is within the limit k
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    // Calculate the sum of the selected elements from each list
                    long long tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1];
                    ans[ans_size++] = tmp; // Add the sum to the answer list
                }
            }
        }
    }

    // Sort the list of sums in ascending order
    qsort(ans, ans_size, sizeof(long long), compare);

    // Print the largest k sums from the answer list
    for (i = 0; i < k; ++i) {
        printf("%lld\n", ans[ans_size - i - 1]); // Print the k largest sums
    }

    // Free the allocated memory for the lists
    for (i = 0; i < 3; ++i) {
        free(a[i]);
    }

    return 0;
}
