#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int next_int ( ) {
    int x;
    scanf ( "%d" , &x );
    return x;
}
int * next_ints ( ) {
    int * x = ( int * ) malloc ( sizeof ( int ) * 100 );
    int i;
    for ( i = 0 ; i < 100 ; i++ ) {
        scanf ( "%d" , &x[i] );
    }
    return x;
}
int main ( ) {
    int n = next_int ( );
    int t = 0;
    int i;
    for ( i = 0 ; i < n ; i++ ) {
        if ( i + 1 & 1 ) {
            t += 1;
        }
    }
    printf ( "%f\n" , ( float ) t / n );
    return 0;
}
