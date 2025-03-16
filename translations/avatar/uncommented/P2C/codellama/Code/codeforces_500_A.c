#include <stdio.h>
int main ( ) {
    int n, t;
    scanf ( "%d %d", &n, &t );
    int s [ n ];
    for ( int i = 0; i < n; i++ ) {
        scanf ( "%d", &s [ i ] );
    }
    int current_cell = 0;
    while ( current_cell <= t ) {
        current_cell += s [ current_cell - 1 ];
        if ( current_cell == t ) {
            printf ( "YES\n" );
            return 0;
        }
    }
    printf ( "NO\n" );
    return 0;
}
