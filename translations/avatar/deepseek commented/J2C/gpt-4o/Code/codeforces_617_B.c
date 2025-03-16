#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // Step 5: Read the number of elements.
    
    int *arr = (int *)malloc(n * sizeof(int)); // Step 6: Create an array to store the indices of elements equal to 1.
    int count = 0; // To keep track of the number of indices stored.

    for (int i = 0; i < n; i++) { // Step 7: Read the elements and store their indices if they are equal to 1.
        int value;
        scanf("%d", &value);
        if (value == 1) {
            arr[count++] = i; // Store the index and increment the count.
        }
    }

    if (count == 0) { // Step 8: Check if the count is zero.
        printf("0\n"); // If the count is zero, print 0.
    } else {
        long result = 1; // Initialize the result variable to 1.
        for (int i = 1; i < count; i++) { // Step 9: Calculate the product of differences between consecutive indices.
            result *= arr[i] - arr[i - 1];
        }
        printf("%ld\n", result); // Print the result.
    }

    free(arr); // Free the allocated memory.
    return 0; // Return success.
}

// <END-OF-CODE>
