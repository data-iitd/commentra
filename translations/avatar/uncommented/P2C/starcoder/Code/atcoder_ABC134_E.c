#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main ( ) {
    int N;
    scanf ( "%d", &N );
    int *arr = ( int * ) malloc ( N * sizeof ( int ) );
    for ( int i = 0; i < N; i++ ) {
        scanf ( "%d", &arr [ i ] );
    }
    int *ans = ( int * ) malloc ( N * sizeof ( int ) );
    int *ptr = ans;
    for ( int i = 0; i < N; i++ ) {
        int *ptr2 = ptr;
        int *ptr3 = arr + i;
        while ( *ptr3!= *ptr2 ) {
            ptr2++;
        }
        if ( *ptr3 == *ptr2 ) {
            ptr2++;
        }
        ptr = ptr2;
    }
    printf ( "%d\n", ptr - ans );
    return 0;
}
