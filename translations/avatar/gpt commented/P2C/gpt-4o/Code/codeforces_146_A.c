#include <stdio.h>

int main() {
    int n;
    // Read an integer input which represents the number of elements
    scanf("%d", &n);

    int number[n]; // Declare an array to hold the numbers
    // Read a list of integers from input
    for (int i = 0; i < n; i++) {
        scanf("%d", &number[i]);
    }

    int h1 = 0; // Sum of the first half
    int h2 = 0; // Sum of the second half
    int x = 0;  // Flag to check if any number is not 4 or 7

    // Iterate through the list of numbers
    for (int i = 0; i < n; i++) {
        // Check if the current number is neither 4 nor 7
        if (number[i] != 4 && number[i] != 7) {
            printf("NO\n"); // Print "NO" if an invalid number is found
            x = 1;          // Set the flag to indicate an invalid number was found
            break;          // Exit the loop since we found an invalid number
        }

        // Sum the first half of the numbers
        if (i < n / 2) {
            h1 += number[i];
        } else {
            // Sum the second half of the numbers
            h2 += number[i];
        }
    }

    // After checking all numbers, determine if the sums of both halves are equal
    if (x == 0) { // Proceed only if no invalid numbers were found
        if (h1 == h2) {
            printf("YES\n"); // Print "YES" if the sums are equal
        } else {
            printf("NO\n");  // Print "NO" if the sums are not equal
        }
    }

    return 0;
}
// <END-OF-CODE>
