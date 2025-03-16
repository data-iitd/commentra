#include <stdio.h> // Include the standard input-output library

int main() { // Entry point of the program
    int a, b; // Declare variables for input
    scanf("%d", &a); // Read the first integer value from user input
    scanf("%d", &b); // Read the second integer value from user input
    
    int res = a; // Initialize the result variable with the value of 'a'
    
    while (a >= b) { // Start a while loop that continues as long as 'a' is greater than or equal to 'b'
        res += (a / b); // Increment the result variable by the result of dividing 'a' by 'b'
        
        a = (a / b) + (a % b); // Update the value of 'a' with the result of the division and the remainder
    }
    
    printf("%d\n", res); // Print the value of the result variable to the standard output stream
    return 0; // Return 0 to indicate successful completion
} // <END-OF-CODE>
