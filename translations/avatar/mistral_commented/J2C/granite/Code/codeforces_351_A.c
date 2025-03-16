

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n ;
    scanf ( "%d", &n ) ;

    double arr [ 2 * n ] ;
    int non_int = 0 ;
    double sum_before = 0, sum = 0 ;

    for ( int i = 0 ; i < 2 * n ; i ++ ) {
        double num ;
        scanf ( "%lf", &num ) ;
        sum_before += num ;
        if ( num!= floor ( num ) ) non_int ++ ;
        sum += floor ( num ) ;
        arr [ i ] = num ;
    }

    double max_sum = fmin ( n, non_int ) + sum ;
    double min_sum = fmax ( 0, non_int - n ) + sum ;

    double ans ;
    if ( min_sum > sum_before ) ans = ( min_sum - sum_before ) ;
    else if ( max_sum < sum_before ) ans = ( sum_before - max_sum ) ;
    else {
        double x = sum_before - floor ( sum_before ) ;
        ans = fmin ( 1 - x, x ) ;
    }

    printf ( "%.3f", ans ) ;

    return 0 ;
}
