
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, levels, level2, level3, count = 0, i, j, x;
    scanf ( "%d %d", &n, &levels );
    int arr [ levels ];
    for ( i = 0; i < levels; i++ ) {
        scanf ( "%d", &arr [ i ] );
    }
    scanf ( "%d", &level2 );
    level3 = levels + level2;
    int arr2 [ level3 ];
    for ( i = 0; i < arr.length; i++ ) {
        arr2 [ i ] = arr [ i ];
    }
    for ( i = arr.length; i < level3; i++ ) {
        scanf ( "%d", &arr2 [ i ] );
    }
    int arr3 [ n ];
    j = 0;
    for ( i = 0; i < n; i++ ) {
        arr3 [ i ] = ++ j;
    }
    for ( i = 0; i < n; i++ ) {
        for ( x = 0; x < arr2.length; x++ ) {
            if ( arr3 [ i ] == arr2 [ x ] ) {
                count++;
                break;
            }
        }
    }
    if ( count == n ) {
        printf ( "I become the guy.\n" );
    } else {
        printf ( "Oh, my keyboard!\n" );
    }
    return 0;
}

