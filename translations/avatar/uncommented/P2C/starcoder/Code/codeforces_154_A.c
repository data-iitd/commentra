#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main ( ) {
    char s [ 1000001 ];
    int n;
    scanf ( "%s%d", s, &n );
    int ans = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        char x [ 2 ];
        scanf ( "%s", x );
        int a = 0, b = 0;
        for ( int j = 0 ; j < strlen ( s ) ; j++ ) {
            if ( s [ j ] == x [ 0 ] ) {
                a++;
            } else if ( s [ j ] == x [ 1 ] ) {
                b++;
            } else {
                ans += min ( a, b );
                a = 0;
                b = 0;
            }
        }
        ans += min ( a, b );
    }
    printf ( "%d", ans );
    return 0;
}
