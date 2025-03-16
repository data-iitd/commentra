#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 368
int main ( ) {
    int m [ N ] = { 0 };
    int f [ N ] = { 0 };
    int i , a , b , c , x , a , b;
    scanf ( "%d" , &i );
    for ( int i = 0 ; i < i ; i ++ ) {
        scanf ( "%s" , &x );
        scanf ( "%d" , &a );
        scanf ( "%d" , &b );
        b = b + 1;
        if ( x == 'M' ) {
            m [ a ] += 2;
            m [ b ] -= 2;
        } else {
            f [ a ] += 2;
            f [ b ] -= 2;
        }
    }
    a = 0;
    b = 0;
    c = 0;
    for ( int i = 0 ; i < N ; i ++ ) {
        a += m [ i ];
        b += f [ i ];
        if ( a < b ) {
            c = a;
        } else {
            c = b;
        }
    }
    printf ( "%d" , c );
    return 0;
}
