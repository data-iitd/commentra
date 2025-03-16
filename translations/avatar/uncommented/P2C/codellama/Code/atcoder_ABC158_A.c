
#include <stdio.h>
#include <string.h>

int main ( ) {
    char s[100];
    scanf ( "%s", s );
    if ( strstr ( s, "A" ) && strstr ( s, "B" ) ) {
        printf ( "Yes\n" );
    } else {
        printf ( "No\n" );
    }
    return 0;
}

