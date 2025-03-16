#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

#define MAX_STR_LEN 100000

char * run ( char * s, char * t ) {
    int i = 0;
    int j = 0;
    int slen = strlen ( s );
    int tlen = strlen ( t );
    int * ss = ( int * ) malloc ( sizeof ( int ) * slen );
    int * tt = ( int * ) malloc ( sizeof ( int ) * tlen );
    for ( i = 0 ; i < slen ; i++ ) {
        ss[i] = 0;
    }
    for ( i = 0 ; i < tlen ; i++ ) {
        tt[i] = 0;
    }
    for ( i = 0 ; i < slen ; i++ ) {
        ss[i] = s[i] - 'a';
    }
    for ( i = 0 ; i < tlen ; i++ ) {
        tt[i] = t[i] - 'a';
    }
    qsort ( ss, slen, sizeof ( int ), cmpfunc );
    qsort ( tt, tlen, sizeof ( int ), cmpfunc );
    for ( i = 0 ; i < slen ; i++ ) {
        if ( ss[i]!= tt[i] ) {
            free ( ss );
            free ( tt );
            return "No";
        }
    }
    free ( ss );
    free ( tt );
    return "Yes";
}

int cmpfunc ( const void * a, const void * b ) {
    return ( *( int * ) a - *( int * ) b );
}

int main ( ) {
    char s[MAX_STR_LEN];
    char t[MAX_STR_LEN];
    scanf ( "%s", s );
    scanf ( "%s", t );
    printf ( "%s\n", run ( s, t ) );
    return 0;
}

