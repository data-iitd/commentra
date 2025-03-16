#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int aaa ( char * n ) {
    int ans = 1;
    for ( int i = 0 ; i < strlen ( n ) ; i ++ ) {
        if ( n [ i ]!= '7' && n [ i ]!= '5' && n [ i ]!= '3' ) {
            ans = 0;
            break;
        }
    }
    if ( ans == 1 ) {
        for ( int i = 0 ; i < strlen ( n ) ; i ++ ) {
            ans += aaa ( n + i + 1 );
        }
    }
    return ans;
}
int main ( ) {
    int N;
    scanf ( "%d", & N );
    printf ( "%d\n", aaa ( "0" ) );
    return 0;
}
