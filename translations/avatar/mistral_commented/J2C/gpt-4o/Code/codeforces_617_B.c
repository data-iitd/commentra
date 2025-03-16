#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation

int main() {  // Defining the main function
    int n;  // Variable to store the size of the array
    scanf("%d", &n);  // Reading the first integer from the input as the size of the array

    int *arr = (int *)malloc(n * sizeof(int));  // Dynamically allocating memory for the array to store indices of 1's
    int count = 0;  // Counter for the number of 1's found

    for (int i = 0; i < n; i++) {  // Loop through the input to find the indices of the 1's
        int value;
        scanf("%d", &value);  // Read the next integer from input
        if (value == 1) {
            arr[count++] = i;  // If the current input is 1, store its index in the array
        }
    }

    if (count == 0) {  // Check if no 1's were found
        printf("0\n");  // If no 1's, print 0 as the output
    } else {
        long result = 1;  // Initialize the result variable to 1

        for (int i = 1; i < count; i++) {  // Loop through the array to calculate the result
            result *= arr[i] - arr[i - 1];  // Multiply the difference between two consecutive indices to the result
        }

        printf("%ld\n", result);  // Print the result as the output
    }

    free(arr);  // Free the dynamically allocated memory
    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
