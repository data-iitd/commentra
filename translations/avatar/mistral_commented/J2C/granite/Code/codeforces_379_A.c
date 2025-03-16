

#include <stdio.h> // Include the standard input/output header file

int main ( void ) { // Entry point of the program
    int a, b, res ; // Declare three integer variables: 'a', 'b', and'res'
    
    scanf ( "%d %d", &a, &b ) ; // Read the first and second integer values from the standard input stream
    
    res = a ; // Initialize the result variable with the value of 'a'
    
    while ( a >= b ) { // Start a while loop that continues as long as 'a' is greater than or equal to 'b'
        res += ( a / b ) ; // Increment the result variable by the result of dividing 'a' by 'b'
        
        a = ( a / b ) + ( a % b ) ; // Update the value of 'a' with the result of the division and the remainder
    }
    
    printf ( "%d\n", res ) ; // Print the value of the result variable to the standard output stream
    
    return 0 ; // Return 0 to indicate successful execution of the program
}

