#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int N;
    cin >> N;
    vector < int > A ( N );
    for ( int i = 0; i < N; i++ ) {
        cin >> A [ i ];
        A [ i ] *= N;
        A [ i ] += i;
    }
    sort ( A.begin ( ), A.end ( ) );
    int cnt = 0;
    for ( int i = 0; i < N; i++ ) {
        int d = ( A [ i ] % N ) % 2;
        if ( d % 2!= i % 2 ) {
            cnt++;
        }
    }
    cout << cnt / 2 << endl;
    return 0;
}
