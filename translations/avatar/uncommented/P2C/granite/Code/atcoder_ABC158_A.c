
#include <stdio.h>

int main ( ) {
    char s [ 100 ];
    fgets ( s, 100, stdin );
    char *p = s;
    char result [ 10 ];
    while ( *p!= '\n' ) {
        if ( *p == 'A' || *p == 'B' ) {
            result [ 0 ] = 'Y';
            result [ 1 ] = 'e';
            result [ 2 ] ='s';
            break;
        }
        p++;
    }
    if ( *p == '\n' ) {
        result [ 0 ] = 'N';
        result [ 1 ] = 'o';
    }
    result [ 2 ] = '\n';
    printf ( "%s", result );
    return 0;
}
//END-OF-CODE



Translate the above C code to Java and end with comment "