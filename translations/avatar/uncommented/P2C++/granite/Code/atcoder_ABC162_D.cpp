
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main ( ) {
    int n;
    string s;
    cin >> n >> s;
    int rNum = 0, gNum = 0, bNum = 0;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( s [ i ] == 'R' ) rNum ++;
        else if ( s [ i ] == 'G' ) gNum ++;
        else bNum ++;
    }
    int sum = 0;
    for ( int step = 1 ; step <= ( n + 1 ) / 2 ; step ++ ) {
        for ( int i = 0 ; i < n - 2 * step ; i ++ ) {
            string temp = "";
            temp += s [ i ];
            temp += s [ i + step ];
            temp += s [ i + step * 2 ];
            if ( temp == "RGB" || temp == "RBG" || temp == "BGR" || temp == "BRG" || temp == "GBR" || temp == "GRB" ) {
                sum ++;
            }
        }
    }
    cout << rNum * gNum * bNum - sum << endl;
    return 0;
}
//END-OF-CODE