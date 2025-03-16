#include <stdio.h>
int main ( )
{
    int n, i;
    scanf ( "%d", & n ) ;
    for ( i = n ; i > 0 ; i -- )
    {
        if ( n % i == 0 )
        {
            n = i ;
            printf ( "%d ", i ) ;
        }
    }
    printf ( "