
#include <stdio.h>
#include <string.h>

int main ( ) {
    char s [ 100001 ] ;
    scanf ( "%s", s ) ;
    int n ;
    scanf ( "%d", & n ) ;
    int ans = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        char x [ 3 ] ;
        scanf ( "%s", x ) ;
        int a = 0, b = 0 ;
        for ( int j = 0 ; s [ j ] ; j ++ ) {
            if ( s [ j ] == x [ 0 ] ) {
                a ++ ;
            } else if ( s [ j ] == x [ 1 ] ) {
                b ++ ;
            } else {
                ans = ans + ( ( a < b )? a : b ) ;
                a = 0 ;
                b = 0 ;
            }
        }
        ans = ans + ( ( a < b )? a : b ) ;
    }
    printf ( "%d\n", ans ) ;
    return 0 ;
}
//END-OF-CODE