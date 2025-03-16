
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long min = LONG_MAX; // Declaring a static variable to keep track of the minimum result

void util(long arr[], char ops[], int idx, int n) {
    if (idx == 3) { // Base case: when all operations are applied
        min = (min < arr[0])? min : arr[0]; // Update min with the current result
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long a[n - 2]; // Temporary array to store remaining numbers
            int k = 0;
            for (int l = 0; l < n; l++) {
                if (l!= j && l!= i) {
                    a[k++] = arr[l]; // Adding remaining numbers to the temporary array
                }
            }

            long res; // Variable to store the result of the operation
            if (idx < 3 && ops[idx] == '+') {
                res = arr[i] + arr[j]; // Applying addition
            } else {
                res = arr[i] * arr[j]; // Applying multiplication
            }

            a[k++] = res; // Adding the result to the temporary array
            util(a, ops, idx + 1, n - 1); // Recursively calling util with the updated array and index
        }
    }
}

int main() {
    long arr[4]; // Array to store the four numbers
    char ops[3]; // Array to store the three operations

    // Reading four numbers and storing them in the array
    for (int i = 0; i < 4; i++) {
        scanf("%ld", &arr[i]);
    }

    // Reading three operations and storing them in the array
    for (int i = 0; i < 3; i++) {
        scanf(" %c", &ops[i]);
    }

    // Calling the recursive function to find the minimum result
    util(arr, ops, 0, 4);

    // Outputting the minimum result
    printf("%ld\n", min);

    return 0;
}
