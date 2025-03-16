
#include <stdio.h>
#include <stdbool.h>

int main ( ) {
    int n, k;
    scanf ( "%d %d", &n, &k );
    int elems [ n ];
    for ( int i = 0; i < n; i ++ ) {
        scanf ( "%d", &elems [ i ] );
    }
    bool all_same ( int * arr, int len ) {
        for ( int i = 0; i < len; i ++ ) {
            if ( arr [ i ]!= arr [ 0 ] ) {
                return false;
            }
        }
        return true;
    }
    if ( all_same ( elems, n ) ) {
        printf ( "0\n" );
        return 0;
    }
    if ( k == 1 ) {
        printf ( "-1\n" );
        return 0;
    }
    if (! all_same ( elems + k - 1, n - k + 1 ) ) {
        printf ( "-1\n" );
        return 0;
    }
    int target = elems [ n - 1 ];
    int to_delete = 0;
    for ( int i = k - 2; i >= 0; i -- ) {
        if ( elems [ i ] == target ) {
            to_delete += 1;
        } else {
            break;
        }
    }
    printf ( "%d\n", to_delete );
}
