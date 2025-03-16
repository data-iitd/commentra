#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define TIME 0
#define VAL 1
#define N 100000
#define T 100000

int main ( ) {
    int n, t;
    scanf ( "%d %d", &n, &t );
    int time_value [ N + 1 ] [ 2 ];
    time_value [ 0 ] [ 0 ] = - 1;
    time_value [ 0 ] [ 1 ] = - 1;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d", &time_value [ i ] [ 0 ], &time_value [ i ] [ 1 ] );
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = i ; j >= 1 ; j-- ) {
            if ( time_value [ j ] [ 0 ] > time_value [ j - 1 ] [ 0 ] ) {
                int temp = time_value [ j - 1 ] [ 0 ];
                time_value [ j - 1 ] [ 0 ] = time_value [ j ] [ 0 ];
                time_value [ j ] [ 0 ] = temp;
                temp = time_value [ j - 1 ] [ 1 ];
                time_value [ j - 1 ] [ 1 ] = time_value [ j ] [ 1 ];
                time_value [ j ] [ 1 ] = temp;
            }
        }
    }
    int dp [ N + 1 ] [ T + 1 ];
    for ( int i = 0 ; i <= n ; i++ ) {
        for ( int j = 0 ; j <= t ; j++ ) {
            dp [ i ] [ j ] = - 1;
        }
    }
    for ( int i = 0 ; i <= t ; i++ ) {
        dp [ 0 ] [ i ] = 0;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        dp [ i ] [ 0 ] = 0;
        for ( int j = 1 ; j <= t ; j++ ) {
            if ( time_value [ i ] [ 0 ] > j ) {
                dp [ i ] [ j ] = dp [ i - 1 ] [ j ];
            } else {
                dp [ i ] [ j ] = max ( dp [ i - 1 ] [ j ], time_value [ i ] [ 1 ] + dp [ i - 1 ] [ j - time_value [ i ] [ 0 ] ] );
            }
        }
    }
    int val_acum = time_value [ n ] [ 1 ];
    int t = t - 1;
    int max_val = val_acum + dp [ n - 1 ] [ t ];
    for ( int i = n - 1 ; i >= 1 ; i-- ) {
        val_acum += time_value [ i ] [ 1 ];
        t -= time_value [ i + 1 ] [ 0 ];
        if ( t < 0 ) {
            break;
        } else {
            max_val = max ( max_val, val_acum + dp [ i - 1 ] [ t ] );
        }
    }
    printf ( "%d\n", max_val );
    return 0;
}
