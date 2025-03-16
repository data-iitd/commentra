#include <stdio.h> // Including the standard input-output library

int main() {
    // Declaring a variable 'data' of type 'int' to read user input
    int data;

    // Reading user input and storing it in the 'data' variable
    scanf("%d", &data);

    // Declaring a variable 'result' of type 'int' to store the result
    int result;

    // Assigning the value of 'data' cubed to the 'result' variable
    result = data * data * data;

    // Printing the result using 'printf' function
    printf("%d\n", result); // Printing the result with format specifier '%d' and newline character '\n'

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
