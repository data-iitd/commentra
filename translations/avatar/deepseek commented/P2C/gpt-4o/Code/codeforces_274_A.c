#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, k;
    scanf("%d %d", &num, &k);  // Read the number of elements and the divisor

    int *arr = (int *)malloc(num * sizeof(int));  // Allocate memory for the array
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);  // Read the array of integers
    }

    int *different = (int *)malloc(num * sizeof(int));  // Allocate memory for unique elements
    int different_count = 0;  // Initialize a variable to keep track of unique elements
    int temp = 0;  // Initialize a variable to store the maximum length of the set

    // Sort the array
    qsort(arr, num, sizeof(int), (int (*)(const void *, const void *))compare);

    // Iterate through each element in the sorted array
    for (int i = 0; i < num; i++) {
        int x = arr[i];
        int is_unique = 1;  // Flag to check if x is unique

        // Check if x is not divisible by k or x/k is not in the set
        if (x % k != 0) {
            for (int j = 0; j < different_count; j++) {
                if (different[j] == x) {
                    is_unique = 0;  // x is already in the set
                    break;
                }
            }
            if (is_unique) {
                different[different_count++] = x;  // Add x to the set if the condition is true
            }
        } else {
            int x_div_k = x / k;
            is_unique = 1;  // Reset flag for checking x/k

            for (int j = 0; j < different_count; j++) {
                if (different[j] == x_div_k) {
                    is_unique = 0;  // x/k is already in the set
                    break;
                }
            }
            if (is_unique) {
                different[different_count++] = x;  // Add x to the set if the condition is true
            }
        }
        temp = (different_count > temp) ? different_count : temp;  // Update temp with the maximum length of the set
    }

    printf("%d\n", temp);  // Print the maximum number of unique elements not divisible by k

    free(arr);  // Free allocated memory for the array
    free(different);  // Free allocated memory for the unique elements
    return 0;
}

// Comparison function for qsort
int compare(const int *a, const int *b) {
    return (*a - *b);
}

// <END-OF-CODE>
