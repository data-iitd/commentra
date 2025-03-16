#include <stdio.h> // Include the standard input-output library for console I/O

int main() {
    int r; // Declare an integer variable 'r' to store the radius

    // Read the radius value from user input
    scanf("%d", &r);

    // Calculate the area of the circle using the formula πr²
    // Here, we are using the simplified version by omitting π for demonstration
    printf("%d\n", (r * r)); // Output the calculated area (r squared)

    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
