#include <stdio.h>

int main() {
    // Declare variables to hold the input values
    int x, a, y;
    // Initialize a variable to hold the result, defaulting to "NO"
    char *result = "NO";

    // Read a line of input and parse it into integers
    scanf("%d %d %d", &x, &a, &y);

    // Check if any of the numbers x, a, or y are either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // If the sum of x, a, and y equals 17, set the result to "YES"
        if (x + y + a == 17) {
            result = "YES";
        }
    }

    // Output the result
    printf("%s\n", result);

    return 0;
}

// <END-OF-CODE>
