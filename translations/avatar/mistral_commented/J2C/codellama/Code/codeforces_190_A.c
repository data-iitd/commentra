#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    // Declaring a variable named 'n' of type 'int'
    int n ;
    // Declaring a variable named 'm' of type 'int'
    int m ;

    // Reading the first integer 'n' from the standard input
    scanf ( "%d", &n ) ;

    // Reading the second integer 'm' from the standard input
    scanf ( "%d", &m ) ;

    // Checking if 'n' is equal to zero
    if ( n == 0 ) {
        // If 'm' is not equal to zero, print "Impossible"
        if ( m != 0 ) {
            printf ( "Impossible" ) ;
        } else { // If 'm' is also zero, print '0' space '0'
            printf ( "%d %d", 0, 0 ) ;
        }
        // Returning from the main method
        return 0 ;
    }

    // Checking if 'm' is less than or equal to 'n'
    if ( m <= n ) {
        // If 'm' is zero, assign it the value 1
        if ( m == 0 ) {
            m = 1 ;
        }
        // Printing 'n' and the sum of 'm' and 'n' minus one
        printf ( "%d %d", n, m + n - 1 ) ;
        // Returning from the main method
        return 0 ;
    }

    // If 'm' is greater than 'n', print 'm' and the sum of 'm' and 'n' minus one
    printf ( "%d %d", m, m + n - 1 ) ;

    // Ending the C code with comment "