#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int n;
    char m[100000];
    scanf ( "%d", &n );
    scanf ( "%s", m );
    int possible = 1;
    for ( int i = 0; i < n; i++ ) {
        int count = 0;
        for ( int j = 0; j < n; j++ ) {
            if ( m[i] == m[j] ) {
                count++;
            }
        }
        if ( count >= n / 2 + 1 ) {
            possible = 0;
            break;
        }
    }
    printf ( "%s\n", possible? "YES" : "NO" );
    return 0;
}
