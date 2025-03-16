#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, k;
    
    // Take the first line of input which are two integers 'num' and 'k'
    scanf("%d %d", &num, &k);
    
    // Comment: Initialize 'num' and 'k' with the values from user input

    // Take the second line of input which is a list 'arr' of integers
    int *arr = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Comment: Initialize an empty list 'arr' to store the input integers

    // Create an empty set 'different' to store unique integers
    int *different = (int *)malloc(num * sizeof(int));
    int different_count = 0;

    // Comment: Initialize an empty set 'different' to store unique integers

    // Sort the list 'arr' in ascending order
    qsort(arr, num, sizeof(int), (int (*)(const void *, const void *))compare);

    // Comment: Sort the list 'arr' in ascending order for easier comparison

    // Iterate through each integer 'x' in the sorted list 'arr'
    for (int i = 0; i < num; i++) {
        int x = arr[i];

        // Check if 'x' is not divisible by 'k' or if its quotient is not already in 'different'
        int is_unique = 1;
        if (x % k == 0) {
            for (int j = 0; j < different_count; j++) {
                if (different[j] == x / k) {
                    is_unique = 0;
                    break;
                }
            }
        }

        if (x % k != 0 || is_unique) {
            // If the condition is true, add 'x' to the set 'different'
            different[different_count++] = x;

            // Comment: If 'x' is not divisible by 'k' or its quotient is not already in 'different', add it to 'different'
        }
    }

    // Comment: After the loop, 'different_count' stores the maximum length of 'different' seen during the iteration

    // Print the maximum length of 'different'
    printf("%d\n", different_count);

    // Comment: Finally, print the maximum length of 'different'

    // Free allocated memory
    free(arr);
    free(different);

    return 0;
}

// Function to compare two integers for qsort
int compare(const int *a, const int *b) {
    return (*a - *b);
}

// <END-OF-CODE>
