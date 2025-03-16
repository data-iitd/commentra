#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main ( ) {
    int N, i, min, sum;
    scanf ( "%d", &N );
    int A[5];
    for ( i = 0; i < 5; i++ ) {
        scanf ( "%d", &A[i] );
    }
    min = A[0];
    for ( i = 1; i < 5; i++ ) {
        if ( A[i] < min ) {
            min = A[i];
        }
    }
    sum = ceil ( N / min ) + 4;
    printf ( "%d", sum );
    return 0;
}
