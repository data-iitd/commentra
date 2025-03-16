
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    int x [ n ];
    for ( int i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", &x [ i ] );
    }
    int a [ n / 2 ];
    int b [ n / 2 ];
    int cnta [ 100002 + 1 ] = { 0 };
    int cntb [ 100002 + 1 ] = { 0 };
    for ( int i = 0 ; i < n / 2 ; i ++ ) {
        a [ i ] = x [ 2 * i ];
        b [ i ] = x [ 2 * i + 1 ];
        cnta [ a [ i ] ] += 1;
        cntb [ b [ i ] ] += 1;
    }
    int vala = 0;
    int maxCnta = 0;
    for ( int i = 0 ; i < n / 2 ; i ++ ) {
        if ( maxCnta < cnta [ a [ i ] ] ) {
            vala = a [ i ];
            maxCnta = cnta [ a [ i ] ];
        }
    }
    int valb = 0;
    int maxCntb = 0;
    for ( int i = 0 ; i < n / 2 ; i ++ ) {
        if ( maxCntb < cntb [ b [ i ] ] ) {
            valb = b [ i ];
            maxCntb = cntb [ b [ i ] ];
        }
    }
    if ( vala!= valb ) {
        int res = 0;
        for ( int i = 0 ; i < n / 2 ; i ++ ) {
            if ( a [ i ]!= vala ) {
                res += 1;
            }
            if ( b [ i ]!= valb ) {
                res += 1;
            }
        }
        printf ( "%d\n", res );
    } else {
        int resa = 0;
        int resb = 0;
        for ( int i = 0 ; i < n / 2 ; i ++ ) {
            if ( a [ i ]!= vala ) {
                resa += 1;
            }
            if ( a [ i ]!= valb ) {
                resa += 1;
            }
            if ( b [ i ]!= vala ) {
                resb += 1;
            }
            if ( b [ i ]!= valb ) {
                resb += 1;
            }
        }
        printf ( "%d\n", ( resa < resb )? resa : resb );
    }
    return 0;
}
