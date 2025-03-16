
#include <stdio.h>
#include <string.h>

int main ( ) {
    char a [ 1000 ] ;
    scanf ( "%s", a ) ;
    int len = strlen ( a ) ;
    char vo [ ] = { 'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y' } ;
    for ( int i = len - 1 ; i >= 0 ; i -- ) {
        if ( a [ i ] =='' || a [ i ] == '?' ) {
            continue ;
        } else {
            for ( int j = 0 ; j < 12 ; j ++ ) {
                if ( a [ i ] == vo [ j ] ) {
                    printf ( "YES\n" ) ;
                    return 0 ;
                }
            }
            printf ( "NO\n" ) ;
            return 0 ;
        }
    }
    return 0 ;
}

