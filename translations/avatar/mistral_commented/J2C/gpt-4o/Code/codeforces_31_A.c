#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation

int main() { // Main function is the entry point of the C application
    int n; // Variable to store the number of elements in the array
    scanf("%d", &n); // Reading the number of elements in the array from standard input

    int f = 0; // Initializing a flag variable to keep track of whether an element is found in the array
    int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocating an integer array of size n

    // Reading the elements of the array from standard input
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int k, j, i; // Declaring index variables

    // Outer loop to iterate through each element in the array
    for (k = 0; k < n; k++) {
        int t = a[k]; // Storing the current element in a temporary variable

        // Inner loop to compare the current element with other elements in the array
        for (i = 0; i < n; i++) {
            // Skipping the comparison if the current index is the same as the index of the current element
            if (i != k) {
                for (j = 0; j < n; j++) { // Inner most loop to compare the current element with all other elements in the array
                    if (j != i && j != k && t == (a[i] + a[j])) { // Checking if the sum of the current and previous elements is equal to the current element
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

    free(a); // Freeing the dynamically allocated memory for the array
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
