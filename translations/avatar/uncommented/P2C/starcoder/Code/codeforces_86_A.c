#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    int l, r, curr, s, first, second, ans;
    scanf ( "%d %d", &l, &r );
    curr = r;
    s = 0;
    while ( curr ) {
        s++;
        curr /= 10;
    }
    first = 10 ** s;
    second = first / 2;
    ans = -1;
    for ( int i = l ; i <= r ; i++ ) {
        if ( i >= l && i <= r ) {
            curr = i;
            char rev[100];
            strcpy ( rev, "" );
            for ( int k = 0 ; k < strlen ( ( char * ) &curr ) ; k++ ) {
                strcat ( rev, ( char * ) & ( 9 - curr % 10 ) );
                curr /= 10;
            }
            ans = max ( ans, atoi ( rev ) * curr );
        }
    }
    printf ( "%d\n", ans );
    return 0;
}
