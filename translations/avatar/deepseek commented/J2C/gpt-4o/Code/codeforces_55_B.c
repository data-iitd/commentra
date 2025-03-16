#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

long min; // Declaring a global variable to keep track of the minimum result

void util(long* arr, char ops[][2], int size, int idx) {
    if (idx == 3) { // Base case: when all operations are applied
        if (arr[0] < min) {
            min = arr[0]; // Update min with the current result
        }
        return;
    }

    // Iterating through the array to apply operations between two numbers
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            long* a = (long*)malloc((size - 1) * sizeof(long)); // Temporary array to store remaining numbers
            int k = 0;
            for (int m = 0; m < size; m++) {
                if (m != j && m != i) {
                    a[k++] = arr[m]; // Adding remaining numbers to the temporary array
                }
            }

            long res; // Variable to store the result of the operation
            if (idx < 3 && ops[idx][0] == '+') {
                res = arr[i] + arr[j]; // Applying addition
            } else {
                res = arr[i] * arr[j]; // Applying multiplication
            }

            a[k] = res; // Adding the result to the temporary array
            util(a, ops, size - 1, idx + 1); // Recursively calling util with the updated array and index
            free(a); // Freeing the allocated memory
        }
    }
}

int main() {
    min = LONG_MAX; // Initializing min to the maximum possible long value
    long arr[4]; // Array to store the numbers
    char ops[3][2]; // Array to store the operations

    // Reading four numbers and adding them to the array
    for (int i = 0; i < 4; i++) {
        scanf("%ld", &arr[i]);
    }

    // Reading three operations and storing them in the array
    for (int i = 0; i < 3; i++) {
        scanf(" %c", &ops[i][0]); // Reading a character and storing it
        ops[i][1] = '\0'; // Null-terminating the string
    }

    // Calling the recursive function to find the minimum result
    util(arr, ops, 4, 0);

    // Outputting the minimum result
    printf("%ld\n", min);
    return 0;
}

// <END-OF-CODE>
