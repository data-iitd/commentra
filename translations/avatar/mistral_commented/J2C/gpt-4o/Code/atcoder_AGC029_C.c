#include <stdio.h>      // Standard I/O library for input and output
#include <stdlib.h>     // Standard library for memory allocation and conversions
#include <stdbool.h>    // Library for using boolean type
#include <string.h>     // Library for string manipulation
#include <limits.h>     // Library for integer limits

#define MAX_N 100000    // Define a maximum size for the array

int n;                  // Number of elements in the array 'a'
int a[MAX_N];          // Array of integers
int count[MAX_N];      // Array to store the count of each element

// Function to read input
void set() {
    scanf("%d", &n); // Read the number of elements 'n'
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read each element of the array 'a'
    }
}

// Function to check if a given 'k' is possible
bool isPossible(int k) {
    memset(count, 0, sizeof(count)); // Clear the count array
    int current = 0; // Initialize the current index in the array 'a'

    for (int i = 0; i < n; i++) { // Iterate through each element in the array 'a'
        int ai = a[i]; // Current element

        if (ai <= current) { // If the current element is smaller than or equal to the previous one
            if (k == 1) return false; // If 'k' is 1, return false as there is no possible solution

            // Remove elements from count that are greater than or equal to ai
            for (int j = ai; j < MAX_N; j++) {
                if (count[j] > 0) {
                    count[j] = 0; // Reset the count for this value
                }
            }

            int p = ai - 1; // Calculate the previous index 'p'
            while (true) { // Find the previous index 'p' with the count 'k'
                if (p < 0) return false; // If 'p' is out of the array bounds, return false

                count[p]++; // Increment the count of 'p'

                if (count[p] == k) { // If the count of 'p' is equal to 'k', reset it and move to the previous index
                    count[p] = 0;
                    p--;
                } else { // Otherwise, break the loop
                    break;
                }
            }
        }
        current = ai; // Update the current index
    }

    return true; // If all elements in the array 'a' are processed, return true as a valid solution is found
}

// Main function to execute the program
int main() {
    set(); // Call the set function to read the input
    int ng = 0; // Initialize the lower bound of the search range
    int ok = n; // Initialize the upper bound of the search range

    while (ok - ng > 1) { // Run the while loop until the search range is narrowed down to a single element
        int k = (ng + ok) / 2; // Calculate the middle index of the search range
        if (isPossible(k)) { // If the middle index 'k' is a valid solution, update the upper bound
            ok = k;
        } else { // Otherwise, update the lower bound
            ng = k;
        }
    }

    printf("%d\n", ok); // Print the solution
    return 0; // Return success
}

// <END-OF-CODE>
