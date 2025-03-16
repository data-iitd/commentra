#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, k;
    scanf("%d %d", &num, &k);

    int *arr = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, num, sizeof(int), (int (*)(const void *, const void *))compare);

    int temp = 0;
    int *different = (int *)malloc(num * sizeof(int));
    int different_size = 0;

    for (int i = 0; i < num; i++) {
        int x = arr[i];
        int is_valid = 1;

        // Check if the element is not divisible by k or if its quotient is not already in the 'different' array
        for (int j = 0; j < different_size; j++) {
            if (x % k == 0 && x / k == different[j]) {
                is_valid = 0;
                break;
            }
        }

        if (is_valid) {
            // Add the element to the 'different' array since it meets the criteria
            different[different_size++] = x;
        }

        // Update the maximum size of the 'different' array if the current size is larger
        if (different_size > temp) {
            temp = different_size;
        }
    }

    // Print the maximum size of the 'different' array found
    printf("%d\n", temp);

    // Free allocated memory
    free(arr);
    free(different);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
