
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main ( ) {
    int x = 0 , y = 0 ;
    int t = 0 ;
    int n = 0 ;
    char str [ ] = { '\0' } ;
    char l [ ] = { '\0' } ;

    scanf ( "%d", &n ) ; // Read the integer n
    scanf ( "%s", str ) ; // Read the string str
    l = str ; // Convert the string to a character array

    // Check each character in the character array
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( l [ i ] != '4' && l [ i ] != '7' ) {
            t = 1 ; // Set t to 1 if a character is neither '4' nor '7'
        }
    }

    // If t is 1, print "NO"
    if ( t == 1 ) {
        printf ( "NO" ) ;
    } else {
        // Calculate the sum of the first half of the character array
        for ( int i = 0 ; i < n / 2 ; i ++ ) {
            x = x + l [ i ] - '0' ;
        }
        // Calculate the sum of the second half of the character array
        for ( int i = n - 1 ; i > ( n / 2 ) - 1 ; i -- ) {
            y = y + l [ i ] - '0' ;
        }
        // If x equals y, print "YES", otherwise print "NO"
        if ( x == y ) {
            printf ( "YES" ) ;
        } else {
            printf ( "NO" ) ;
        }
    }

    return 0 ;
}

