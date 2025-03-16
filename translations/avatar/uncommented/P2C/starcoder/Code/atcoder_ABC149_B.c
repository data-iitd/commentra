#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int cookies [ ] = { 0, 0, 0 };
    int leftOver = cookies [ 0 ] - cookies [ 2 ];
    int takahashi = ( leftOver > 0 )? leftOver : 0;
    printf ( "%d %d\n", takahashi, ( cookies [ 1 ] > 0 )? cookies [ 1 ] : ( cookies [ 1 ] - abs ( leftOver ) ) );
    return 0;
}
