
#include <stdio.h>

int G ( int a, int b ) {
    while ( a % b!= 0 ) {
        a = b;
        b = a % b;
    }
    return b;
}

int L ( int a, int b ) {
    return a * b / G ( a, b );
}

int main ( ) {
    int x, y, a, b;
    scanf ( "%d %d %d %d", & x, & y, & a, & b );
    int lcm = L ( x, y );
    printf ( "%d\n", b / lcm - ( a - 1 ) / lcm );
    return 0;
}

