#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s [ 1000001 ] ;
    int cum [ 1000001 ] ;
    int q ;
    scanf ( "%s", s ) ;
    cum [ 0 ] = cum [ strlen ( s ) ] = 0 ;
    for ( int i = 1 ; i < strlen ( s ) ; i ++ )
    {
        if ( s [ i ] == s [ i - 1 ] )
            cum [ i ] = cum [ i - 1 ] + 1 ;
        else
            cum [ i ] = cum [ i - 1 ] ;
    }
    scanf ( "%d", &q ) ;
    while ( q -- )
    {
        scanf ( "%d %d", &l, &r ) ;
        r -- ;
        printf ( "%d\n", cum [ r ] - cum [ l - 1 ] ) ;
    }
    return 0 ;
}
