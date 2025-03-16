#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX_N 1000000
int main ( ) {
    int n;
    scanf ( "%d", &n );
    int sequence [ MAX_N ];
    for ( int i = 0 ; i < n ; i++ )
        scanf ( "%d", &sequence [ i ] );
    int storage [ MAX_N ] = { 0 };
    int FXs [ MAX_N ] = { 0 };
    for ( int i = 0 ; i < n ; i++ ) {
        int y = f ( sequence [ i ] );
        if ( storage [ y ] == 0 ) {
            storage [ y ] = 1;
            FXs [ y ] = 1;
        }
        else {
            storage [ y ]++;
            FXs [ y ]++;
        }
    }
    int ans = 0;
    for ( int i = 0 ; i < n ; i++ )
        ans += storage [ i ] * storage [ i ];
    for ( int i = 0 ; i < n ; i++ )
        ans -= storage [ i ];
    printf ( "%d", ans / 2 );
    return 0;
}
int f ( int n ) {
    int y = 1;
    while ( n!= 1 ) {
        if ( n % 2 )
            y++;
        n /= 2;
    }
    return y;
}
