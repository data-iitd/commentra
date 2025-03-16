#include <stdio.h>

int substract(int a, int b) {
    // Check if 'a' is greater than 'b'
    if (a > b) {
        int total = 0;  // Initialize total to accumulate results
        // Loop until either 'a' or 'b' becomes zero
        while (a > 0 && b > 0) {
            // Add the integer division of 'a' by 'b' to total
            total += a / b;
            // Update 'a' to the remainder of 'a' divided by 'b'
            a = a % b;
            // If 'a' is still greater than zero, calculate further
            if (a > 0) {
                // Add the integer division of 'b' by 'a' to total
                total += b / a;
                // Update 'b' to the remainder of 'b' divided by 'a'
                b = b % a;
            }
        }
        return total;  // Return the accumulated total
    }

    // Check if 'a' is less than 'b'
    if (a < b) {
        int total = 0;  // Initialize total to accumulate results
        // Loop until either 'a' or 'b' becomes zero
        while (a > 0 && b > 0) {
            // Add the integer division of 'b' by 'a' to total
            total += b / a;
            // Update 'b' to the remainder of 'b' divided by 'a'
            b = b % a;
            // If 'b' is still greater than zero, calculate further
            if (b > 0) {
                // Add the integer division of 'a' by 'b' to total
                total += a / b;
                // Update 'a' to the remainder of 'a' divided by 'b'
                a = a % b;
            }
        }
        return total;  // Return the accumulated total
    }

    // If 'a' is equal to 'b', return 1
    if (a == b) {
        return 1;
    }

    return 0; // Default return in case of unexpected input
}

int main() {
    int n; // Number of pairs
    scanf("%d", &n); // Read an integer input 'n'
    int results[n]; // Array to store results

    // Loop to read 'n' pairs of integers
    for (int i = 0; i < n; i++) {
        int a, b; // Declare variables for the pair
        scanf("%d %d", &a, &b); // Read a pair of integers
        results[i] = substract(a, b); // Call the substract function and store the result
    }

    // Loop to print each result stored in the array
    for (int i = 0; i < n; i++) {
        printf("%d\n", results[i]);
    }

    return 0; // Return success
}

// <END-OF-CODE>
