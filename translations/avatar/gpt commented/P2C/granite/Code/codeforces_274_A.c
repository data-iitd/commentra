
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read two integers from input: num (number of elements) and k (the divisor)
    int num, k;
    scanf("%d %d", &num, &k);

    // Read the array of integers from input
    int *arr = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize a set to keep track of unique elements that meet the criteria
    int *different = (int*)malloc(num * sizeof(int));
    int different_size = 0;

    // Sort the array to process elements in ascending order
    qsort(arr, num, sizeof(int), compare);

    // Iterate through each element in the sorted array
    for (int i = 0; i < num; i++) {
        // Check if the element is not divisible by k or if its quotient is not already in the 'different' set
        if (arr[i] % k!= 0 ||!binary_search(different, different_size, arr[i] / k)) {
            // Add the element to the 'different' set since it meets the criteria
            different[different_size++] = arr[i];
        }
    }

    // Print the maximum size of the 'different' set found
    printf("%d\n", different_size);

    // Free the memory allocated for the arrays
    free(arr);
    free(different);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binary_search(int *arr, int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key) {
            return 1;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}

