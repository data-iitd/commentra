#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n, k;
    scanf ( "%d %d", &n, &k );
    int *elems = ( int * ) malloc ( n * sizeof ( int ) );
    for ( int i = 0 ; i < n ; i ++ )
        scanf ( "%d", &elems [ i ] );
    int all_same = 1;
    for ( int i = 1 ; i < n ; i ++ )
        if ( elems [ i ]!= elems [ 0 ] )
            all_same = 0;
    if ( all_same ) {
        printf ( "0\n" );
        return 0;
    }
    if ( k == 1 ) {
        printf ( "-1\n" );
        return 0;
    }
    if ( elems [ k - 1 ]!= elems [ n - 1 ] ) {
        printf ( "-1\n" );
        return 0;
    }
    int target = elems [ n - 1 ];
    int *to_delete = ( int * ) malloc ( k * sizeof ( int ) );
    for ( int i = 0 ; i < k ; i ++ )
        to_delete [ i ] = elems [ i ];
    while ( to_delete [ k - 1 ] == target )
        k --;
    printf ( "%d\n", k );
    return 0;
}
