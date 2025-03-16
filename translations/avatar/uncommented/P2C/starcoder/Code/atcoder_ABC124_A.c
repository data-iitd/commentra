#include <stdio.h>
#include <stdlib.h>
int main ( )
{
    int a, b, c = 0 ;
    scanf ( "%d %d", &a, &b ) ;
    for ( int i = 0 ; i < 2 ; i++ )
    {
        c += max ( a, b ) ;
        if ( a >= b )
            a-- ;
        else
            b-- ;
    }
    printf ( "%d", c ) ;
    return 0 ;
}
