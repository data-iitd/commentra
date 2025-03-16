#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdarg.h>
#include <float.h>
#include <limits.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdarg.h>
#include <float.h>
#include <limits.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>

int main ( int argc, char * * argv ) {
    int n ;
    int * a ;
    struct node * s ;
    scanf ( "%d", & n ) ;
    a = ( int * ) malloc ( n * sizeof ( int ) ) ;
    for ( int i = 0 ; i < n ; i ++ ) scanf ( "%d", & a [ i ] ) ;
    s = NULL ;
    int ng = 0 ;
    int ok = n ;
    while ( ok - ng > 1 ) {
        int k = ( ng + ok ) / 2 ;
        if ( isPossible ( k ) ) {
            ok = k ;
        } else {
            ng = k ;
        }
    }
    printf ( "%d", ok ) ;
    return 0 ;
}

bool isPossible ( int k ) {
    struct node * s = NULL ;
    int current = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( a [ i ] <= current ) {
            if ( k == 1 ) return false ;
            while ( s && s -> key >= a [ i ] ) {
                struct node * t = s ;
                s = s -> prev ;
                free ( t ) ;
            }
            int p = a [ i ] - 1 ;
            while ( true ) {
                if ( p < 0 ) return false ;
                int sp = 0 ;
                struct node * t = s ;
                while ( t && t -> key == p ) {
                    sp ++ ;
                    t = t -> prev ;
                }
                if ( sp == k ) {
                    if ( t ) {
                        t -> prev = t -> prev -> prev ;
                    } else {
                        s = s -> prev ;
                    }
                    p -- ;
                } else {
                    break ;
                }
            }
        }
        current = a [ i ] ;
    }
    return true ;
}

struct node {
    int key ;
    struct node * prev ;
} ;

