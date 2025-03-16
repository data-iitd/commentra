#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <queue>

using namespace std;

int main ( ) {
    int n, m, vis [ 10001 ], ci, cb, cc, u, v, i, j, k, l, cnt, flag, col ;
    queue < int > stk ;
    scanf ( "%d %d", &n, &m ) ;
    memset ( vis, 0, sizeof ( vis ) ) ;
    ci = cb = cc = 0 ;
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d %d", &u, &v ) ;
        g [ u ] [ v ] = 1 ;
        g [ v ] [ u ] = 1 ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( vis [ i ] == 0 ) {
            if ( g [ i ] [ 0 ] == 0 ) {
                ci ++ ;
            }
            else {
                flag = true ;
                stk.push ( i ) ;
                vis [ i ] = 1 ;
                while (! stk.empty ( ) ) {
                    u = stk.front ( ) ;
                    stk.pop ( ) ;
                    for ( j = 1 ; j <= n ; j ++ ) {
                        if ( g [ u ] [ j ] == 1 && vis [ j ] == 0 ) {
                            stk.push ( j ) ;
                            vis [ j ] = 3 - vis [ u ] ;
                            flag &= ( vis [ j ] == vis [ u ] ) ;
                        }
                    }
                }
                if ( flag ) {
                    cb ++ ;
                }
                else {
                    cc ++ ;
                }
            }
        }
    }
    printf ( "%d", ci * ci + 2 * ci * ( n - ci ) + cc * cc + 2 * cb * cc + 2 * cb * cb ) ;
    return 0 ;
}

