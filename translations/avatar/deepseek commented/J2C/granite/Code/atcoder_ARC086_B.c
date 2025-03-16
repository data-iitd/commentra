
#include <stdio.h> // Include the necessary header file for input/output operations

int main() {
    int n; // Declare and initialize the variable 'n' to store the size of the array
    scanf("%d", &n); // Read the size of the array from input

    int a[n]; // Declare and initialize the array 'a' of size 'n'
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); // Read 'n' integers from input and store them in the array 'a'
    }

    int m = 0; // Declare and initialize the variable'm' to store the index of the maximum absolute value element
    for (int i = 1; i < n; ++i) {
        if (abs(a[m]) < abs(a[i])) {
            m = i; // Update the index of the maximum absolute value element
        }
    }

    int r[n][2]; // Declare a 2D array 'r' to store the operations
    int k = 0; // Declare and initialize the variable 'k' to store the number of operations

    // Find pairs of indices where one element is non-negative and the other is negative
    for (int i = 0; i < n; ++i) {
        if ((a[m] >= 0) ^ (a[i] >= 0)) { // Using XOR to check if one is non-negative and the other is negative
            r[k][0] = m + 1; // Store the first index of the pair in the 2D array 'r'
            r[k][1] = i + 1; // Store the second index of the pair in the 2D array 'r'
            ++k; // Increment the variable 'k' to store the number of operations
        }
    }

    // Generate operations based on whether the maximum absolute value element is non-negative or negative
    if (a[m] >= 0) {
        for (int i = 1; i < n; ++i) {
            r[k][0] = i + 1; // Store the first index of the operation in the 2D array 'r'
            r[k][1] = i + 2; // Store the second index of the operation in the 2D array 'r'
            ++k; // Increment the variable 'k' to store the number of operations
        }
    } else {
        for (int i = n; i > 1; --i) {
            r[k][0] = i; // Store the first index of the operation in the 2D array 'r'
            r[k][1] = i - 1; // Store the second index of the operation in the 2D array 'r'
            ++k; // Increment the variable 'k' to store the number of operations
        }
    }

    // Print the number of operations and the operations themselves
    printf("%d\n", k); // Print the number of operations
    for (int i = 0; i < k; ++i) {
        printf("%d %d\n", r[i][0], r[i][1]); // Print each operation in the format "first_index second_index"
    }

    return 0; // Return 0 to indicate successful execution of the program
}
