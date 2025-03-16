
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int x[3];
    int max = 0;
    int k;
    int i, j, m;
    long tmp;
    int n;

    // Step 1: Read input values for the array x and find the maximum value in x.
    for (i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        max = max > x[i] ? max : x[i];
    }

    scanf("%d", &k);

    long a[3][max];
    long *p[3];

    // Step 2: Initialize a list of lists to store the input values for each sub-array.
    for (i = 0; i < 3; ++i) {
        p[i] = a[i];
    }

    // Step 3: Read input values for each sub-array, sort them, and store them in the list of lists.
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < x[i]; ++j) {
            scanf("%ld", &p[i][j]);
        }
        qsort(p[i], x[i], sizeof(long), cmp);
    }

    long ans[max * max * max];
    n = 0;

    // Step 5: Initialize an empty list to store the results.
    // Step 6: Use nested loops to iterate through all possible combinations of elements from the three sub-arrays,
    // and add the sum of the selected elements to the result list if the product of their indices is less than or equal to k.
    for (i = 0; i < x[0]; ++i) {
        for (j = 0; j < x[1]; ++j) {
            for (m = 0; m < x[2]; ++m) {
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    tmp = p[0][x[0] - i - 1] + p[1][x[1] - j - 1] + p[2][x[2] - m - 1];
                    ans[n++] = tmp;
                }
            }
        }
    }

    // Step 7: Sort the result list in ascending order.
    qsort(ans, n, sizeof(long), cmp);

    // Step 8: Print the top k values from the result list in descending order.
    for (i = 0; i < k; ++i) {
        printf("%ld\n", ans[n - i - 1]);
    }

    return 0;
}

int cmp(const void *a, const void *b)
{
    return *(long *)a - *(long *)b;
}

