#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int max_level, i, j, k, n, m, flag = 0;
    scanf ( "%d", &max_level );
    int *x = ( int * ) malloc ( max_level * sizeof ( int ) );
    int *y = ( int * ) malloc ( max_level * sizeof ( int ) );
    for ( i = 0 ; i < max_level ; i++ ) {
        scanf ( "%d", &x[i] );
    }
    for ( i = 0 ; i < max_level ; i++ ) {
        scanf ( "%d", &y[i] );
    }
    x[max_level] = 0;
    y[max_level] = 0;
    n = max_level;
    m = max_level;
    for ( i = 0 ; i < n ; i++ ) {
        if ( x[i] == 0 ) {
            n--;
        }
    }
    for ( i = 0 ; i < m ; i++ ) {
        if ( y[i] == 0 ) {
            m--;
        }
    }
    for ( i = 0 ; i < n ; i++ ) {
        for ( j = 0 ; j < m ; j++ ) {
            if ( x[i] == y[j] ) {
                flag = 1;
                break;
            }
        }
        if ( flag == 1 ) {
            break;
        }
    }
    if ( n!= max_level || m!= max_level || flag == 1 ) {
        printf ( "Oh, my keyboard!\n" );
    } else {
        printf ( "I become the guy.\n" );
    }
    return 0;
}
