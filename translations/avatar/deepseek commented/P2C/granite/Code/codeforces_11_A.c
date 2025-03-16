

#include <stdio.h>

int main ( ) {
    int n, d ;
    scanf ( "%d %d", & n, & d ) ;
    // Taking input for two variables `n` and `d`

    int x [ n ] ;
    int m = 0 ;
    int q = 0 ;
    // Initializing an integer array `x` of size `n` and two integer variables `m` and `q` to 0

    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", & x [ i ] ) ;
        // Taking input for the array `x`
    }

    for ( int a = 0 ; a < n - 1 ; a ++ ) {
        if ( x [ a ] >= x [ a + 1 ] ) {
            q = ( x [ a ] - x [ a + 1 ] ) / d + 1 ;
            m = m + q ;
            x [ a + 1 ] = x [ a + 1 ] + q * d ;
        }
        // Checking if the current element is greater than or equal to the next element
        // Calculating the number of steps `q` needed to make the current element less than the next element by at least `d`
        // Updating the value of `m` by adding `q` to it
        // Updating the next element in the array `x` by adding `q * d` to it
    }

    printf ( "%d", m ) ;
    // Printing the value of `m`

    return 0 ;
}
// End of C code