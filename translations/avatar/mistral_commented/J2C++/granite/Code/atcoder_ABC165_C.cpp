

#include <bits/stdc++.h>

using namespace std ;

int main ( ) {
    int n, m, q ;
    cin >> n >> m >> q ;

    vector < int > a ( q ) ;
    vector < int > b ( q ) ;
    vector < int > c ( q ) ;
    vector < int > d ( q ) ;

    for ( int i = 0 ; i < q ; ++ i ) {
        cin >> a [ i ] >> b [ i ] >> c [ i ] >> d [ i ] ;
        -- a [ i ] ;
        -- b [ i ] ;
    }

    long long ans = - 100000000000000000LL ;

    function < void ( vector < int >, int ) > dfs = [&] ( vector < int > list, int idx ) {
        if ( idx == n ) {
            long long score = 0LL ;

            for ( int i = 0 ; i < q ; ++ i ) {
                score += ( list [ b [ i ] ] - list [ a [ i ] ] == c [ i ] )? d [ i ] : 0LL ;
            }

            ans = max ( ans, score ) ;
            return ;
        }

        for ( int num = ( idx == 0 )? 1 : list [ idx - 1 ] ; num <= m ; ++ num ) {
            list.push_back ( num ) ;
            dfs ( list, idx + 1 ) ;
            list.pop_back ( ) ;
        }
    } ;

    dfs ( { }, 0 ) ;

    cout << ans << endl ;

    return 0 ;
}

