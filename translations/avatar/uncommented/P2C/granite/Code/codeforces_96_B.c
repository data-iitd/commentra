
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

long long int l[10000000000];
long long int limit = 10000000000;

void gen ( long long int number, long long int four, long long int seven ) {
    if ( number > limit ) {
        return;
    }
    if ( number > 0 && four == seven ) {
        l[0] = number;
    }
    gen ( number * 10 + 4, four + 1, seven ) ;
    gen ( number * 10 + 7, four, seven + 1 ) ;
}

int main ( ) {
    gen ( 0, 0, 0 ) ;
    qsort ( l, 10000000000, sizeof ( long long int ) ) ;
    long long int n ;
    scanf ( "%lld", &n ) ;
    long long int ans = 0 ;
    for ( int i = 0 ; i < 10000000000 ; i ++ ) {
        if ( l[i] >= n ) {
            ans = l[i] ;
            break ;
        }
    }
    printf ( "%lld\n", ans ) ;
    return 0;
}
