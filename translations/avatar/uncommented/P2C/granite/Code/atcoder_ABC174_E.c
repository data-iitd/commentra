
#include <stdio.h>
#include <stdlib.h>

int check ( int *lis, int k, int mid, int n ) {
    int i;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( lis [ i ] % mid == 0 ) {
            k += 1;
        }
        k -= ( lis [ i ] / mid );
    }
    return k >= 0;
}

int main ( ) {
    int n, k, i;
    scanf ( "%d %d", &n, &k );
    int *lis = ( int * ) malloc ( sizeof ( int ) * n );
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d", &lis [ i ] );
    }
    int a = 1, b = * ( max_element ( lis, lis + n ) ), ans = b;
    while ( a <= b ) {
        int mid = ( a + b ) / 2;
        if ( check ( lis, k, mid, n ) ) {
            ans = mid;
            b = mid - 1;
        } else {
            a = mid + 1;
        }
    }
    printf ( "%d", ans );
    return 0;
}
