
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define mod ( int ) 1e9 + 7

#define DX ( int [ ] ) { - 1, 0, 1, 0 }
#define DY ( int [ ] ) { 0, - 1, 0, 1 }

int n ;
long k ;
long a [ 1000001 ] ;

int main ( ) {
    scanf ( "%d", & n ) ;
    scanf ( "%ld", & k ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        scanf ( "%ld", & a [ i ] ) ;
    }
    qsort ( a, n, sizeof ( long ), cmp ) ;
    long INF = ( long ) ( 1e18 ) + 1 ;
    long l = - INF ;
    long r = INF ;
    while ( l + 1 < r ) {
        long c = ( l + r ) / 2 ;
        if ( check ( c ) ) l = c ;
        else r = c ;
    }
    printf ( "%ld\n", l ) ;
    return 0 ;
}

int cmp ( const void * a, const void * b ) {
    return ( *( long * ) a ) - ( *( long * ) b ) ;
}

bool check ( long x ) {
    long tot = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        long now = a [ i ] ;
        int l = 0, r = n ;
        if ( now >= 0 ) {
            while ( l < r ) {
                int c = ( l + r ) / 2 ;
                if ( now * a [ c ] < x ) l = c + 1 ;
                else r = c ;
            }
            tot += l ;
        } else {
            while ( l < r ) {
                int c = ( l + r ) / 2 ;
                if ( now * a [ c ] >= x ) l = c + 1 ;
                else r = c ;
            }
            tot += ( n - l ) ;
        }
        if ( ( long ) a [ i ] * a [ i ] < x ) tot -- ;
        if ( tot / 2 < k ) return true ;
    }
    return false ;
}

