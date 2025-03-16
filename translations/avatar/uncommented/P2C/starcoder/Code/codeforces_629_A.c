#include <stdio.h>
#include <stdlib.h>
int main ( ) {
    int n, i, j, chocCount, nfat, happiness;
    scanf ( "%d", &n );
    char cake [ n ] [ n ];
    happiness = 0;
    nfat = 1;
    for ( i = 0 ; i < n ; i++ ) {
        scanf ( "%s", cake [ i ] );
        chocCount = 0;
        for ( j = 0 ; j < n ; j++ ) {
            if ( cake [ i ] [ j ] == 'C' ) {
                chocCount++;
            }
        }
        if ( chocCount > 1 ) {
            for ( i = chocCount ; i > chocCount - 2 ; i-- ) {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
    }
    chocCount = 0;
    for ( j = 0 ; j < n ; j++ ) {
        for ( i = 0 ; i < n ; i++ ) {
            if ( cake [ i ] [ j ] == 'C' ) {
                chocCount++;
            }
        }
        if ( chocCount > 1 ) {
            for ( i = chocCount ; i > chocCount - 2 ; i-- ) {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }
    printf ( "%d", happiness );
    return 0;
}
