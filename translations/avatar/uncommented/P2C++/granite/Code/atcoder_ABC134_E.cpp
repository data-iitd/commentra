
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search ( int key ) {
    int bad = - 1, good = ans.size ( ) ;
    while ( good - bad > 1 ) {
        int mid = ( bad + good ) / 2 ;
        if ( ans [ mid ] [ ans [ mid ].size ( ) - 1 ] < key ) {
            good = mid ;
        } else {
            bad = mid ;
        }
    }
    return good ;
}

int main ( ) {
    int N ;
    cin >> N ;
    vector < vector < int > > ans ;
    for ( int i = 0 ; i < N ; i ++ ) {
        int A ;
        cin >> A ;
        int idx = binary_search ( A ) ;
        if ( idx == ans.size ( ) ) {
            ans.push_back ( vector < int > ( ) ) ;
            ans [ idx ].push_back ( A ) ;
        } else {
            ans [ idx ].push_back ( A ) ;
        }
    }
    cout << ans.size ( ) << endl ;
    return 0 ;
}

