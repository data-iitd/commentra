
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
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
#include <stdio_ext.h>
#include <complex.h>
#include <tgmath.h>
#include <stdalign.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

// Initialize scanner for user input
int main ( int argc, char * * argv ) {
    int N ;
    scanf ( "%d", & N ) ;
    int size = ( 1 << N ) ;
    int * S = malloc ( size * sizeof ( int ) ) ;
    bool * spawned = malloc ( size * sizeof ( bool ) ) ;
    spawned [ size - 1 ] = true ;
    for ( int i = 0 ; i < size ; i ++ ) {
        scanf ( "%d", & S [ i ] ) ;
    }
    qsort ( S, size, sizeof ( int ), ( int ( * ) ( const void *, const void * ) ) qsort_cmp ) ;
    List < int > active = List < int > ( ) ;
    active.add ( size - 1 ) ;
    spawned [ size - 1 ] = true ;
    for ( int i = 0 ; i < N ; i ++ ) {
        active.sort ( ( int ( * ) ( const void *, const void * ) ) qsort_cmp_reverse ) ;
        List < int > activated = List < int > ( ) ;
        int next = size - 1 ;
        for ( int slime : active ) {
            while ( next >= 0 && ( S [ next ] >= slime || spawned [ next ] ) ) {
                next -- ;
            }
            if ( next < 0 ) {
                printf ( "No" ) ;
                return 0 ;
            }
            spawned [ next ] = true ;
            activated.add ( S [ next ] ) ;
        }
        active.addAll ( activated ) ;
    }
    printf ( "Yes" ) ;
    return 0 ;
}

