#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    string line;
    cin >> line;
    map < char , int > bought_count;
    for ( char c : line ) {
        bought_count [ c ] ++;
    }
    cin >> line;
    map < char , int > made_cout;
    for ( char c : line ) {
        made_cout [ c ] ++;
    }
    int res = 0;
    for ( auto [ color , count ] : made_cout ) {
        if ( bought_count.find ( color ) == bought_count.end ( ) ) {
            cout << - 1 << endl;
            return 0;
        }
        res += min ( bought_count [ color ] , count );
    }
    cout << res << endl;
    return 0;
}
