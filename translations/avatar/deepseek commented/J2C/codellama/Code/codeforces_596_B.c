
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    int n ;
    long *arr ;
    long answer ;
    scanf ( "%d", &n ) ;
    arr = ( long * ) malloc ( n * sizeof ( long ) ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%ld", &arr [ i ] ) ;
    }
    answer = abs ( arr [ 0 ] ) ;
    for ( int i = 1 ; i < n ; i ++ ) {
        answer += abs ( arr [ i ] - arr [ i - 1 ] ) ;
    }
    printf ( "%ld\n", answer ) ;
    free ( arr ) ;
    return 0 ;
}
