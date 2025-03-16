#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 1000000000
#define MOD 1000000007

int main ( ) {
    int n;
    scanf ( "%d", &n );
    int a[n];
    for ( int i = 0 ; i < n ; i++ )
        scanf ( "%d", &a[i] );
    int ans = 0;
    for ( int i = 1 ; i < n - 1 ; i++ )
        if ( a[i - 1] < a[i] && a[i] > a[i + 1] || a[i - 1] > a[i] && a[i] < a[i + 1] )
            ans++;
    printf ( "%d", ans + 1 );
    return 0;
}
