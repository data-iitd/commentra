#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to compare two long integers for qsort
int compare(const void *a, const void *b) {
    return (*(long *)b - *(long *)a; // Sort in descending order
}

int main() {
    int x[3];
    int max = 0;

    // Step 1: Read input values for the array x and find the maximum value in x.
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        if (x[i] > max) {
            max = x[i];
        }
    }

    int k;
    scanf("%d", &k);
    
    long *a[3][MAX_SIZE]; // Array of pointers to long arrays
    int sizes[3] = {0}; // To keep track of the sizes of each sub-array

    // Step 2: Initialize a list of lists to store the input values for each sub-array.
    for (int i = 0; i < 3; ++i) {
        a[i] = (long *)malloc(x[i] * sizeof(long));
    }

    // Step 3: Read input values for each sub-array, sort them, and store them in the list of lists.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < x[i]; ++j) {
            scanf("%ld", &a[i][j]);
        }
        sizes[i] = x[i];
        qsort(a[i], sizes[i], sizeof(long), compare); // Sort in descending order
    }

    long *ans = (long *)malloc(MAX_SIZE * sizeof(long));
    int ans_size = 0;

    // Step 6: Use nested loops to iterate through all possible combinations of elements from the three sub-arrays,
    // and add the sum of the selected elements to the result list if the product of their indices is less than or equal to k.
    for (int i = 0; i < sizes[0]; ++i) {
        for (int j = 0; j < sizes[1]; ++j) {
            for (int m = 0; m < sizes[2]; ++m) {
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    long tmp = a[0][i] + a[1][j] + a[2][m];
                    ans[ans_size++] = tmp;
                }
            }
        }
    }

    // Step 7: Sort the result list in ascending order.
    qsort(ans, ans_size, sizeof(long), compare);

    // Step 8: Print the top k values from the result list in descending order.
    for (int i = 0; i < k && i < ans_size; ++i) {
        printf("%ld\n", ans[i]);
    }

    // Free allocated memory
    for (int i = 0; i < 3; ++i) {
        free(a[i]);
    }
    free(ans);

    return 0;
}

// <END-OF-CODE>
