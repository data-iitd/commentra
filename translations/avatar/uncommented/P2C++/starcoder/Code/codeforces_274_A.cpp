#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int num, k ;
    cin >> num >> k ;
    vector < int > arr ( num ) ;
    for ( int i = 0 ; i < num ; i++ ) {
        cin >> arr[i] ;
    }
    set < int > different ;
    int temp = 0 ;
    sort ( arr.begin ( ), arr.end ( ) ) ;
    for ( int x : arr ) {
        if ( x % k!= 0 or not x / k in different ) {
            different.insert ( x ) ;
        }
        temp = max ( temp, ( int ) different.size ( ) ) ;
    }
    cout << temp << endl ;
    return 0 ;
}
