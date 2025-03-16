
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ( )
{
    char txt [ 100 ];
    int cu = 0, cl = 0;
    printf ( "Enter a string: " );
    scanf ( "%s", txt );
    for ( int i = 0; i < strlen ( txt ); i++ )
    {
        if ( islower ( txt [ i ] ) )
            cl++;
        else
            cu++;
    }
    if ( cu > cl )
        printf ( "%s", toupper ( txt ) );
    else
        printf ( "%s", tolower ( txt ) );
    return 0;
}
