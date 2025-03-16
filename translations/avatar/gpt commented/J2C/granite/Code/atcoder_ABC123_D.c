
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    // Initialize variables and allocate memory for arrays and lists
    int x[3], max = 0;
    int k;
    long a[3][100000];
    long *ans;
    
    // Read the sizes of the three lists and the maximum product limit from user input
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        max = fmax(max, x[i]);
    }
    scanf("%d", &k);
    
    // Read the elements for each list and sort them
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < x[i]; ++j) {
            scanf("%ld", &a[i][j]);
        }
        qsort(a[i], x[i], sizeof(long), cmpfunc);
    }
    
    // Allocate memory for the answer list
    ans = (long*)malloc(sizeof(long) * k);
    
    // Generate all combinations of elements from the three lists
    int count = 0;
    for (int i = 0; i < x[0]; ++i) {
        for (int j = 0; j < x[1]; ++j) {
            for (int m = 0; m < x[2]; ++m) {
                // Check if the product of the indices is within the limit k
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    // Calculate the sum of the selected elements from each list
                    long tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1];
                    ans[count++] = tmp; // Add the sum to the answer list
                }
            }
        }
    }
    
    // Sort the list of sums in ascending order
    qsort(ans, count, sizeof(long), cmpfunc);
    
    // Print the largest k sums from the answer list
    for (int i = 0; i < k; ++i) {
        printf("%ld\n", ans[count - i - 1]); // Print the k largest sums
    }
    
    // Free the memory allocated for the answer list
    free(ans);
    
    return 0;
}

