#include <stdio.h> // Include the stdio.h library for input/output operations

int main() // Begin the main function
{
    int a; // Declare an integer variable named 'a'

    scanf("%d", &a); // Read an integer value from the user and store it in variable 'a'

    // Calculate the value of the expression (a + (a * a) + (a * a * a)) and print it
    printf("%d\n", (a + (a * a) + (a * a * a)));

    return 0; // Indicate successful execution of the program
}

// <END-OF-CODE>
