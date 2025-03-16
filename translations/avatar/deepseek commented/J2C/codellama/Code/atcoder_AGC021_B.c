
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    // Step 1: Read the number of points N from the input.
    int N ;
    scanf ( "%d" , &N ) ;
    
    // Step 2: Read the coordinates of each point and store them in arrays x and y.
    int * x = ( int * ) malloc ( N * sizeof ( int ) ) ;
    int * y = ( int * ) malloc ( N * sizeof ( int ) ) ;
    for ( int i = 0 ; i < N ; ++ i ) {
        scanf ( "%d%d" , &x [ i ] , &y [ i ] ) ;
    }
    
    // Step 3: For each point, calculate the angles between this point and all other points.
    for ( int i = 0 ; i < N ; ++ i ) {
        double * thetas = ( double * ) malloc ( N * sizeof ( double ) ) ;
        for ( int j = 0 ; j < N ; ++ j ) {
            if ( i == j ) continue ; // Skip the point itself
            // Calculate the angle using atan2
            thetas [ j ] = atan2 ( y [ j ] - y [ i ] , x [ j ] - x [ i ] ) ;
        }
        
        // Step 4: Sort the angles and add 2π to the last angle to handle the wrap-around.
        qsort ( thetas , N , sizeof ( double ) , cmp ) ;
        thetas [ N - 1 ] += 2 * M_PI ;
        
        // Step 5: Find the maximum difference between consecutive angles, subtract π, and divide by 2π to get the fraction of the circle.
        double ans = 0 ;
        for ( int k = 0 ; k < N - 1 ; ++ k )
            ans = fmax ( ans , thetas [ k + 1 ] - thetas [ k ] - M_PI ) ;
        
        // Step 6: Print the result.
        printf ( "%.10lf\n" , ans / ( M_PI * 2 ) ) ;
        
        free ( thetas ) ;
    }
    
    free ( x ) ;
    free ( y ) ;
    
    return 0 ;
}

int cmp ( const void * a , const void * b ) {
    return ( * ( double * ) a - * ( double * ) b ) < 0 ;
}

