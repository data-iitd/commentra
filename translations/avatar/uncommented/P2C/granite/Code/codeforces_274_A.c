
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int num, k;
    scanf ( "%d %d", &num, &k );
    int *arr = ( int * ) malloc ( sizeof ( int ) * num );
    for ( int i = 0; i < num; i ++ ) {
        scanf ( "%d", &arr [ i ] );
    }
    int *different = ( int * ) malloc ( sizeof ( int ) * num );
    int temp = 0;
    for ( int i = 0; i < num; i ++ ) {
        if ( arr [ i ] % k!= 0 || different [ arr [ i ] / k ]!= 1 ) {
            different [ arr [ i ] ] = 1;
            temp = temp > arr [ i ]? temp : arr [ i ];
        }
    }
    printf ( "%d\n", temp );
    free ( arr );
    free ( different );
    return 0;
}

