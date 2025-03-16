
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

int main ( ) {
    int N, M ;
    cin >> N >> M ;
    vector < int > A ( N ) ;
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> A [ i ] ;
    }
    vector < int > cum_remainders ( N + 1 ) ;
    partial_sum ( A.begin ( ), A.end ( ), cum_remainders.begin ( ) + 1, [ & ] ( int a, int b ) {
        return ( a + b ) % M ;
    } ) ;
    transform ( cum_remainders.begin ( ), cum_remainders.end ( ), cum_remainders.begin ( ), [ & ] ( int a ) {
        return a % M ;
    } ) ;
    map < int, int > remainder_counts ;
    for ( int i = 0 ; i <= N ; i ++ ) {
        remainder_counts [ cum_remainders [ i ] ] ++ ;
    }
    long long combinations = 0 ;
    for ( auto count : remainder_counts ) {
        combinations += count.second * ( count.second - 1 ) / 2 ;
    }
    cout << combinations << endl ;
    return 0 ;
}

