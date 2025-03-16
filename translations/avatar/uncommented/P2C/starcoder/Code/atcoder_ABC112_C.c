#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    int *ls_xyh = ( int * ) malloc ( n * 3 * sizeof ( int ) );
    for ( int i = 0 ; i < n ; i++ ) {
        scanf ( "%d%d%d", &ls_xyh [ 3 * i ], &ls_xyh [ 3 * i + 1 ], &ls_xyh [ 3 * i + 2 ] );
    }
    int x0 = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( ls_xyh [ 3 * i + 2 ] > 0 ) {
            x0 = ls_xyh [ 3 * i ];
            break;
        }
    }
    int *cands = ( int * ) malloc ( 101 * 101 * 3 * sizeof ( int ) );
    for ( int cx = 0 ; cx < 101 ; cx++ ) {
        for ( int cy = 0 ; cy < 101 ; cy++ ) {
            int ch = ls_xyh [ 3 * 0 ] + abs ( cx - x0 ) + abs ( cy - ls_xyh [ 3 * 0 + 1 ] );
            for ( int i = 1 ; i < n ; i++ ) {
                ch = max ( ch - abs ( cx - ls_xyh [ 3 * i ] ) - abs ( cy - ls_xyh [ 3 * i + 1 ] ), 0 );
            }
            cands [ 3 * ( cx * 101 + cy ) ] = cx;
            cands [ 3 * ( cx * 101 + cy ) + 1 ] = cy;
            cands [ 3 * ( cx * 101 + cy ) + 2 ] = ch;
        }
    }
    int *max_cands = cands;
    for ( int i = 1 ; i < n ; i++ ) {
        for ( int j = 0 ; j < 101 * 101 ; j++ ) {
            if ( cands [ 3 * j + 2 ] > max_cands [ 3 * j + 2 ] ) {
                max_cands [ 3 * j ] = cands [ 3 * j ];
                max_cands [ 3 * j + 1 ] = cands [ 3 * j + 1 ];
                max_cands [ 3 * j + 2 ] = cands [ 3 * j + 2 ];
            }
        }
    }
    int *max_cand = max_cands;
    for ( int i = 1 ; i < n ; i++ ) {
        if ( max_cand [ 2 ] > max_cands [ 3 * i + 2 ] ) {
            max_cand [ 0 ] = max_cands [ 3 * i ];
            max_cand [ 1 ] = max_cands [ 3 * i + 1 ];
            max_cand [ 2 ] = max_cands [ 3 * i + 2 ];
        }
    }
    printf ( "%d %d %d", max_cand [ 0 ], max_cand [ 1 ], max_cand [ 2 ] );
    return 0;
}
