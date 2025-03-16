
#include <stdio.h>

int substract ( int a, int b ) {
    if ( a > b ) {
        int total = 0;
        while ( a > 0 && b > 0 ) {
            total += a / b;
            a = a % b;
            if ( a > 0 ) {
                total += b / a;
                b = b % a;
            }
        }
        return total;
    }
    if ( a < b ) {
        int total = 0;
        while ( a > 0 && b > 0 ) {
            total += b / a;
            b = b % a;
            if ( b > 0 ) {
                total += a / b;
                a = a % b;
            }
        }
        return total;
    }
    if ( a == b ) {
        return 1;
    }
}

int main ( ) {
    int n;
    scanf ( "%d", &n );
    int lst [ n ];
    for ( int i = 0 ; i < n ; i ++ ) {
        int a, b;
        scanf ( "%d %d", &a, &b );
        lst [ i ] = substract ( a, b );
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        printf ( "%d\n", lst [ i ] );
    }
    return 0;
}

