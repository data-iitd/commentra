#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1, sumL = 0;
    for ( int i = 0 ; i < s.size ( ) ; i++ ) {
        if ( s[i] =='' ) continue;
        if ( s[i] == '.' ) {
            sumL = 0;
            ans++;
        }
        else {
            sumL++;
            if ( sumL > n ) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
