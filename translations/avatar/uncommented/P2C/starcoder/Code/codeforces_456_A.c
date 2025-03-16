#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, i, j, k, a, b, c, d;
    scanf ( "%d", &n );
    int m [ n ][ 4 ];
    for ( i = 0 ; i < n ; i ++ )
        for ( j = 0 ; j < 4 ; j ++ )
            scanf ( "%d", &m [ i ][ j ] );
    for ( i = 0 ; i < n ; i ++ )
        for ( j = i + 1 ; j < n ; j ++ )
            if ( m [ i ][ 1 ] < m [ j ][ 1 ] ) {
                a = m [ i ][ 0 ];
                b = m [ i ][ 1 ];
                c = m [ i ][ 2 ];
                d = m [ i ][ 3 ];
                m [ i ][ 0 ] = m [ j ][ 0 ];
                m [ i ][ 1 ] = m [ j ][ 1 ];
                m [ i ][ 2 ] = m [ j ][ 2 ];
                m [ i ][ 3 ] = m [ j ][ 3 ];
                m [ j ][ 0 ] = a;
                m [ j ][ 1 ] = b;
                m [ j ][ 2 ] = c;
                m [ j ][ 3 ] = d;
            }
    for ( i = 0 ; i < n ; i ++ )
        if ( m [ i ][ 1 ] > m [ 0 ][ 1 ] ) {
            printf ( "Happy Alex\n" );
            break;
        }
    else
        printf ( "Poor Alex\n" );
    return 0;
}
