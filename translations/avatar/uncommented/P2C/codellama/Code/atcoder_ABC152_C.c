#include <stdio.h>
#include <stdlib.h>
int main ( ) {
    int N;
    scanf ( "%d" , &N );
    int n [ N ];
    for ( int i = 0 ; i < N ; i++ ) {
        scanf ( "%d" , &n [ i ] );
    }
    int a = 1;
    int pos = 0;
    for ( int i = 1 ; i < N ; i++ ) {
        if ( n [ pos ] > n [ i ] ) {
            a += 1;
            pos = i;
        }
    }
    printf ( "%d" , a );
    return 0;
}
