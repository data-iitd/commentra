
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n;
    cin >> n;
    vector < int > a ( n );
    for ( int i = 0; i < n; i ++ ) {
        cin >> a [ i ];
    }
    vector < pair < int, int > > dp ( 1, make_pair ( a [ 0 ], 0 ) );
    for ( int i = 1; i < n; i ++ ) {
        if ( a [ i ] <= dp [ dp.size ( ) - 1 ].first ) {
            vector < pair < int, int > > new_dp;
            for ( int j = 0; j < dp.size ( ); j ++ ) {
                if ( dp [ j ].first < a [ i ] ) {
                    new_dp.push_back ( dp [ j ] );
                }
            }
            new_dp.push_back ( make_pair ( a [ i ], 0 ) );
            dp = new_dp;
        } else {
            dp.push_back ( make_pair ( a [ i ], 0 ) );
        }
        bool is_added = false;
        for ( int j = dp.size ( ) - 1; j >= 0; j -- ) {
            if ( dp [ j ].second < i ) {
                vector < pair < int, int > > new_dp;
                for ( int k = 0; k < j; k ++ ) {
                    new_dp.push_back ( dp [ k ] );
                }
                new_dp.push_back ( make_pair ( dp [ j ].first - 1, dp [ j ].second + 1 ) );
                for ( int k = j + 1; k < dp.size ( ); k ++ ) {
                    if ( new_dp [ new_dp.size ( ) - 1 ].first < dp [ k ].first ) {
                        new_dp.push_back ( dp [ k ] );
                    }
                }
                dp = new_dp;
                if ( dp [ dp.size ( ) - 1 ].first < a [ i ] ) {
                    dp.push_back ( make_pair ( a [ i ], 0 ) );
                }
                is_added = true;
                break;
            }
        }
        if (! is_added ) {
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
