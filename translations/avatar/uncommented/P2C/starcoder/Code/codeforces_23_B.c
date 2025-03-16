#include <stdio.h>
int main ( )
{
    int n, i, a;
    scanf ( "%d", &n );
    for ( i = 0 ; i < n ; i++ )
    {
        scanf ( "%d", &a );
        if ( a < 2 )
            printf ( "0\n" );
        else
            printf ( "%d\n", a - 2 );
    }
    return 0;
}
