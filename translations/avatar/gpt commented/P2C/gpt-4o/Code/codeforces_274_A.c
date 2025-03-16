#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int num, k;
    // Read two integers from input: num (number of elements) and k (the divisor)
    scanf("%d %d", &num, &k);

    // Read the array of integers from input
    int arr[MAX_SIZE];
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize a set to keep track of unique elements that meet the criteria
    int different[MAX_SIZE];
    int different_count = 0;

    // Sort the array to process elements in ascending order
    qsort(arr, num, sizeof(int), compare);

    // Iterate through each element in the sorted array
    for (int i = 0; i < num; i++) {
        int x = arr[i];
        // Check if the element is not divisible by k or if its quotient is not already in the 'different' set
        int is_in_different = 0;
        if (x % k == 0) {
            for (int j = 0; j < different_count; j++) {
                if (different[j] == x / k) {
                    is_in_different = 1;
                    break;
                }
            }
        }

        if (x % k != 0 || !is_in_different) {
            // Add the element to the 'different' set since it meets the criteria
            different[different_count++] = x;
        }
    }

    // Print the maximum size of the 'different' set found
    printf("%d\n", different_count);

    return 0;
}

// <END-OF-CODE>
