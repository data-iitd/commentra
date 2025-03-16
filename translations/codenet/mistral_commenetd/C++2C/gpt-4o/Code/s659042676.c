#include <stdio.h> // Header for standard input/output operations

int main() {
    int a, b; // Declare two integer variables `a` and `b`

    // Read two integer values from the standard input using `scanf`
    scanf("%d %d", &a, &b);

    // Calculate the difference between `6` and the sum of `a` and `b`
    int result = 6 - a - b;

    // Print the result to the standard output using `printf`
    printf("%d\n", result);

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
