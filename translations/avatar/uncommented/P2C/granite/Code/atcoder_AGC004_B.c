
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, x ;
    scanf ( "%d %d", & n, & x ) ;
    int * a = ( int * ) malloc ( sizeof ( int ) * n ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", a + i ) ;
    }
    int * * b = ( int * * ) malloc ( sizeof ( int * ) * n ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        b [ i ] = ( int * ) malloc ( sizeof ( int ) * n ) ;
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        int m = a [ i ] ;
        for ( int j = 0 ; j < n ; j ++ ) {
            int k = i - j ;
            if ( k < 0 ) {
                k += n ;
            }
            m = m < a [ k ]? m : a [ k ] ;
            b [ j ] [ i ] = m ;
        }
    }
    int m = 1000000000 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        int sum = 0 ;
        for ( int j = 0 ; j < n ; j ++ ) {
            sum += b [ j ] [ i ] ;
        }
        sum += x * i ;
        m = m < sum? m : sum ;
    }
    printf ( "%d\n", m ) ;
    return 0 ;
}
