
#include <stdio.h>
#include <limits.h>

int main ( void ) {
    int N, L, R, QL, QR;
    scanf ( "%d %d %d %d %d", &N, &L, &R, &QL, &QR );

    int W [ N ] ;
    int sum [ N + 1 ] ;

    for ( int n = 0 ; n < N ; n ++ ) {
        scanf ( "%d", &W [ n ] ) ;
        sum [ n + 1 ] = sum [ n ] + W [ n ] ;
    }

    long min = LONG_MAX ;

    for ( int firstR = 0 ; firstR <= N ; firstR ++ ) {
        int lCount = firstR ;
        int rCount = N - lCount ;

        long cand = ( long ) sum [ lCount ] * L + ( long ) ( sum [ N ] - sum [ lCount ] ) * R ;

        int llCount = lCount - rCount - 1 ;
        int rrCount = rCount - lCount - 1 ;

        cand += ( long ) llCount * QL ;
        cand += ( long ) rrCount * QR ;

        min = cand < min? cand : min ;
    }

    printf ( "%ld\n", min ) ;

    return 0 ;
}
