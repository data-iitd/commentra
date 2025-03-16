#include <stdio.h>
int main ( )
{
    int X, i, j;
    bool prime [ 100010 ] ;
    for ( i = 0 ; i < 100010 ; i ++ )
        prime [ i ] = true ;
    prime [ 0 ] = false ;
    prime [ 1 ] = false ;
    for ( i = 4 ; i < 100010 ; i += 2 )
        prime [ i ] = false ;
    for ( i = 3 ; i * i <= 100008 ; i += 2 )
        if ( prime [ i ] )
            for ( j = i + i ; j < 100008 ; j += i )
                prime [ j ] = false ;
    scanf ( "%d", &X ) ;
    for ( i = X ; i < 100008 ; i ++ )
        if ( prime [ i ] )
            break ;
    printf ( "%d\n", i ) ;
    return 0 ;
}
