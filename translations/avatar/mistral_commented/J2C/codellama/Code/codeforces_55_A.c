
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n , i = 1 , k = 0 , p = 1 ;
    int a [ 1000 ] ;
    int flag = true ;

    scanf ( "%d" , &n ) ;

    i = 1 ;
    k = 0 ;
    p = 1 ;
    flag = true ;

    while ( k <= n ) {
        i += k ;

        if ( i >= n ) {
            while ( i >= n ) i = i - n ;
        }

        ++ a [ i ] ;
        ++ k ;
    }

    for ( i=0 ; i<n ; ++i ) {
        if ( a [ i ] == 0 ) {
            flag = false ;
            break ;
        }
    }

    if ( flag ) printf ( "YES\n" ) ;
    else printf ( "NO\n" ) ;

    return 0 ;
}

