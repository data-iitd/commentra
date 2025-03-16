#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, i, ans, last;
    scanf ( "%d", &n );
    int *l = ( int * ) malloc ( n * sizeof ( int ) );
    for ( i = 0 ; i < n ; i++ ) {
        scanf ( "%d", &l[i] );
    }
    ans = n - 1;
    last = 0;
    for ( i = 0 ; i < n ; i++ ) {
        ans += abs ( last - l[i] ) + 1;
        last = l[i];
    }
    printf ( "%d\n", ans );
    return 0;
}
