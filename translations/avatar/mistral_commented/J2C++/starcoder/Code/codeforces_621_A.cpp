
#include <bits/stdc++.h>

using namespace std ;

int main ( ) {
    int n ;
    cin >> n ;

    vector < long long > list ;

    for ( int i = 0 ; i < n ; i ++ )
        list.push_back ( stoll ( cin.get ( ) ) ) ;

    vector < long long > odd ;
    long long sum = 0 ;

    for ( long long i : list ) {
        if ( i % 2 == 0 )
            sum += i ;
        else
            odd.push_back ( i ) ;
    }

    sort ( odd.begin ( ), odd.end ( ) ) ;

    for ( long long i : odd )
        sum += i ;

    if ( odd.size ( ) % 2!= 0 )
        sum -= odd.front ( ) ;

    cout << sum << endl ;
}

