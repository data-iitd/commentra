
#include <stdio.h>
#include <stdlib.h>

// Variable to store the minimum result found
long min;

// Utility function to perform operations and find the minimum result
void util(long arr[], char ops[], int idx, int n) {
    // Base case: if all operations have been used, update the minimum result
    if (idx == 3) {
        min = (min < arr[0])? min : arr[0];
        return;
    }

    // Iterate through all pairs of numbers in the list
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Create a new array to hold the remaining numbers after the operation
            long a[n - 2];
            int k = 0;
            for (int l = 0; l < n; l++) {
                if (l!= j && l!= i) {
                    a[k++] = arr[l];
                }
            }

            long res;
            // Perform the operation based on the current operation in the ops array
            if (idx < 3 && ops[idx] == '+') {
                res = arr[i] + arr[j]; // Addition operation
            } else {
                res = arr[i] * arr[j]; // Multiplication operation
            }

            // Add the result of the operation to the new array
            a[k++] = res;

            // Recursively call util with the new array and the next operation index
            util(a, ops, idx + 1, n - 1);
        }
    }
}

int main() {
    // Create an array to store the input numbers
    long arr[4];

    // Read 4 long integers from user input and add them to the array
    for (int i = 0; i < 4; i++) {
        scanf("%ld", &arr[i]);
    }

    // Create an array to store the operations
    char ops[3];

    // Read 3 operations from user input
    for (int i = 0; i < 3; i++) {
        scanf(" %c", &ops[i]);
    }

    // Initialize min to the maximum possible value
    min = LONG_MAX;

    // Call the utility function to compute the minimum result
    util(arr, ops, 0, 4);

    // Print the minimum result found
    printf("%ld\n", min);

    return 0;
}
