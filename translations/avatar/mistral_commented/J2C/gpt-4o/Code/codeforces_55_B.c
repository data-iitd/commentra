#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation
#include <limits.h> // Including limits.h for LONG_MAX
#include <string.h> // Including string.h for string operations

long min; // Initializing the minimum value to LONG_MAX

void util(long *arr, char ops[][2], int idx, int size) { // Starting the util function
    if (idx == 3) { // Checking if the index of the operator is equal to 3 (the last operator)
        if (arr[0] < min) { // Updating the minimum value with the first number in the array
            min = arr[0];
        }
        return; // Exiting the function
    }

    for (int i = 0; i < size; i++) { // Iterating through the array to find two numbers for the current operator
        for (int j = i + 1; j < size; j++) {
            long *a = (long *)malloc((size - 1) * sizeof(long)); // Creating a new array to store the result of the current operation
            int k_index = 0; // Index for the new array

            for (int k = 0; k < size; k++) { // Iterating through the array to exclude the current and previous numbers
                if (k != j && k != i) {
                    a[k_index++] = arr[k]; // Adding the excluded number to the new array
                }
            }

            long res; // Initializing the result variable

            if (ops[idx][0] == '+') { // Checking if the current operator is '+'
                res = arr[i] + arr[j]; // Performing the addition operation
            } else { // Else, the current operator is '*'
                res = arr[i] * arr[j]; // Performing the multiplication operation
            }

            a[k_index] = res; // Adding the result to the new array
            util(a, ops, idx + 1, k_index + 1); // Recursively calling the util function with the new array, the array of operators, and the index of the next operator
            free(a); // Freeing the allocated memory for the new array
        }
    }
}

int main() { // Starting the main function
    min = LONG_MAX; // Setting the initial value of min to LONG_MAX
    long arr[4]; // Creating an array of long type to store the input numbers
    char ops[3][2]; // Creating an array of char type to store the operators

    for (int i = 0; i < 4; i++) { // Reading 4 numbers from the standard input and storing them in the array
        scanf("%ld", &arr[i]);
    }

    for (int i = 0; i < 3; i++) { // Reading 3 operators from the standard input and storing them in the array
        scanf(" %c", &ops[i][0]); // Note: space before %c to consume any whitespace
        ops[i][1] = '\0'; // Null-terminating the string
    }

    util(arr, ops, 0, 4); // Calling the util function with the array, the array of operators, and the index of the first operator

    printf("%ld\n", min); // Printing the minimum value found during the execution
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
