#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX_PIECES 100000
#define MAX_STR_LEN 100000
int main ( ) {
    int pieces [ MAX_PIECES ] [ 2 ];
    int n, i, pScore, sScore, pMaxScore, sMaxScore;
    scanf ( "%d", &n );
    for ( i = 0 ; i < n ; i++ ) {
        scanf ( "%d", &pieces [ i ] [ 0 ] );
        scanf ( "%s", pieces [ i ] [ 1 ] );
    }
    pScore = sScore = pMaxScore = sMaxScore = 0;
    for ( i = 0 ; i < n ; i++ ) {
        if ( pieces [ i ] [ 1 ] [ 0 ] == 'B' ) {
            pScore += pieces [ i ] [ 0 ];
            if ( pScore > pMaxScore ) {
                pMaxScore = pScore;
            }
        } else {
            pScore -= pieces [ i ] [ 0 ];
        }
    }
    for ( i = n - 1 ; i >= 0 ; i-- ) {
        if ( pieces [ i ] [ 1 ] [ 0 ] == 'A' ) {
            sScore += pieces [ i ] [ 0 ];
            if ( sScore > sMaxScore ) {
                sMaxScore = sScore;
            }
        } else {
            sScore -= pieces [ i ] [ 0 ];
        }
    }
    if ( pMaxScore > sMaxScore ) {
        printf ( "%d", pMaxScore );
    } else {
        printf ( "%d", sMaxScore );
    }
    return 0;
}
