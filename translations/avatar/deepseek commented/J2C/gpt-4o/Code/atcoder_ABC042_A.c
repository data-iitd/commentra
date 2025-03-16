#include <stdio.h>

int main() {
    // Declare variables to store input values
    int x, a, y;
    // Initialize a variable to store the result
    char *h = "NO";

    // Read a line of input from the user
    scanf("%d %d %d", &x, &a, &y);

    // Check if any of the integers is either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // Check if the sum of the integers is 17
        if (x + y + a == 17) {
            h = "YES";
        }
    }

    // Print the result
    printf("%s\n", h);

    return 0;
}

// <END-OF-CODE>
