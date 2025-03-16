
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int ans = 0;
    if ( a.find ( "1" ) == string::npos ) {
        ans = 0;
    } else {
        vector < int > v;
        int cnt = 0;
        for ( int i = 0; i < a.size ( ); i ++ ) {
            if ( a [ i ] == '0' ) {
                cnt ++;
            } else {
                v.push_back ( cnt + 1 );
                cnt = 0;
            }
        }
        ans = 1;
        for ( int i = 0; i < v.size ( ); i ++ ) {
            ans *= v [ i ];
        }
    }
    cout << ans << endl;
    return 0;
}

