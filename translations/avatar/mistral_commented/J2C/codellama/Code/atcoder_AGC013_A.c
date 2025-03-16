
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int N ; // Declaring the number of elements in the array
    int * A ; // Declaring a pointer to an integer array
    int i , j , count = 0 ; // Declaring the loop variables and the count variable

    // Reading the number of elements in the array from the standard input
    scanf ( "%d" , &N ) ;

    // Allocating memory for the integer array
    A = ( int * ) malloc ( N * sizeof ( int ) ) ;

    // Reading the elements of the array from the standard input
    for ( i = 0 ; i < N ; i ++ ) {
        scanf ( "%d" , &A [ i ] ) ;
    }

    // Iterating through the array to find the number of increasing and decreasing sequences
    for ( i = 0 ; i < N - 1 ; i ++ ) {
        if ( i == N - 1 ) count ++ ;
        else if ( A [ i ] == A [ i + 1 ] ) ;
        else if ( A [ i ] < A [ i + 1 ] ) {
            while ( A [ i ] <= A [ i + 1 ] ) {
                i ++ ;
                if ( i == N - 1 ) break ;
            }
            count ++ ;
        } else {
            while ( A [ i ] >= A [ i + 1 ] ) {
                i ++ ;
                if ( i == N - 1 ) break ;
            }
            count ++ ;
        }
    }

    printf ( "%d\n" , count ) ;

    // Freeing the memory allocated for the integer array
    free ( A ) ;

    return 0 ;
}

