
#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library

int main ( void ) {
    int n ; // Declare an integer variable to store the input
    scanf ( "%d", &n ) ; // Read an integer input using scanf
    
    char s [ 100 ] = { 0 } ; // Declare a character array to store the binary representation
    int i = 0 ; // Initialize a variable to keep track of the index
    
    // Convert the integer to binary representation
    while ( n > 0 ) {
        int x = n % 2 ; // Get the remainder when divided by 2
        n /= 2 ; // Divide the number by 2
        s [ i ++ ] = x + '0' ; // Append the remainder to the string
    }
    
    int ans = 0 ; // Initialize a variable to count the number of '1's
    
    // Count the number of '1's in the binary representation
    for ( int j = 0 ; j < i ; j ++ ) {
        if ( s [ j ] == '1' ) {
            ans ++ ; // Increment the count if the character is '1'
        }
    }
    
    printf ( "%d", ans ) ; // Print the count of '1's using printf
    
    return 0 ; // Return 0 to indicate successful execution
}
