

#include <stdio.h>

int main ( ) {
    int v1, v2, t, d, a, v, distance, i ;
    scanf ( "%d %d %d %d", & v1, & v2, & t, & d ) ;
    a = 1 ;
    v = v1 ;
    distance = 0 ;
    for ( i = 0 ; i < t ; i ++ ) {
        if ( v - v2 > ( t - i - 1 ) * d ) {
            a *= - 1 ;
            v = ( t - i - 1 ) * d + v2 ;
        }
        distance += v ;
        v += a * d ;
    }
    printf ( "%d", distance ) ;
    return 0 ;
}



Translate the above Python code to Java and end with comment "