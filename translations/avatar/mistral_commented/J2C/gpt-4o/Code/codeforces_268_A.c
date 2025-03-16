#include <stdio.h> // Including the standard input-output library
#include <stdlib.h> // Including the standard library for memory allocation and conversion functions

int main() { // Defining the main function
    int n; // Variable to store the number of integers
    scanf("%d", &n); // Reading the first line of input containing the number of integers n

    int result = 0; // Initializing the variable result to zero

    int h[n]; // Creating an integer array h of size n
    int g[n]; // Creating an integer array g of size n

    for (int i = 0; i < n; i++) { // Iterating through each index i from 0 to n-1
        scanf("%d", &h[i]); // Reading an integer value and assigning it to the current index of array h
        scanf("%d", &g[i]); // Reading an integer value and assigning it to the current index of array g
    }

    for (int i = 0; i < n; i++) { // Iterating through each index i from 0 to n-1
        for (int j = 0; j < n; j++) { // Nested for loop iterating through each index j from 0 to n-1
            if (h[i] == g[j]) { // Checking if the current element of array h is equal to the current element of array g
                result++; // Incrementing the result variable if the condition is true
            }
        }
    }

    printf("%d\n", result); // Printing the final result to the standard output
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
