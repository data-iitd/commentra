
#include <stdio.h>
#include <string.h>

char * generateString ( ) {
    char * str = ( char * ) malloc ( 1001 * sizeof ( char ) ) ;
    int i ;
    for ( i = 1 ; i <= 1000 ; i ++ ) {
        sprintf ( str + ( i - 1 ) * 3, "%d", i ) ;
    }
    return str ;
}

int main ( ) {
    int n ;
    scanf ( "%d", & n ) ;
    printf ( "%c\n", generateString ( ) [ n - 1 ] ) ;
    return 0 ;
}
//END-OF-CODE