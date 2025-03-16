#include <stdio.h> // Importing the 'stdio.h' library for input/output operations

int main() {
    int a; // Declaring a variable 'a' of type 'int'

    // Reading an integer value from the standard input using 'scanf'
    scanf("%d", &a);

    // Multiplying the value of 'a' with itself twice and storing the result in a variable
    int result = 3 * a * a;

    // Printing the result to the standard output using 'printf'
    printf("%d\n", result);
    // This line prints the square of the number 'a' multiplied by 3

    return 0; // Returning 0 to indicate successful execution
}

