#include <stdio.h> // Include the stdio.h library for input and output operations

int main() { // Beginning of the main function
    int x; // Declare an integer variable named x

    scanf("%d", &x); // Read an integer value from the standard input and store it in variable x

    if (x >= 1200) { // Beginning of the if statement block
        printf("ARC\n"); // Output the string "ARC" to the standard output if the condition is true
    }
    else { // Beginning of the else statement block
        printf("ABC\n"); // Output the string "ABC" to the standard output if the condition is false
    }

    return 0; // Indicate successful execution of the program and return control to the operating system
}

// <END-OF-CODE>
