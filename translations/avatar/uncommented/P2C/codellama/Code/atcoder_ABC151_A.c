#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#define DEBUG false
void log ( char * text ) {
    if ( DEBUG ) {
        printf ( "%s\n" , text );
    }
}
void parse_input ( char * lines_as_string , char * c ) {
    bool debug = false;
    char * lines = NULL;
    if ( lines_as_string == NULL ) {
        debug = false;
        lines = ( char * ) malloc ( sizeof ( char ) * 100 );
        scanf ( "%s" , lines );
    } else {
        debug = true;
        lines = ( char * ) malloc ( sizeof ( char ) * 100 );
        strcpy ( lines , lines_as_string );
    }
    char * c_ = strtok ( lines , " " );
    strcpy ( c , c_ );
}
char * solve ( char * c ) {
    char * a = "abcdefghijklmnopqrstuvwxyz";
    int i = strchr ( a , c [ 0 ] ) - a;
    return a + i + 1;
}
void main ( ) {
    char c [ 100 ];
    parse_input ( NULL , c );
    char * result = solve ( c );
    if ( result [ 0 ] == '[' ) {
        char * r = result + 1;
        while ( r [ 0 ] != ']' ) {
            printf ( "%c" , r [ 0 ] );
            r++;
        }
    } else {
        printf ( "%c" , result [ 0 ] );
    }
    printf ( "\n" );
}
