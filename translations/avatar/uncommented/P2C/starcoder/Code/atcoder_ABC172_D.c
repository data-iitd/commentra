#include <stdio.h>
int main ( ) {
    int N;
    scanf ( "%d", &N );
    int ans = 0;
    for ( int i = 1 ; i <= N ; i ++ ) {
        ans += i * ( N / i ) * ( N / i + 1 ) / 2;
    }
    printf ( "%d", ans );
    return 0;
}
