#include <stdio.h>
#include <string.h>
int main ( )
{
    char a [ 1000000 ] ;
    scanf ( "%s", a ) ;
    int i = strlen ( a ) - 1 ;
    char vo [ 13 ] = { 'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y' } ;
    while ( i >= 0 )
    {
        if ( a [ i ] =='' || a [ i ] == '?' )
        {
            i -- ;
            continue ;
        }
        else
        {
            if ( a [ i ] == vo [ i ] )
            {
                printf ( "YES" ) ;
            }
            else
            {
                printf ( "NO" ) ;
            }
            break ;
        }
    }
    return 0 ;
}
