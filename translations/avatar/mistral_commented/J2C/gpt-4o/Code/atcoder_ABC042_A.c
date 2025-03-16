#include <stdio.h> // Include standard input-output library
#include <stdlib.h> // Include standard library for atoi function

int main() {
    // Declare variables to hold the input values
    int x, a, y;
    // Initialize a string variable h with the value "NO"
    char *h = "NO";

    // Read a line of input from the console
    char line[100];
    fgets(line, sizeof(line), stdin);

    // Parse the first three integers from the input line
    sscanf(line, "%d %d %d", &x, &a, &y);

    // Check if any of the numbers x, a, or y are equal to 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // If any of the numbers satisfy the condition, check if their sum is equal to 17
        if (x + y + a == 17) {
            // If the sum is equal to 17, set the value of h to "YES"
            h = "YES";
        }
    }

    // Print the value of h to the console
    printf("%s\n", h);

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
