
#include <stdio.h>

int main() {
    // Create a variable to store the input value
    int x;
    // Read an integer input from the user
    scanf("%d", &x);
    // Initialize a counter to keep track of the number of rotations
    int count = 0;
    // Store the original value of x for later use
    int tmp = x;
    // Reset x to 0 for the rotation calculation
    x = 0;
    // Loop until x completes a full rotation (360 degrees)
    while (x!= 360) {
        // Increment x by the original input value
        x = x + tmp;
        // If x exceeds 360, wrap it around by subtracting 360
        if (x > 360) {
            x = x - 360;
        }
        // Increment the count of rotations
        count++;
    }
    // Output the total number of rotations needed to reach 360 degrees
    printf("%d", count);
    // End the program
    return 0;
}

// End of code