#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector < pair < int, int > > problems ( q );
    for ( int i = 0 ; i < q ; i++ ) {
        cin >> problems [ i ].first >> problems [ i ].second;
    }
    function < int ( int, int ) > count = [ = ] ( int total, int i ) {
        return total + 1 if ( s [ i - 1 ] == 'A' and s [ i ] == 'C' ) else total;
    };
    vector < int > cumsum ( accumulate ( begin ( problems ), end ( problems ), 0, count ) );
    for ( auto p : problems ) {
        cout << cumsum [ p.second - 1 ] - cumsum [ p.first - 1 ] << endl;
    }
    return 0;
}
