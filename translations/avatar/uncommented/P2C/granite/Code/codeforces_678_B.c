
#include <stdio.h>
#include <string.h>

char* leapyear ( int n ) {
    if ( n % 400 == 0 || ( n % 4 == 0 && n % 100!= 0 ) ) {
        return "y";
    } else {
        return "n";
    }
}

int main() {
    int n;
    char d = "f";
    char* ans;
    if ( n % 400 == 0 || ( n % 4 == 0 && n % 100!= 0 ) ) {
        ans = "ly";
    } else {
        ans = "nly";
    }
    while ( 1 ) {
        if ( n % 400 == 0 || ( n % 4 == 0 && n % 100!= 0 ) ) {
            if ( strcmp( d, "m" ) == 0 ) {
                d = "w";
                n += 1;
            } else if ( strcmp( d, "t" ) == 0 ) {
                d = "th";
                n += 1;
            } else if ( strcmp( d, "w" ) == 0 ) {
                d = "f";
                n += 1;
            } else if ( strcmp( d, "th" ) == 0 ) {
                d = "sa";
                n += 1;
            } else if ( strcmp( d, "f" ) == 0 ) {
                d = "s";
                n += 1;
            } else if ( strcmp( d, "sa" ) == 0 ) {
                d = "m";
                n += 1;
            } else if ( strcmp( d, "s" ) == 0 ) {
                d = "t";
                n += 1;
            }
        } else {
            if ( strcmp( d, "m" ) == 0 ) {
                d = "t";
                n += 1;
            } else if ( strcmp( d, "t" ) == 0 ) {
                d = "w";
                n += 1;
            } else if ( strcmp( d, "w" ) == 0 ) {
                d = "th";
                n += 1;
            } else if ( strcmp( d, "th" ) == 0 ) {
                d = "f";
                n += 1;
            } else if ( strcmp( d, "f" ) == 0 ) {
                d = "sa";
                n += 1;
            } else if ( strcmp( d, "sa" ) == 0 ) {
                d = "s";
                n += 1;
            } else if ( strcmp( d, "s" ) == 0 ) {
                d = "m";
                n += 1;
            }
        }
        if ( strcmp( d, "f" ) == 0 && strcmp( ans, "ly" ) == 0 && strcmp( leapyear( n ), "y" ) == 0 ) {
            break;
        } else if ( strcmp( d, "f" ) == 0 && strcmp( ans, "nly" ) == 0 && strcmp( leapyear( n ), "n" ) == 0 ) {
            break;
        }
    }
    printf( "%d\n", n );
    return 0;
}
