#include <stdio.h>
#include <string.h>
int main ( ) {
    char s [ 1000000 ] , x [ 1000000 ] ;
    int n , i , j , a , b , ans = 0 ;
    scanf ( "%s" , s ) ;
    scanf ( "%d" , &n ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%s" , x ) ;
        a = b = 0 ;
        for ( j = 0 ; j < strlen ( s ) ; j ++ ) {
            if ( s [ j ] == x [ 0 ] ) {
                a ++ ;
            } else if ( s [ j ] == x [ 1 ] ) {
                b ++ ;
            } else {
                ans += min ( a , b ) ;
                a = b = 0 ;
            }
        }
        ans += min ( a , b ) ;
    }
    printf ( "%d" , ans ) ;
    return 0 ;
}
