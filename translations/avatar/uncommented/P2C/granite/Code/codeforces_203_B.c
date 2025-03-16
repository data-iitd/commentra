
#include <stdio.h>

void solve_case ( ) {
    int n, m;
    scanf ( "%d %d", & n, & m );
    int count [ n ] [ n ];
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            count [ i ] [ j ] = 0;
        }
    }
    int ans = - 1;
    for ( int k = 0 ; k < m ; k ++ ) {
        int x, y;
        scanf ( "%d %d", & x, & y );
        x --;
        y --;
        bool found = false;
        for ( int i = x - 2 ; i <= x + 1 ; i ++ ) {
            for ( int j = y - 2 ; j <= y + 1 ; j ++ ) {
                if ( i >= 0 && i < n && j >= 0 && j < n ) {
                    count [ i ] [ j ] += 1;
                    if ( count [ i ] [ j ] == 9 ) {
                        found = true;
                    }
                }
            }
        }
        if ( found ) {
            ans = k + 1;
            break;
        }
    }
    printf ( "%d\n", ans );
}

int main ( ) {
    solve_case ( );
    return 0;
}
//END-OF-CODE