#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n ; // Declaring an integer variable to store the input
    char s [ 100 ] = { 0 } ; // Declaring a character array to store the binary representation
    int ans = 0 ; // Declaring an integer variable to count the number of '1's
    
    // Reading an integer input
    scanf ( "%d", &n ) ;
    
    // Converting the integer to binary representation
    while ( n > 0 ) {
        int x = n % 2 ; // Getting the remainder when divided by 2
        n /= 2 ; // Dividing the number by 2
        sprintf ( s, "%d%s", x, s ) ; // Appending the remainder to the string
    }
    
    // Counting the number of '1's in the binary representation
    for ( int i = 0 ; i < strlen ( s ) ; i ++ ) {
        if ( s [ i ] == '1' ) {
            ans ++ ; // Incrementing the count if the character is '1'
        }
    }
    
    printf ( "%d\n", ans ) ; // Printing the count of '1's
    
    return 0 ;
}

