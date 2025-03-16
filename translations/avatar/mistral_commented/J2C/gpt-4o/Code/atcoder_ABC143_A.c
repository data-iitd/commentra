#include <stdio.h>

int main() {
    // Declare variables to hold input values
    int a, b, c;

    // Read input from the console
    if (scanf("%d %d", &a, &b) != 2) {
        // Handle input error
        return 1;
    }

    // Calculate the value of 'c' by subtracting 'b' multiplied by 2 from 'a'
    c = a - b * 2;

    // If the value of 'c' is negative, set it to zero
    if (c < 0) {
        c = 0;
    }

    // Print the value of 'c' to the console
    printf("%d\n", c);

    return 0;
}

// <END-OF-CODE>
