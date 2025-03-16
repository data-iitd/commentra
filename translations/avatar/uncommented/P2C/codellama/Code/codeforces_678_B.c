#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leapyear ( int n ) {
    if ( n % 400 == 0 || ( n % 4 == 0 && n % 100 != 0 ) ) {
        return 1;
    } else {
        return 0;
    }
}

int main ( ) {
    int n, d;
    char ans[10];
    scanf ( "%d", &n );
    d = 'f';
    if ( n % 400 == 0 || ( n % 4 == 0 && n % 100 != 0 ) ) {
        strcpy ( ans, "ly" );
    } else {
        strcpy ( ans, "nly" );
    }
    while ( 1 ) {
        if ( n % 400 == 0 || ( n % 4 == 0 && n % 100 != 0 ) ) {
            if ( d == 'm' ) {
                d = 'w';
                n += 1;
            } else if ( d == 't' ) {
                d = 'th';
                n += 1;
            } else if ( d == 'w' ) {
                d = 'f';
                n += 1;
            } else if ( d == 'th' ) {
                d = 'sa';
                n += 1;
            } else if ( d == 'f' ) {
                d = 's';
                n += 1;
            } else if ( d == 'sa' ) {
                d = 'm';
                n += 1;
            } else if ( d == 's' ) {
                d = 't';
                n += 1;
            }
        } else {
            if ( d == 'm' ) {
                d = 't';
                n += 1;
            } else if ( d == 't' ) {
                d = 'w';
                n += 1;
            } else if ( d == 'w' ) {
                d = 'th';
                n += 1;
            } else if ( d == 'th' ) {
                d = 'f';
                n += 1;
            } else if ( d == 'f' ) {
                d = 'sa';
                n += 1;
            } else if ( d == 'sa' ) {
                d = 's';
                n += 1;
            } else if ( d == 's' ) {
                d = 'm';
                n += 1;
            }
        }
        if ( d == 'f' && strcmp ( ans, "ly" ) == 0 && leapyear ( n ) == 1 ) {
            break;
        } else if ( d == 'f' && strcmp ( ans, "nly" ) == 0 && leapyear ( n ) == 0 ) {
            break;
        }
    }
    printf ( "%d\n", n );
    return 0;
}