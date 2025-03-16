
#include <stdio.h>
#include <string.h>

int main ( ) {

    char str [ 100 ] = { '\0' };
    char * pch;
    char * pch2;

    printf ( "Enter a string: " );
    gets ( str );

    pch = strtok ( str , "," );

    while ( pch != NULL ) {

        printf ( "%s " , pch );
        pch = strtok ( NULL , "," );

    }

    printf ( "\n" );

    return 0;

}

