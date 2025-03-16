
#include <stdio.h>

int main ( ) {
    int n, i, j;
    scanf ( "%d", &n );
    i = 1;
    j = n * n;
    while ( i < j ) {
        printf ( "%d %d\n", i, j );
        i += 1;
        j -= 1;
    }
    return 0;
}
// END-OF-CODE