#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Initialize scanner for user input
    int x[3];
    int max = 0; // Variable to track the maximum size
    int k;
    int i, j, m;
    long tmp;
    int n;
    int *a[3];
    int *ans;
    
    // Read the sizes of the three lists from user input
    for (i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        max = max > x[i] ? max : x[i]; // Update max if current size is greater
    }
    
    // Read the maximum product limit
    scanf("%d", &k);
    
    // Initialize an array of lists to store the elements for each of the three lists
    for (i = 0; i < 3; ++i) {
        a[i] = (int *)malloc(x[i] * sizeof(int));
    }
    
    // Read the elements for each list and sort them
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < x[i]; ++j) {
            scanf("%d", &a[i][j]); // Add elements to the respective list
        }
        qsort(a[i], x[i], sizeof(int), compare); // Sort the list after all elements are added
    }
    
    // List to store the valid sums
    ans = (int *)malloc(max * sizeof(int));
    
    // Generate all combinations of elements from the three lists
    for (i = 0; i < x[0]; ++i) {
        for (j = 0; j < x[1]; ++j) {
            for (m = 0; m < x[2]; ++m) {
                // Check if the product of the indices is within the limit k
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    // Calculate the sum of the selected elements from each list
                    tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1];
                    ans[n++] = tmp; // Add the sum to the answer list
                }
            }
        }
    }
    
    // Sort the list of sums in ascending order
    qsort(ans, n, sizeof(int), compare);
    
    // Get the size of the answer list
    n = n > k ? k : n;
    
    // Print the largest k sums from the answer list
    for (i = 0; i < n; ++i) {
        printf("%d\n", ans[n - i - 1]); // Print the k largest sums
    }
    
    // Free the memory allocated for the lists
    for (i = 0; i < 3; ++i) {
        free(a[i]);
    }
    free(ans);
    
    return 0;
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

