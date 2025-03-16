#include <stdio.h>
#include <stdlib.h>
int main ( ) {
    int tc, tcs, a;
    scanf ( "%d", &tcs );
    for ( tc = 1; tc <= tcs; tc++ ) {
        scanf ( "%d", &a );
        printf ( "%d\n", a == 0 ? 1 : 0 );
    }
    return 0;
}
