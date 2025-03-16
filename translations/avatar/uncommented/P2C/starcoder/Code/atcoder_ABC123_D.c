#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>

int main ( ) {
    int x, y, z, k ;
    scanf ( "%d%d%d%d", &x, &y, &z, &k ) ;
    int a [ x ], b [ y ], c [ z ], ab [ x * y ], abc [ k ] ;
    for ( int i = 0 ; i < x ; i ++ ) {
        scanf ( "%d", &a [ i ] ) ;
    }
    for ( int i = 0 ; i < y ; i ++ ) {
        scanf ( "%d", &b [ i ] ) ;
    }
    for ( int i = 0 ; i < z ; i ++ ) {
        scanf ( "%d", &c [ i ] ) ;
    }
    for ( int i = 0 ; i < x * y ; i ++ ) {
        ab [ i ] = a [ i / y ] + b [ i % y ] ;
    }
    for ( int i = 0 ; i < k ; i ++ ) {
        abc [ i ] = ab [ i ] ;
    }
    for ( int i = 0 ; i < k ; i ++ ) {
        for ( int j = 0 ; j < z ; j ++ ) {
            abc [ i ] += c [ j ] ;
        }
    }
    for ( int i = 0 ; i < k ; i ++ ) {
        printf ( "%d\n", abc [ i ] ) ;
    }
    return 0 ;
}

