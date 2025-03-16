
#include <stdio.h>

int main ( ) {
    int n;
    scanf ( "%d", & n );
    char s [ 100001 ];
    scanf ( "%s", s );
    char t [ 100001 ];
    scanf ( "%s", t );
    int i, j, cnt;
    if ( strcmp ( s, t ) == 0 ) {
        printf ( "%d\n", n );
    } else {
        cnt = 0;
        for ( i = 0; i < n; i ++ ) {
            for ( j = 0; j < n - i; j ++ ) {
                if ( s [ i + j ]!= t [ j ] ) {
                    break;
                }
                if ( j == n - i - 1 ) {
                    cnt = n - i;
                }
            }
        }
        printf ( "%d\n", 2 * n - cnt );
    }
    return 0;
}
