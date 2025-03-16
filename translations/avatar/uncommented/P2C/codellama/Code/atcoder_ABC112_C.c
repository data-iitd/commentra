#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100000000
int solve ( int n , int ls_xyh [ 100000000 ] [ 3 ] ) {
    int x0 = 0;
    int i;
    for ( i = 0 ; i < n ; i++ ) {
        if ( ls_xyh [ i ] [ 2 ] > 0 ) {
            x0 = ls_xyh [ i ] [ 0 ];
            break;
        }
    }
    int cands [ 100000000 ] [ 3 ];
    int cx, cy, h0, h, ch, j, k;
    for ( cx = 0 ; cx < 101 ; cx++ ) {
        for ( cy = 0 ; cy < 101 ; cy++ ) {
            h0 = ls_xyh [ i ] [ 2 ];
            h = h0 + abs ( cx - x0 ) + abs ( cy - y0 );
            cands [ cx ] [ cy ] = h;
        }
    }
    for ( i = 0 ; i < n ; i++ ) {
        for ( cx = 0 ; cx < 101 ; cx++ ) {
            for ( cy = 0 ; cy < 101 ; cy++ ) {
                h = cands [ cx ] [ cy ];
                ch = h - abs ( cx - ls_xyh [ i ] [ 0 ] ) - abs ( cy - ls_xyh [ i ] [ 1 ] );
                if ( ch > 0 ) {
                    cands [ cx ] [ cy ] = ch;
                } else {
                    cands [ cx ] [ cy ] = 0;
                }
            }
        }
    }
    int xx, yy, hh;
    for ( cx = 0 ; cx < 101 ; cx++ ) {
        for ( cy = 0 ; cy < 101 ; cy++ ) {
            if ( cands [ cx ] [ cy ] > 0 ) {
                xx = cx;
                yy = cy;
                hh = cands [ cx ] [ cy ];
                break;
            }
        }
    }
    return 0;
}
int readQuestion ( ) {
    int n;
    int ls_xyh [ 100000000 ] [ 3 ];
    char * ws = malloc ( 100000000 * sizeof ( char ) );
    scanf ( "%d", &n );
    int i;
    for ( i = 0 ; i < n ; i++ ) {
        scanf ( "%d %d %d", &ls_xyh [ i ] [ 0 ], &ls_xyh [ i ] [ 1 ], &ls_xyh [ i ] [ 2 ] );
    }
    return 0;
}
int main ( ) {
    solve ( * readQuestion ( ) );
    return 0;
}
