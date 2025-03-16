
#include <bits/stdc++.h>
using namespace std;

void cutRibbon ( ) {
    int arr [ 3 ] ;
    for ( int i = 0 ; i < 3 ; i ++ ) {
        cin >> arr [ i ] ;
    }
    int length = arr [ 0 ] ;
    sort ( arr + 1, arr + 3 ) ;
    if ( length % arr [ 0 ] == 0 ) {
        cout << int ( length / arr [ 0 ] ) << endl ;
        return ;
    }
    int ans = 0 ;
    if ( arr [ 0 ] == arr [ 1 ] ) {
        int k = 0 ;
        for ( int i = 0 ; i <= length / arr [ 2 ] ; i ++ ) {
            int check = length - i * arr [ 2 ] ;
            if ( check >= 0 && check % arr [ 0 ] == 0 ) {
                k = int ( check / arr [ 0 ] ) ;
                ans = max ( ans, k + i ) ;
            }
        }
    } else {
        int k = 0 ;
        for ( int i = 0 ; i <= length / arr [ 2 ] ; i ++ ) {
            for ( int j = 0 ; j <= length / arr [ 1 ] ; j ++ ) {
                int check = length - i * arr [ 2 ] - j * arr [ 1 ] ;
                if ( check >= 0 && check % arr [ 0 ] == 0 ) {
                    k = int ( check / arr [ 0 ] ) ;
                    ans = max ( ans, k + i + j ) ;
                }
            }
        }
    }
    cout << ans << endl ;
    return ;
}
cutRibbon ( )

