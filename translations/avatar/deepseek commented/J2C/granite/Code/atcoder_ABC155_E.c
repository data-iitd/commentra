

#include <stdio.h>
#include <string.h>

int main ( void ) {
    // Define a constant for infinity
    const long long INF = 1e15;
    
    // Create a character array to store the input number
    char number [ 100001 ];
    
    // Read the input number from the user
    scanf ( "%s", number );
    
    // Calculate the length of the input number
    int length = strlen ( number );
    
    // Create an array to store the digits of the number
    int digits [ length + 1 ];
    
    // Convert the number into an array of digits
    for ( int i = 0; i < length; i ++ ) {
        digits [ i ] = number [ length - 1 - i ] - '0';
    }
    
    // Initialize the total bill to 0
    int bills = 0;
    
    // Loop through each digit to calculate the total bill
    for ( int i = 0; i <= length; i ++ ) {
        // Handle the case where the digit is 10
        if ( digits [ i ] == 10 ) {
            digits [ i + 1 ] ++ ;
            digits [ i ] = 0;
        }
        
        // Add the digit to the bill if it is less than 5
        if ( digits [ i ] < 5 ) {
            bills += digits [ i ];
        }
        // Handle the case where the digit is 5
        else if ( digits [ i ] == 5 ) {
            if ( digits [ i + 1 ] >= 5 ) {
                digits [ i + 1 ] ++ ;
            }
            bills += 5;
        }
        // Handle the case where the digit is greater than 5
        else {
            digits [ i + 1 ] ++ ;
            bills += 10 - digits [ i ];
        }
    }
    
    // Print the total bill
    printf ( "%d\n", bills );
    
    // End the program
    return 0;
}
