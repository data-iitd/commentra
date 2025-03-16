
#include <stdio.h>

int main ( ) {
    int n, i, last, ans;
    scanf ( "%d", &n );
    int l [ n ];
    for ( i = 0; i < n; i ++ ) {
        scanf ( "%d", &l [ i ] );
    }
    ans = n - 1;
    last = 0;
    for ( i = 0; i < n; i ++ ) {
        ans += abs ( last - l [ i ] ) + 1;
        last = l [ i ];
    }
    printf ( "%d\n", ans );
    return 0;
}
// END-OF-CODE