

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, f = 0, i, j, k, t;
    scanf("%d", &n); // Reading the number of elements in the array from the standard input stream
    int a[n]; // Creating an integer array of size n

    // Reading the elements of the array from the standard input stream
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (k = 0; k < n; k++) {
        t = a[k]; // Storing the current element in a temporary variable

        for (i = 0; i < n; i++) {
            if (i!= k) {
                for (j = 0; j < n - 1; j++) { // Inner most loop to compare the current element with all the previous elements in the array
                    if (i!= j && t == (a[i] + a[j])) { // Checking if the sum of the current and previous elements is equal to the current element
                        f = 1; // Setting the flag variable to 1 if a match is found
                        break; // Exiting the inner most loop if a match is found
                    }
                }
                if (f == 1) { // Checking if the flag variable is set to 1, indicating a match is found
                    break; // Exiting the inner loop if a match is found
                }
            }
        }
        if (f == 1) { // Checking if the flag variable is set to 1, indicating a match is found
            printf("%d %d %d\n", k + 1, j + 1, i + 1); // Printing the indices of the previous and current elements if a match is found
            f = 0; // Resetting the flag variable to 0 for the next iteration
        }
    }

    if (f == 0) { // Checking if no match is found in the array
        printf("-1\n"); // Printing "-1" if no match is found
    }

    return 0;
}

These comments should help in understanding the logic of each block of code in the given C program.