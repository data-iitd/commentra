#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    string s;
    cin >> s;
    if ( s.size ( ) == 1 ) {
        cout << 0 << endl;
        return 0;
    }
    map < char , int > a;
    for ( int i = 0 ; i < s.size ( ) ; i++ ) {
        a [ s [ i ] ]++;
    }
    int ans = 0;
    for ( auto it : a ) {
        ans = max ( ans , it.second * 2 );
    }
    cout << ans << endl;
    return 0;
}
