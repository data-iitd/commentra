#include <stdio.h>

// Function to read an integer as input
int scanInt() {
    int num;
    scanf("%d", &num); // Read an integer from standard input
    return num;        // Return the integer
}

// Main function to execute the program
int main() {
    // Read the first three integers as input
    int r = scanInt();
    int D = scanInt();
    int x = scanInt();

    // Iterate through a loop 10 times
    for (int i = 1; i <= 10; i++) {
        // Calculate the new value of x using the given formula
        x = r * x - D;

        // Print the value of x to the console
        printf("%d\n", x);
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
