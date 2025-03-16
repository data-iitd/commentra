
#include <bits/stdc++.h>

using namespace std ;

int main ( ) {
    int n, m, q ;
    cin >> n >> m >> q ;

    int *a = new int [ q ] ;
    int *b = new int [ q ] ;
    int *c = new int [ q ] ;
    int *d = new int [ q ] ;

    for ( int i = 0 ; i < q ; ++ i ) {
        cin >> a [ i ] >> b [ i ] >> c [ i ] >> d [ i ] ;
    }

    long long ans = - 100 ;

    dfs ( n, m, q, a, b, c, d, ans ) ;

    cout << ans << endl ;

    return 0 ;
}

void dfs ( int n, int m, int q, int *a, int *b, int *c, int *d, long long &ans ) {
    if ( n == 0 ) {
        long long score = 0 ;

        for ( int i = 0 ; i < q ; ++ i ) {
            score += ( a [ i ] - b [ i ] == c [ i ] )? d [ i ] : 0 ;
        }

        ans = max ( ans, score ) ;
    }

    if ( n > 0 ) {
        for ( int num = 1 ; num <= m ; ++ num ) {
            dfs ( n - 1, m, q, a, b, c, d, ans ) ;
        }
    } else {
        for ( int num = 1 ; num <= m ; ++ num ) {
            dfs ( n, m, q, a, b, c, d, ans ) ;
        }
    }
}



