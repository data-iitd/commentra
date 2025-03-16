#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation

int main() {
    int n; // Variable to store the number of elements
    scanf("%d", &n); // Reading an integer n from user input

    // Dynamically allocating an array to store the indices of elements that are equal to 1
    int *arr = (int *)malloc(n * sizeof(int));
    int count = 0; // Counter for the number of indices found

    // Looping through the input values to find indices of elements equal to 1
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value); // Reading the input value
        if (value == 1) {
            arr[count++] = i; // If the input value is 1, store the index
        }
    }

    // Checking if the count of indices is zero
    if (count == 0) {
        // If no indices were found, print 0
        printf("0\n");
    } else {
        // If indices were found, initialize a result variable to 1
        long result = 1;

        // Calculate the product of the differences between consecutive indices
        for (int i = 1; i < count; i++) {
            result *= arr[i] - arr[i - 1];
        }

        // Print the final result
        printf("%ld\n", result);
    }

    // Free the dynamically allocated memory
    free(arr);
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
