
#include <stdio.h>
#include <math.h>

int main ( ) {
    char s [ 2020 ];
    int l = 2019, m [ 2020 ] = { 1 }, a = 0, r = 0;
    fgets ( s, 2020, stdin );
    for ( int i = strlen ( s ) - 1 ; i >= 0 ; i -- ) {
        a = ( a + s [ i ] - '0' ) % l;
        r += m [ a ];
        m [ a ] ++;
    }
    printf ( "%d\n", r );
    return 0;
}
//END-OF-CODE