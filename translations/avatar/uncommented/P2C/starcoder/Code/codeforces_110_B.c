#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    char *s = malloc ( 1000000 );
    int n;
    scanf ( "%d", &n );
    for ( int i = 0 ; i < n ; i++ )
        s [ i ] = "abcd" [ i % 4 ];
    printf ( "%s\n", s );
    return 0;
}
