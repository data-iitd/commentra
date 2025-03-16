
#include <stdio.h>

int main ( ) {
    int N = 0;
    scanf ( "%d", & N );
    int ans = 0;
    for ( int i = 1; i <= N; i ++ ) {
        ans += i * ( N / i ) * ( N / i + 1 ) / 2;
    }
    printf ( "%d\n", ans );
    return 0;
}
// END-OF-CODE