#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int N;
    scanf ( "%d", & N ) ;
    int A [ N ] ;
    for ( int i = 0 ; i < N ; i ++ ) {
        scanf ( "%d", & A [ i ] ) ;
    }
    int mn, mx ;
    mn = N + 1 ;
    mx = - 1 ;
    for ( int i = 0 ; i < N ; i ++ ) {
        if ( i + 1!= A [ i ] ) {
            mn = min ( mn, i ) ;
            mx = max ( mx, i ) ;
        }
    }
    if ( mx == - 1 ) {
        printf ( "0 0" ) ;
    } else {
        int A [ N ] ;
        for ( int i = 0 ; i < mn ; i ++ ) {
            A [ i ] = A [ i ] ;
        }
        for ( int i = mn ; i < mx ; i ++ ) {
            A [ i ] = A [ mx - i + mn ] ;
        }
        for ( int i = mx + 1 ; i < N ; i ++ ) {
            A [ i ] = A [ i - ( mx - mn + 1 ) ] ;
        }
        if ( 1 ) {
            int ok = 1 ;
            for ( int i = 0 ; i < N - 1 ; i ++ ) {
                if ( A [ i ] > A [ i + 1 ] ) {
                    ok = 0 ;
                    break ;
                }
            }
            if ( ok ) {
                printf ( "%d %d", mn + 1, mx + 1 ) ;
            } else {
                printf ( "0 0" ) ;
            }
        } else {
            printf ( "0 0" ) ;
        }
    }
    return 0 ;
}
