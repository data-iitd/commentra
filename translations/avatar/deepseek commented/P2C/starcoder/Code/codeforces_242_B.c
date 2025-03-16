
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main ( ) {
    int n, id = 0, l, r ;
    scanf ( "%d", &n ) ;
    scanf ( "%d %d", &l, &r ) ;
    for ( int i = 1 ; i < n ; i ++ ) {
        int li, ri ;
        scanf ( "%d %d", &li, &ri ) ;
        if ( li <= l && r <= ri ) id = i ;
        else if ( li < l || r < ri ) id = n ;
        l = li < l? li : l ;
        r = ri > r? ri : r ;
    }
    printf ( "%d\n", - 1 if id == n else id + 1 ) ;
    return 0 ;
}

