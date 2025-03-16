#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX_N 100000
int main ( ) {
    int N;
    scanf ( "%d", &N );
    int P [ MAX_N ];
    for ( int i = 0 ; i < N ; i ++ ) {
        scanf ( "%d", &P [ i ] );
    }
    int a [ MAX_N + 1 ];
    for ( int i = 0 ; i <= N ; i ++ ) {
        a [ i ] = -1;
    }
    for ( int i = 0 ; i < N ; i ++ ) {
        if ( a [ P [ i ] ] == -1 ) {
            a [ P [ i ] ] = i;
        }
    }
    int tmp = 1;
    int max_len = 1;
    for ( int i = 0 ; i < N ; i ++ ) {
        if ( a [ i ]!= -1 && a [ i + 1 ]!= -1 ) {
            tmp += 1;
            max_len = max ( max_len, tmp );
        } else {
            tmp = 1;
        }
    }
    int ans = N - max_len;
    printf ( "%d", ans );
    return 0;
}
