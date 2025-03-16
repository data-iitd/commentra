#include <stdio.h>

int main() {
    // Read two integers from input and assign them to variables a and b
    int a, b;
    scanf("%d %d", &a, &b);

    // Initialize the variable 'hole' to represent the current hole position
    int hole = 1;

    // Initialize a counter 'i' to track the number of iterations
    int i = 0;

    // Set a flag 'check' to control the while loop
    int check = 1; // true

    // Continue looping until the condition is met
    while (check) {
        // Check if the current hole position is greater than or equal to b
        if (hole >= b) {
            // If so, exit the loop
            check = 0; // false
        } else {
            // Calculate the new hole position based on the formula
            hole = a * (i + 1) - i;

            // Increment the iteration counter
            i++;
        }
    }

    // Print the total number of iterations (i) when the loop ends
    printf("%d\n", i);

    return 0;
}

// <END-OF-CODE>
