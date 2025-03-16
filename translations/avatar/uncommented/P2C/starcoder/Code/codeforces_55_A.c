#include <stdio.h>
int main ( )
{
    int n;
    scanf ( "%d", &n );
    while ( n % 2 == 0 )
        n /= 2;
    if ( n == 1 )
        printf ( "YES" );
    else
        printf ( "NO" );
    return 0;
}
