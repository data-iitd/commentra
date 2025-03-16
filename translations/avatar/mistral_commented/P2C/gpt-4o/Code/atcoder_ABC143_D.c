#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to perform binary search (bisect_left)
int bisect_left(int *arr, int size, int value) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// Function to perform binary search (bisect_right)
int bisect_right(int *arr, int size, int value) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int n;
    // Read the number of elements
    scanf("%d", &n);
    int *l = malloc(n * sizeof(int));

    // Read the list of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Sort the list in ascending order
    qsort(l, n, sizeof(int), compare);

    // Initialize the answer variable
    long long ans = 0;

    // Iterate through each pair of indices 'i' and 'j'
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = l[i];
            int b = l[j];

            // Find the index 'right' using bisect_left
            int right = bisect_left(l, n, a + b);

            // Find the index 'left' using bisect_right
            int left = bisect_right(l, n, (a > b ? a - b : b - a));

            // Calculate the temporary answer 'tmp'
            long long tmp = right - left;

            // Adjust 'tmp' if 'i' and 'j' are within the range
            if (left <= i && i < right) {
                tmp--;
            }
            if (left <= j && j < right) {
                tmp--;
            }

            // Add the temporary answer to the final answer
            ans += tmp;
        }
    }

    // Print the final answer divided by three
    printf("%lld\n", ans / 3);

    // Free the allocated memory
    free(l);
    return 0;
}
