

#include <stdio.h>

int main ( ) {
    int n, a [ 100000 ] ;
    scanf ( "%d", & n ) ;
    // Read the number of elements from input
    for ( int i = 0 ; i < n ; i ++ ) scanf ( "%d", & a [ i ] ) ;
    // Read the list elements from input

    if ( sum ( a ) % ( n * ( n + 1 ) / 2 ) ) {
        // Check if the sum of the list is divisible by the triangular number (n * (n + 1) / 2)
        printf ( "NO" ) ;
    } else {
        int k = sum ( a ) / ( n * ( n + 1 ) / 2 ) ;
        // Calculate the quotient k by dividing the sum of the list by the triangular number
        a [ n ] = a [ 0 ] ;
        // Append the first element to the end of the list to create a circular list

        if ( sum ( [ ( k - i + j ) % n for i, j in zip ( a [ 1 : ], a ) ] ) or sum ( [ ( k - i + j ) / n >= 0 for i, j in zip ( a [ 1 : ], a ) ] )!= n ) {
            // Check if the condition is met for all elements in the circular list
            printf ( "NO" ) ;
        } else {
            printf ( "YES" ) ;
            // If the condition is met, print "YES"
        }
    }
    return 0 ;
}
