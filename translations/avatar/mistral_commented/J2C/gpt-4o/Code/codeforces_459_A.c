#include <stdio.h> // Include standard input and output library
#include <stdlib.h> // Include standard library for abs function

int main() { // Define the main function
    int x1, y1, x2, y2; // Declare variables for coordinates

    // Read the coordinates from standard input
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if (x1 == x2) { // Check if x1 and x2 are equal
        int dif = abs(y1 - y2); // Calculate the absolute difference between y1 and y2
        printf("%d %d %d %d\n", (x1 + dif), y1, (x1 + dif), y2); // Print the result
    } else if (y1 == y2) { // Check if y1 and y2 are equal
        int dif = abs(x1 - x2); // Calculate the absolute difference between x1 and x2
        printf("%d %d %d %d\n", x1, (y1 + dif), x2, (y2 + dif)); // Print the result
    } else if (abs(x1 - x2) == abs(y1 - y2)) { // Check if the absolute differences are equal
        printf("%d %d %d %d\n", x1, y2, x2, y1); // Print the result
    } else { // If none of the above conditions are met
        printf("-1\n"); // Print -1
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
