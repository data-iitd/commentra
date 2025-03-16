#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long min = LONG_MAX; // Declaring a global variable to keep track of the minimum result

void util(long *arr, int arr_size, char **ops, int idx);

int main() {
    int arr_size = 4;
    long arr[4];
    char *ops[3];

    // Reading four numbers and storing them in the array
    for (int i = 0; i < arr_size; i++) {
        scanf("%ld", &arr[i]);
    }

    // Reading three operations and storing them in the array
    for (int i = 0; i < 3; i++) {
        ops[i] = (char *)malloc(2 * sizeof(char));
        scanf("%s", ops[i]);
    }

    // Calling the recursive function to find the minimum result
    util(arr, arr_size, ops, 0);

    // Outputting the minimum result
    printf("%ld\n", min);

    // Freeing allocated memory for operations
    for (int i = 0; i < 3; i++) {
        free(ops[i]);
    }

    return 0;
}

// Recursive function to find the minimum result by applying operations
void util(long *arr, int arr_size, char **ops, int idx) {
    if (idx == 3) { // Base case: when all operations are applied
        if (arr[0] < min) {
            min = arr[0]; // Update min with the current result
        }
        return;
    }

    // Iterating through the array to apply operations between two numbers
    for (int i = 0; i < arr_size; i++) {
        for (int j = i + 1; j < arr_size; j++) {
            long temp_arr[arr_size - 1];
            int temp_idx = 0;

            // Creating a temporary array to store remaining numbers
            for (int k = 0; k < arr_size; k++) {
                if (k != j && k != i) {
                    temp_arr[temp_idx++] = arr[k];
                }
            }

            long res; // Variable to store the result of the operation
            if (idx < 3 && ops[idx][0] == '+') {
                res = arr[i] + arr[j]; // Applying addition
            } else {
                res = arr[i] * arr[j]; // Applying multiplication
            }

            // Adding the result to the temporary array
            temp_arr[temp_idx] = res;

            // Recursively calling util with the updated array and index
            util(temp_arr, arr_size - 1, ops, idx + 1);
        }
    }
}
