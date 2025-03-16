#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define N 1000000
#define K 1000000
char S [ N + 10 ];
char U [ N + 10 ];
int main ( ) {
    int N, K, i, j, p, minindex, count ;
    scanf ( "%d%d", &N, &K ) ;
    scanf ( "%s", S ) ;
    bool aaaa = false ;
    if ( K >= 15 ) {
        aaaa = true ;
    }
    else if ( 2 * pow ( 2, K ) >= N ) {
        aaaa = true ;
    }
    if ( aaaa ) {
        printf ( "%c", S [ 0 ] ) ;
        for ( i = 1 ; i < N ; i ++ ) {
            printf ( "%c", S [ i ] ) ;
        }
        printf ( "\n" ) ;
        return 0 ;
    }
    strcpy ( U, S ) ;
    for ( i = 0 ; i < N ; i ++ ) {
        U [ i + N ] = S [ i ] ;
    }
    char c = S [ 0 ] ;
    p = strcspn ( U, c ) ;
    minindex = p ;
    p += 1 ;
    while ( p <= N ) {
        if ( U [ p ] == c ) {
            if ( check_normal_dict ( U, minindex, p ) ) {
                minindex = p ;
            }
        }
        p += 1 ;
    }
    char *last_dict = U + minindex ;
    if ( K == 1 ) {
        printf ( "%s\n", last_dict ) ;
    }
    else {
        count = 0 ;
        for ( i = 0 ; i < N ; i ++ ) {
            if ( last_dict [ i ] == last_dict [ 0 ] ) {
                count ++ ;
            }
            else {
                break ;
            }
        }
        if ( count * ( 2 * pow ( 2, K - 1 ) ) >= N ) {
            printf ( "%c", last_dict [ 0 ] ) ;
            for ( i = 1 ; i < N ; i ++ ) {
                printf ( "%c", last_dict [ i ] ) ;
            }
            printf ( "\n" ) ;
        }
        else {
            for ( i = 0 ; i < count * ( ( 2 * pow ( 2, K - 1 ) ) - 1 ) ; i ++ ) {
                printf ( "%c", last_dict [ 0 ] ) ;
            }
            for ( i = count * ( ( 2 * pow ( 2, K - 1 ) ) - 1 ) ; i < N ; i ++ ) {
                printf ( "%c", last_dict [ i ] ) ;
            }
            printf ( "\n" ) ;
        }
    }
    return 0 ;
}
bool check_normal_dict ( char *u, int pointer1, int pointer2 ) {
    for ( int i = 0 ; i < N ; i ++ ) {
        if ( u [ pointer1 + i ] > u [ pointer2 + i ] ) {
            return true ;
        }
        else if ( u [ pointer1 + i ] < u [ pointer2 + i ] ) {
            return false ;
        }
    }
    return false ;
}
