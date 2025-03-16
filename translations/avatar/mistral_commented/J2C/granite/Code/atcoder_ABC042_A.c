
#include <stdio.h> // Include standard input/output library

int main() {
    // Declare and initialize variables x, a, and y as integers
    int x, a, y;

    // Read three integers from the console and store them in variables x, a, and y
    scanf("%d %d %d", &x, &a, &y);

    // Initialize a string variable h with the value "NO"
    char h[] = "NO";

    // Check if any of the numbers x, a, or y are equal to 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // If any of the numbers satisfy the condition, check if their sum is equal to 17
        if (x + y + a == 17) {
            // If the sum is equal to 17, set the value of h to "YES"
            h[0] = 'Y';
            h[1] = 'E';
            h[2] = 'S';
        }
    }

    // Print the value of h to the console
    printf("%s\n", h);

    return 0; // Return 0 to indicate successful execution of the program
}
