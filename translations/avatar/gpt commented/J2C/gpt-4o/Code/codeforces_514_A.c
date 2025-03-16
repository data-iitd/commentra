#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize a variable to store the input number
    long x;
    
    // Read a long integer from the user
    scanf("%ld", &x);
    
    // Initialize an array to store the digits after transformation
    long list[20]; // Assuming the number of digits won't exceed 20
    int index = 0;

    // Process each digit of the number until there are no digits left
    while (x > 0) {
        // Extract the last digit of the number
        long r = x % 10;

        // Determine whether to keep the digit or replace it with its complement to 9
        if (9 - r < r) {
            // If the digit is the last one and its complement is 0, keep the digit
            if (x / 10 == 0 && 9 - r == 0)
                list[index++] = r;
            else
                // Otherwise, add the complement to the list
                list[index++] = 9 - r;
        } else
            // If the digit is less than or equal to its complement, keep the digit
            list[index++] = r;

        // Remove the last digit from the number
        x = x / 10;
    }

    // Initialize variables to construct the new number
    long newNumber = 0;

    // Reconstruct the new number from the transformed digits
    for (int i = index - 1; i >= 0; i--) {
        newNumber = newNumber * 10 + list[i];
    }

    // Output the newly constructed number
    printf("%ld\n", newNumber);

    return 0;
}

// <END-OF-CODE>
