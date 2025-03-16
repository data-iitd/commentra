
#include <stdio.h>
#include <string.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    char cake [ n ] [ n ];
    int happiness = 0;
    int chocCount = 0;
    int nfat = 1;
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%s", cake [ i ] );
        for ( int j = 0 ; j < n ; j ++ ) {
            if ( cake [ i ] [ j ] == 'C' ) {
                chocCount += 1;
            }
        }
        if ( chocCount > 1 ) {
            for ( int i = chocCount ; i > chocCount - 2 ; i -- ) {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }
    int posCount = 0;
    for ( int j = 0 ; j < n ; j ++ ) {
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( cake [ i ] [ j ] == 'C' ) {
                chocCount += 1;
            }
        }
        if ( chocCount > 1 ) {
            for ( int i = chocCount ; i > chocCount - 2 ; i -- ) {
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
