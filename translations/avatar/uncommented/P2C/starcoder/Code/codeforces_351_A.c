#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    float arr[n];
    for ( int i = 0 ; i < n ; i++ )
        scanf ( "%f", &arr[i] );
    qsort ( arr, n, sizeof ( float ), cmp );
    int o = 2 * n - (int) ( log2 ( arr[n - 1] ) + 1 );
    float arr_sum = 0;
    for ( int i = 0 ; i < n ; i++ )
        arr_sum += arr[i];
    float res = 2e9;
    for ( int i = 0 ; i <= n ; i++ ) {
        if ( i + o >= n )
            res = fmin ( res, fabs ( i - arr_sum ) );
    }
    printf ( "%.3f", res );
    return 0;
}

int cmp ( const void *a, const void *b ) {
    return ( *(float *) a > *(float *) b ) - ( *(float *) a < *(float *) b );
}

