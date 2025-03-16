
#include <stdio.h>

int main ( ) {
    int k, n, w ;
    scanf ( "%d %d %d", & k, & n, & w ) ;
    if ( 1 <= k && w <= 1000 ) {
        int total = 0 ;
        for ( int i = 1 ; i <= w ; i ++ ) {
            total += i * k ;
        }
        if ( total > n ) {
            printf ( "%d", total - n ) ;
        } else {
            printf ( "%d", 0 ) ;
        }
    }
    return 0 ;
}
//END-OF-CODE