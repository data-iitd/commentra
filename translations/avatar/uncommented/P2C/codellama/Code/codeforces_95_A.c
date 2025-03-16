#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main ( ) {
    int pya;
    char **arre;
    char oString [ 1000 ];
    char lowString [ 1000 ];
    char letter1;
    char letter2;
    int valid [ 1000 ];
    int setcito [ 1000 ];
    int i, j, wat, index;

    scanf ( "%d", &pya );
    arre = ( char ** ) malloc ( pya * sizeof ( char * ) );
    for ( i = 0; i < pya; i++ ) {
        arre [ i ] = ( char * ) malloc ( 1000 * sizeof ( char ) );
        scanf ( "%s", arre [ i ] );
    }
    scanf ( "%s", oString );
    strcpy ( lowString, oString );
    letter1 = tolower ( oString [ 0 ] );
    letter2 = 'a' + ( letter1 != 'a' );
    for ( i = 0; i < strlen ( oString ); i++ ) {
        valid [ i ] = 0;
    }
    for ( i = 0; i < strlen ( oString ); i++ ) {
        setcito [ i ] = 0;
    }
    for ( i = 0; i < pya; i++ ) {
        wat = 0;
        while ( 1 ) {
            index = strstr ( lowString, arre [ i ] ) - lowString;
            if ( index < 0 ) {
                break;
            }
            for ( j = index; j < index + strlen ( arre [ i ] ); j++ ) {
                setcito [ j ] = 1;
            }
            wat = index + 1;
        }
    }
    for ( i = 0; i < strlen ( oString ); i++ ) {
        if ( setcito [ i ] ) {
            oString [ i ] = letter1;
        }
    }
    for ( i = 0; i < strlen ( oString ); i++ ) {
        if ( islower ( oString [ i ] ) ) {
            oString [ i ] = letter1;
        } else {
            oString [ i ] = letter2;
        }
    }
    printf ( "%s\n", oString );

    return 0;
}
