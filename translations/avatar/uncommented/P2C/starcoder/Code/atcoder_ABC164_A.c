#include <stdio.h>
int main ( ) {
    int S, W ;
    scanf ( "%d %d", &S, &W ) ;
    printf ( "unsafe" ) ;
    if ( S <= W )
        printf ( "safe" ) ;
    printf ( "