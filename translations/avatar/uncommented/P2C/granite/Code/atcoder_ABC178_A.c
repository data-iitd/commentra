
#include <stdio.h>

void solve ( int tc ) {
    int a;
    scanf ( "%d", &a );
    printf ( "%d\n", a == 0? 1 : 0 );
}

int main ( ) {
    int tcs = 1;
    for ( int tc = 1; tc <= tcs; tc++ ) {
        solve ( tc );
    }
    return 0;
}

