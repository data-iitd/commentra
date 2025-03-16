#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

long min; // Variable to store the minimum result found

// Function to perform operations and find the minimum result
void util(long* arr, char ops[][2], int size, int idx) {
    // Base case: if all operations have been used, update the minimum result
    if (idx == 3) {
        if (arr[0] < min) {
            min = arr[0];
        }
        return;
    }

    // Iterate through all pairs of numbers in the array
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // Create a new array to hold the remaining numbers after the operation
            long* a = (long*)malloc((size - 1) * sizeof(long));
            int k = 0;

            // Add the remaining numbers to the new array
            for (int m = 0; m < size; m++) {
                if (m != j && m != i) {
                    a[k++] = arr[m];
                }
            }

            long res;
            // Perform the operation based on the current operation in the ops array
            if (idx < 3 && ops[idx][0] == '+') {
                res = arr[i] + arr[j]; // Addition operation
            } else {
                res = arr[i] * arr[j]; // Multiplication operation
            }

            // Add the result of the operation to the new array
            a[k] = res;

            // Recursively call util with the new array and the next operation index
            util(a, ops, size - 1, idx + 1);

            // Free the allocated memory for the new array
            free(a);
        }
    }
}

int main() {
    // Initialize min to the maximum possible value
    min = LONG_MAX;

    // Create an array to store the input numbers
    long arr[4];

    // Read 4 long integers from user input and add them to the array
    for (int i = 0; i < 4; i++) {
        scanf("%ld", &arr[i]);
    }

    // Create an array to store the operations
    char ops[3][2];

    // Read 3 operations from user input
    for (int i = 0; i < 3; i++) {
        scanf("%s", ops[i]);
    }

    // Call the utility function to compute the minimum result
    util(arr, ops, 4, 0);

    // Print the minimum result found
    printf("%ld\n", min);

    return 0;
}

// <END-OF-CODE>
