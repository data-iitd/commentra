#include <stdio.h>
#define LUCKY "abcd"
int main ( ) {
    int n, i;
    char s[1000];
    scanf ( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        s[i] = LUCKY[i % 4];
    }
    printf ( "%s\n", s );
    return 0;
}
