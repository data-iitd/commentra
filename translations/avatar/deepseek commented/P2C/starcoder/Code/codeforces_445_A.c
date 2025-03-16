
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ( ) {
    int n, m;
    scanf ( "%d %d", &n, &m );
    char **l = ( char ** ) malloc ( n * sizeof ( char * ) );
    for ( int i = 0; i < n; i++ ) {
        char *s = ( char * ) malloc ( m + 1 );
        scanf ( "%s", s );
        for ( int j = 0; j < m; j++ ) {
            if ( s[j] == '.' ) {
                if ( ( i + j ) & 1 ) s[j] = 'W';
                else s[j] = 'B';
            }
        }
        l[i] = s;
    }
    for ( int i = 0; i < n; i++ ) {
        printf ( "%s\n", l[i] );
        free ( l[i] );
    }
    free ( l );
    return 0;
}

