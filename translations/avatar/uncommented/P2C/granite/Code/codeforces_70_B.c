
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

int main ( int argc, char * argv [ ] ) {
    regex_t reg;
    regmatch_t match;
    int n, ans, sumL;
    char * str, * ptr;
    char buf [ 1000001 ];
    fgets ( buf, 1000000, stdin );
    n = atoi ( buf );
    fgets ( buf, 1000000, stdin );
    ptr = buf;
    regcomp ( & reg, "[.?!]", 0 );
    ans = 1;
    sumL = 0;
    while ( regexec ( & reg, ptr, 1, & match, 0 ) == 0 ) {
        str = malloc ( match. rm_eo - match. rm_so + 1 );
        strncat ( str, ptr + match. rm_so, match. rm_eo - match. rm_so );
        str [ match. rm_eo - match. rm_so ] = '\0';
        if ( strlen ( str ) > 1 ) {
            if ( strlen ( str ) > n ) {
                printf ( "Impossible\n" );
                exit ( 0 );
            }
            if ( sumL + strlen ( str ) + ( sumL > 0 ) > n ) {
                ans += 1;
                sumL = strlen ( str );
            } else {
                sumL = sumL + strlen ( str ) + ( sumL > 0 );
            }
        }
        ptr = ptr + match. rm_eo;
    }
    printf ( "%d\n", ans );
    return 0;
}
