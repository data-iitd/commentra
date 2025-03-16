

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>

int main() {
    int x[3];
    int max = 0;

    // Step 1: Read input values for the array x and find the maximum value in x.
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        max = fmax(max, x[i]);
    }

    int k;
    long a[3][max];

    // Step 2: Initialize an array of arrays to store the input values for each sub-array.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < x[i]; ++j) {
            scanf("%ld", &a[i][j]);
        }
    }

    scanf("%d", &k);

    long ans[k];

    // Step 5: Initialize an array to store the results.
    // Step 6: Use nested loops to iterate through all possible combinations of elements from the three sub-arrays,
    // and add the sum of the selected elements to the result array if the product of their indices is less than or equal to k.
    int count = 0;
    for (int i = 0; i < x[0]; ++i) {
        for (int j = 0; j < x[1]; ++j) {
            for (int m = 0; m < x[2]; ++m) {
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    ans[count++] = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1];
                }
            }
        }
    }

    // Step 7: Sort the result array in ascending order.
    qsort(ans, count, sizeof(long), [](const void *a, const void *b) {
        return *(long *)a - *(long *)b;
    });

    // Step 8: Print the top k values from the result array in descending order.
    for (int i = 0; i < k; ++i) {
        printf("%ld\n", ans[count - i - 1]);
    }

    return 0;
}
