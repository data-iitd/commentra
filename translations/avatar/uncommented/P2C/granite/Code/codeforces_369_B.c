
#include <stdio.h>

int get_nums ( int num, int t ) {
    return t / num + 1;
}

int main ( ) {
    int n, k, l, r, sa, sk;
    scanf ( "%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk );
    int ans [ n ];
    for ( int i = 0 ; i < k ; i ++ ) {
        ans [ i ] = get_nums ( k, sk );
    }
    for ( int i = k ; i < n ; i ++ ) {
        ans [ i ] = get_nums ( n - k, sa - sk );
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        printf ( "%d ", ans [ i ] );
    }
    printf ( "\n" );
    return 0;
}

