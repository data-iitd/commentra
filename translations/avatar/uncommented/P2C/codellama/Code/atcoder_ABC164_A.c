#include <stdio.h>
int main ( ) {
    int S , W;
    scanf ( "%d %d" , &S , &W );
    if ( S <= W ) {
        printf ( "unsafe" );
    } else {
        printf ( "safe" );
    }
    return 0;
}
