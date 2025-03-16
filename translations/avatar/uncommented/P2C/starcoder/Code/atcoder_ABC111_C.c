#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    int *x = ( int * ) malloc ( n * sizeof ( int ) );
    for ( int i = 0 ; i < n ; i++ ) {
        scanf ( "%d", &x [ i ] );
    }
    int *a = ( int * ) malloc ( n / 2 * sizeof ( int ) );
    int *b = ( int * ) malloc ( n / 2 * sizeof ( int ) );
    for ( int i = 0 ; i < n ; i++ ) {
        if ( i % 2 == 0 ) {
            a [ i / 2 ] = x [ i ];
        } else {
            b [ i / 2 ] = x [ i ];
        }
    }
    int *cnta = ( int * ) malloc ( 100002 * sizeof ( int ) );
    int *cntb = ( int * ) malloc ( 100002 * sizeof ( int ) );
    for ( int i = 0 ; i < 100002 ; i++ ) {
        cnta [ i ] = 0;
        cntb [ i ] = 0;
    }
    for ( int i = 0 ; i < n / 2 ; i++ ) {
        cnta [ a [ i ] ]++;
    }
    for ( int i = 0 ; i < n / 2 ; i++ ) {
        if ( cnta [ a [ i ] ] > cnta [ vala ] ) {
            vala = a [ i ];
        }
    }
    for ( int i = 0 ; i < n / 2 ; i++ ) {
        if ( cnta [ a [ i ] ] > cnta [ vala1 ] && a [ i ]!= vala ) {
            vala1 = a [ i ];
        }
    }
    for ( int i = 0 ; i < n / 2 ; i++ ) {
        cntb [ b [ i ] ]++;
    }
    for ( int i = 0 ; i < n / 2 ; i++ ) {
        if ( cntb [ b [ i ] ] > cntb [ valb ] ) {
            valb = b [ i ];
        }
    }
    for ( int i = 0 ; i < n / 2 ; i++ ) {
        if ( cntb [ b [ i ] ] > cntb [ valb1 ] && b [ i ]!= valb ) {
            valb1 = b [ i ];
        }
    }
    if ( valb!= vala ) {
        int res = 0;
        for ( int i = 0 ; i < n / 2 ; i++ ) {
            if ( a [ i ]!= vala ) {
                res++;
            }
        }
        for ( int i = 0 ; i < n / 2 ; i++ ) {
            if ( b [ i ]!= valb ) {
                res++;
            }
        }
        printf ( "%d\n", res );
    } else {
        int resa = 0;
        int resb = 0;
        int resa1 = 0;
        int resb1 = 0;
        for ( int i = 0 ; i < n / 2 ; i++ ) {
            if ( a [ i ]!= vala ) {
                resa++;
            }
            if ( a [ i ]!= vala1 ) {
                resa1++;
            }
        }
        for ( int i = 0 ; i < n / 2 ; i++ ) {
            if ( b [ i ]!= valb ) {
                resb++;
            }
            if ( b [ i ]!= valb1 ) {
                resb1++;
            }
        }
        printf ( "%d\n", min ( resa + resb1, resa1 + resb ) );
    }
    free ( x );
    free ( a );
    free ( b );
    free ( cnta );
    free ( cntb );
    return 0;
}
