#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int t, m, i, j, pos, cnt, ind = 1;
    scanf ( "%d %d", &t, &m );
    int *alocuente = ( int * ) malloc ( m * sizeof ( int ) );
    for ( i = 0 ; i < m ; i++ )
        alocuente [ i ] = 0;
    for ( i = 0 ; i < t ; i++ ) {
        char *op = ( char * ) malloc ( 100 * sizeof ( char ) );
        scanf ( "%s", op );
        if ( strcmp ( op, "alloc" ) == 0 ) {
            scanf ( "%d", &pos );
            for ( j = 0 ; j < m ; j++ ) {
                if ( alocuente [ j ] == 0 ) {
                    pos++;
                    if ( pos == atoi ( op + 6 ) ) {
                        for ( j = j - atoi ( op + 6 ) + 1 ; j < j + atoi ( op + 6 ) ; j++ )
                            alocuente [ j ] = ind;
                        printf ( "%d\n", ind );
                        ind++;
                        break;
                    }
                }
                else
                    pos = 0;
            }
            if ( j == m )
                printf ( "NULL\n" );
        }
        if ( strcmp ( op, "erase" ) == 0 ) {
            scanf ( "%d", &pos );
            if ( pos == 0 || pos > m || alocuente [ pos - 1 ]!= pos )
                printf ( "ILLEGAL_ERASE_ARGUMENT\n" );
            else {
                for ( j = pos - 1 ; j < m - 1 ; j++ )
                    alocuente [ j ] = alocuente [ j + 1 ];
                alocuente [ m - 1 ] = 0;
            }
        }
        if ( strcmp ( op, "defragment" ) == 0 ) {
            cnt = 0;
            for ( j = 0 ; j < m ; j++ )
                if ( alocuente [ j ] == 0 )
                    cnt++;
            for ( j = 0 ; j < m ; j++ )
                if ( alocuente [ j ]!= 0 )
                    alocuente [ j - cnt ] = alocuente [ j ];
            for ( j = m - 1 ; j >= m - cnt ; j-- )
                alocuente [ j ] = 0;
        }
        free ( op );
    }
    free ( alocuente );
    return 0;
}
