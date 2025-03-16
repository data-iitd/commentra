#include <stdio.h>
#include <stdlib.h>

int main() {
    // Reading an integer n from user input, which represents the number of elements
    int n;
    scanf("%d", &n);

    // Initializing a list to store the indices of elements that are equal to 1
    int *arr = (int *)malloc(n * sizeof(int));
    int arr_size = 0;

    // Looping through the input values to find indices of elements equal to 1
    for (int i = 0; i < n; i++) {
        // If the input value is 1, add the current index to the list
        int input;
        scanf("%d", &input);
        if (input == 1) {
            arr[arr_size++] = i;
        }
    }

    // Checking if the list of indices is empty
    if (arr_size == 0) {
        // If the list is empty, print 0
        printf("0\n");
    } else {
        // If the list is not empty, initialize a result variable to 1
        long result = 1;

        // Calculate the product of the differences between consecutive indices
        for (int i = 1; i < arr_size; i++) {
            result *= arr[i] - arr[i - 1];
        }

        // Print the final result
        printf("%ld\n", result);
    }

    // Freeing the memory allocated for the list
    free(arr);

    return 0;
}

