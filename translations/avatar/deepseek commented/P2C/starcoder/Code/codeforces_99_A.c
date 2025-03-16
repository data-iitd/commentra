
#include <stdio.h>
#include <string.h>

int main ( )
{
    char l [ 100 ];
    scanf ( "%s", l );
    char s [ 100 ];
    strcpy ( s, l );
    char p [ 100 ];
    strcpy ( p, l );
    int i = p [ 0 ] - '0';
    if ( s [ strlen ( s ) - 1 ] == '9' )
    {
        printf ( "GOTO Vasilisa.\n" );
    }
    else if ( s [ strlen ( s ) - 1 ]!= '9' && i < 5 )
    {
        printf ( "%s\n", s );
    }
    else
    {
        s [ strlen ( s ) - 1 ] = s [ strlen ( s ) - 1 ] + 1;
        printf ( "%s\n", s );
    }
    return 0;
}

