#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 1000000000
#define MOD 1000000007

int main ( ) {
    int q, h, s, d, n;
    scanf ( "%d%d%d%d%d", &q, &h, &s, &d, &n );
    int best1L = min ( q * 4, h * 2, s );
    int best2L = min ( d, best1L * 2 );
    if ( n % 2 == 0 ) {
        printf ( "%d", best2L * ( n / 2 ) );
    } else {
        printf ( "%d", best2L * ( n / 2 ) + best1L );
    }
    return 0;
}
