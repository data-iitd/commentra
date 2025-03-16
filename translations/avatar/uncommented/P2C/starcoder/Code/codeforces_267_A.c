#include <stdio.h>
#include <stdlib.h>
int main ( ) {
    int n;
    scanf ( "%d", &n );
    int *lst = ( int * ) malloc ( n * sizeof ( int ) );
    for ( int i = 0 ; i < n ; i++ ) {
        int a, b;
        scanf ( "%d %d", &a, &b );
        lst[i] = 0;
        if ( a > b ) {
            while ( a > 0 && b > 0 ) {
                lst[i] += a / b;
                a = a % b;
                if ( a > 0 ) {
                    lst[i] += b / a;
                    b = b % a;
                }
            }
        }
        if ( a < b ) {
            while ( a > 0 && b > 0 ) {
                lst[i] += b / a;
                b = b % a;
                if ( b > 0 ) {
                    lst[i] += a / b;
                    a = a % b;
                }
            }
        }
        if ( a == b ) {
            lst[i] = 1;
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        printf ( "%d\n", lst[i] );
    }
    free ( lst );
    return 0;
}
