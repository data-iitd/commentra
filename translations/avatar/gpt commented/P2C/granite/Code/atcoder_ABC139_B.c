
#include <stdio.h>

int main() {
    int a, b, hole = 1, i = 0;
    // Read two integers from input and assign them to variables a and b
    scanf("%d %d", &a, &b);

    // Set a flag check to control the while loop
    int check = 1;

    // Continue looping until the condition is met
    while (check) {
        // Check if the current hole position is greater than or equal to b
        if (hole >= b) {
            // If so, exit the loop
            check = 0;
        } else {
            // Calculate the new hole position based on the formula
            hole = a * (i + 1) - i;

            // Increment the iteration counter
            i++;
        }
    }

    // Print the total number of iterations (i) when the loop ends
    printf("%d", i);

    return 0;
}
