#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, k;
    scanf("%d %d", &num, &k);

    int *arr = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    int temp = 0;
    int *different = (int *)calloc(num, sizeof(int));
    int different_size = 0;

    // Sort the array 'arr' in ascending order
    qsort(arr, num, sizeof(int), (int (*)(const void *, const void *))compare);

    for (int i = 0; i < num; i++) {
        int x = arr[i];
        int is_unique = 1;

        // Check if 'x' is not divisible by 'k' or if its quotient is not already in 'different'
        if (x % k != 0) {
            for (int j = 0; j < different_size; j++) {
                if (x / k == different[j]) {
                    is_unique = 0;
                    break;
                }
            }
        } else {
            is_unique = 0;
        }

        // If the condition is true, add 'x' to the array 'different'
        if (is_unique) {
            different[different_size++] = x / k;
        }

        // Update the maximum length of 'different' seen so far
        temp = (temp > different_size) ? temp : different_size;
    }

    // Print the maximum length of 'different'
    printf("%d\n", temp);

    // Free allocated memory
    free(arr);
    free(different);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
