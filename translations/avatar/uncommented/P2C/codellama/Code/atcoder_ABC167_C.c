#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 1000000

int main ( ) {
    int n , m , x , i , j , k , ca , ans = 0;
    scanf ( "%d %d %d" , &n , &m , &x );
    int c [ n ] [ m + 1 ];
    for ( i = 0 ; i < n ; i++ ) {
        for ( j = 0 ; j < m + 1 ; j++ ) {
            scanf ( "%d" , &c [ i ] [ j ] );
        }
    }
    int pre [ n ];
    for ( i = 0 ; i < n ; i++ ) {
        pre [ i ] = i;
    }
    int l [ MAX ] [ MAX ];
    int rem [ MAX ];
    int len_l = 0;
    for ( i = 0 ; i < n ; i++ ) {
        for ( j = 0 ; j < n - i ; j++ ) {
            l [ len_l ] [ j ] = pre [ j ];
        }
        len_l++;
    }
    for ( i = 1 ; i < m + 1 ; i++ ) {
        for ( j = 0 ; j < len_l ; j++ ) {
            ca = 0;
            for ( k = 0 ; k < n - len_l + j + 1 ; k++ ) {
                ca += c [ l [ j ] [ k ] ] [ i ];
            }
            if ( ca < x ) {
                rem [ j ] = 1;
            }
            else {
                rem [ j ] = 0;
            }
        }
        for ( j = 0 ; j < len_l ; j++ ) {
            if ( rem [ j ] == 1 ) {
                for ( k = j ; k < len_l - 1 ; k++ ) {
                    l [ k ] [ 0 ] = l [ k + 1 ] [ 0 ];
                    l [ k ] [ 1 ] = l [ k + 1 ] [ 1 ];
                }
                len_l--;
            }
        }
        if ( len_l == 0 ) {
            printf ( "-1\n" );
            break;
        }
    }
    if ( len_l != 0 ) {
        for ( i = 0 ; i < len_l ; i++ ) {
            ca = 0;
            for ( j = 0 ; j < n - len_l + i + 1 ; j++ ) {
                ca += c [ l [ i ] [ j ] ] [ 0 ];
            }
            if ( ans == 0 ) {
                ans = ca;
            }
            else {
                ans = min ( ans , ca );
            }
        }
        printf ( "%d\n" , ans );
    }
    return 0;
}

