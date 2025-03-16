
#include <bits/stdc++.h>

using namespace std ;

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( 0 ) ;
    cout.tie ( 0 ) ;

    // Step 1: Reading Input
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;

    // Step 2: Processing Input
    double arr [ 2 * n ] ;
    int non_int = 0 ;
    double sum_before = 0, sum = 0 ;

    for ( int i = 0 ; i < 2 * n ; i ++ ) {
        double num ;
        cin >> num ;
        sum_before += num ;
        if ( num!= floor ( num ) ) non_int ++ ;
        sum += floor ( num ) ;
        arr [ i ] = num ;
    }

    // Step 3: Calculating Results
    double max_sum = min ( n, non_int ) + sum ;
    double min_sum = max ( 0, non_int - n ) + sum ;
    double ans ;

    if ( min_sum > sum_before )
        ans = ( min_sum - sum_before ) ;
    else if ( max_sum < sum_before )
        ans = ( sum_before - max_sum ) ;
    else {
        double x = sum_before - floor ( sum_before ) ;
        ans = min ( 1 - x, x ) ;
    }

    // Step 4: Output
    cout << fixed << setprecision ( 3 ) << ans << endl ;
}

