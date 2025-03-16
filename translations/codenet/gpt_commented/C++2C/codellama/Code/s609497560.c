#include <stdio.h> // Include the iostream library for input and output operations

int main() // Main function where the execution of the program begins
{
    int a; // Declare an integer variable 'a' to store user input

    // Prompt the user to enter a value for 'a'
    printf("Enter a number: "); 
    scanf("%d", &a); // Read the input value from the user and store it in 'a'

    // Calculate the expression a + a^2 + a^3 and output the result
    printf("%d\n", (a + (a * a) + (a * a * a)));

    return 0; // Return 0 to indicate that the program finished successfully
}

