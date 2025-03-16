
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main ( ) {
    int N ;
    long X ;
    long *x ;
    long *xsum ;
    long ans ;
    int i ;
    int j ;
    int k ;

    // Read the number of points N and the target value X
    scanf ( "%d %ld" , &N , &X ) ;

    // Initialize an array to store the positions of N points
    x = ( long * ) malloc ( N * sizeof ( long ) ) ;
    xsum = ( long * ) malloc ( N + 1 * sizeof ( long ) ) ;

    // Read the positions of the points into the array x and calculate the cumulative sum
    for ( i = 0 ; i < N ; i ++ ) {
        scanf ( "%ld" , &x [ i ] ) ;
        xsum [ i + 1 ] = xsum [ i ] + x [ i ] ;
    }

    // Initialize ans with a value calculated using the total sum of positions and the given X value
    ans = X * N + 5 * xsum [ N ] ;

    // Iterate over possible values of i, which represents the number of points to be removed
    for ( i = 1 ; i < N ; i ++ ) {
        long cost = X * i + 5 * ( xsum [ N ] - xsum [ N - i ] ) ;

        // For each value of i, calculate the cost of removing i points and update ans if a better cost is found
        for ( j = 5 , k = N - i ; k >= 0 ; j += 2 , k -= i ) {
            if ( cost > ans ) {
                break ;
            }
            cost += j * ( xsum [ k ] - xsum [ k - i < 0 ? 0 : k - i ] ) ;
        }
        ans = ans < cost ? ans : cost ;
    }

    // Print the minimum cost found
    printf ( "%ld\n" , ans + N * X ) ;

    // Free the memory allocated for the arrays
    free ( x ) ;
    free ( xsum ) ;

    return 0 ;
}

