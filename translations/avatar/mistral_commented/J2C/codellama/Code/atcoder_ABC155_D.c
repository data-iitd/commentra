
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ll long long
#define mod (ll) 1e9 + 7

#define DX { - 1 , 0 , 1 , 0 }
#define DY { 0 , - 1 , 0 , 1 }

int n ;
ll k ;
ll * a ;

int check ( ll x ) {
    ll tot = 0 ;

    for ( int i = 0 ; i < n ; i ++ ) {
        ll now = a [ i ] ;
        int l = 0 , r = n ;

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

        if ( ( ll ) a [ i ] * a [ i ] < x ) tot -- ;

        if ( tot / 2 < k ) return 1 ;
    }

    return 0 ;
}

int main ( ) {
    scanf ( "%d%lld" , & n , & k ) ;
    a = ( ll * ) malloc ( n * sizeof ( ll ) ) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%lld" , & a [ i ] ) ;
    }

    qsort ( a , n , sizeof ( ll ) , ( int ( * ) ( const void * , const void * ) ) & compare ) ;

    ll INF = ( ll ) ( 1e18 ) + 1 ;
    ll l = - INF ;
    ll r = INF ;

    while ( l + 1 < r ) {
        ll c = ( l + r ) / 2 ;
        if ( check ( c ) ) l = c ;
        else r = c ;
    }

    printf ( "%lld\n" , l ) ;

    return 0 ;
}

int compare ( const void * a , const void * b ) {
    return ( * ( ll * ) a - * ( ll * ) b ) ;
}

