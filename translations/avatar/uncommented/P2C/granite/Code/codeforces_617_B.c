
#include <stdio.h>
#include <math.h>

int main ( ) {
    int n;
    scanf ( "%d", &n );
    char a [ n ];
    scanf ( "%s", a );
    int ans = 0;
    int cnt = 0;
    for ( int i = 0; i < n; i ++ ) {
        if ( a [ i ] == '1' ) {
            ans += pow ( 2, cnt );
            cnt = 0;
        } else {
            cnt += 1;
        }
    }
    printf ( "%d\n", ans );
    return 0;
}
// END-OF-CODE