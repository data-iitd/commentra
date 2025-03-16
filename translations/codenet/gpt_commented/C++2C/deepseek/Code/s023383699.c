#include <stdio.h> // Include the stdio library for input and output operations

int main() { // Main function where the program execution begins
    int x; // Declare an integer variable 'x' to store user input
    scanf("%d", &x); // Read an integer value from the user and store it in 'x'
    
    // Calculate the cube of 'x' and print the result
    printf("%d\n", x * x * x); // Output the cube of 'x' followed by a newline

    return 0; // Return 0 to indicate that the program ended successfully
}
