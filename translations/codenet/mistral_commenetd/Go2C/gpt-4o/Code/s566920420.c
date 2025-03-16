#include <stdio.h> // Include the standard I/O library

int main() {
    // Declare a variable named "a" of type int
    int a;

    // Read a value of type int from the standard input and store it in the variable "a"
    scanf("%d", &a);

    // Calculate the result of the expression "a + a*a + a*a*a"
    int result = a + a * a + a * a * a;

    // Print the result to the standard output
    printf("%d\n", result);

    // End of code
    return 0; // Return 0 to indicate successful completion
} // <END-OF-CODE>
