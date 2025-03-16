#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x); // Read an integer from the input
    int bool = (x == 1) ? 1 : 0; // Convert the integer x to a boolean value bool using a ternary operator
    int result = !bool ? 1 : 0; // Calculate the result based on the boolean value bool
    printf("%d\n", result); // Print the result
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
