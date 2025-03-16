#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main ( ) {
    int n;
    cin >> n;
    vector<string> m;
    for ( int i = 0; i < n; i++ ) {
        string s;
        cin >> s;
        m.push_back ( s );
    }
    bool possible = true;
    for ( int i = 0; i < m.size ( ); i++ ) {
        int count = 0;
        for ( int j = 0; j < m.size ( ); j++ ) {
            if ( m[i] == m[j] ) {
                count++;
            }
        }
        if ( count >= n / 2 + 1 ) {
            possible = false;
            break;
        }
    }
    if ( possible ) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
