#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Variable to store the minimum result found
long long min = LLONG_MAX;

// Recursive utility function to perform operations and find the minimum result
void util(long long *arr, char **ops, int idx, int size) {
    // Base case: if all operations have been used, update the minimum result
    if (idx == 3) {
        if (arr[0] < min) {
            min = arr[0];
        }
        return;
    }

    // Iterate through all pairs of numbers in the list
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // Create a new array to hold the remaining numbers after the operation
            long long a[size - 1];
            int k = 0;
            for (int l = 0; l < size; l++) {
                if (l != j && l != i) {
                    a[k++] = arr[l];
                }
            }

            long long res;
            // Perform the operation based on the current operation in the ops array
            if (idx < 3 && ops[idx][0] == '+') {
                res = arr[i] + arr[j]; // Addition operation
            } else {
                res = arr[i] * arr[j]; // Multiplication operation
            }

            // Add the result of the operation to the new array
            a[k] = res;

            // Recursively call util with the new array and the next operation index
            util(a, ops, idx + 1, size - 1);
        }
    }
}

int main() {
    // Create an array to store the input numbers
    int size = 4;
    long long arr[size];

    // Read 4 long integers from user input and add them to the array
    for (int i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }

    // Create an array to store the operations
    char *ops[3];
    for (int i = 0; i < 3; i++) {
        ops[i] = (char *)malloc(2 * sizeof(char));
        scanf("%s", ops[i]);
    }

    // Call the utility function to compute the minimum result
    util(arr, ops, 0, size);

    // Print the minimum result found
    printf("%lld\n", min);

    // Free the allocated memory for operations
    for (int i = 0; i < 3; i++) {
        free(ops[i]);
    }

    return 0;
}
