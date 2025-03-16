#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Define a maximum size for the lists

// Function to compare two long integers for qsort
int compare(const void *a, const void *b) {
    return (*(long *)b - *(long *)a; // Sort in descending order
}

int main() {
    // Initialize variables
    int x[3];
    int max = 0; // Variable to track the maximum size
    long a[3][MAX_SIZE]; // Array to store the elements for each of the three lists
    long ans[MAX_SIZE * MAX_SIZE * MAX_SIZE]; // Array to store the valid sums
    int ans_size = 0; // Size of the answer array

    // Read the sizes of the three lists from user input
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        if (x[i] > max) {
            max = x[i]; // Update max if current size is greater
        }
    }

    // Read the maximum product limit
    int k;
    scanf("%d", &k);

    // Read the elements for each list
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < x[i]; ++j) {
            scanf("%ld", &a[i][j]); // Add elements to the respective list
        }
        // Sort the list after all elements are added
        qsort(a[i], x[i], sizeof(long), compare);
    }

    // Generate all combinations of elements from the three lists
    for (int i = 0; i < x[0]; ++i) {
        for (int j = 0; j < x[1]; ++j) {
            for (int m = 0; m < x[2]; ++m) {
                // Check if the product of the indices is within the limit k
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    // Calculate the sum of the selected elements from each list
                    long tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1];
                    ans[ans_size++] = tmp; // Add the sum to the answer list
                }
            }
        }
    }

    // Sort the list of sums in descending order
    qsort(ans, ans_size, sizeof(long), compare);

    // Print the largest k sums from the answer list
    for (int i = 0; i < k && i < ans_size; ++i) {
        printf("%ld\n", ans[i]); // Print the k largest sums
    }

    return 0;
}

// <END-OF-CODE>
