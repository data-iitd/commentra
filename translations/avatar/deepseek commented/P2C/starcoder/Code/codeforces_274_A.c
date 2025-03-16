
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int num, k, temp = 0, i = 0 ;
    scanf ( "%d %d", &num, &k ) ;
    int * arr = ( int * ) malloc ( num * sizeof ( int ) ) ;
    for ( i = 0 ; i < num ; i++ ) {
        scanf ( "%d", &arr[i] ) ;
    }
    qsort ( arr, num, sizeof ( int ), cmpfunc ) ;
    for ( i = 0 ; i < num ; i++ ) {
        if ( arr[i] % k!= 0 || arr[i] / k < 0 ) {
            temp = temp + 1 ;
        }
    }
    printf ( "%d", temp ) ;
    return 0 ;
}

int cmpfunc ( const void * a, const void * b ) {
    return ( *( int * ) a - *( int * ) b ) ;
}

