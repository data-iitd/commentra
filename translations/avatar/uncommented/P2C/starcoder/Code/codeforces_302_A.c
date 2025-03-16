#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n, m, sa, i;
    scanf ( "%d %d", &n, &m );
    sa = 0;
    for ( i = 0 ; i < n ; i++ )
        if ( getchar ( ) == '-' )
            sa++;
    sa = min ( n - sa, sa );
    for ( i = 0 ; i < m ; i++ ) {
        int a, b;
        scanf ( "%d %d", &a, &b );
        b -= a;
        printf ( b % 2 && b <= sa << 1? "1\n" : "0\n" );
    }
    return 0;
}
