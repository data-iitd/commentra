#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    string s;
    cin >> s;
    string t = "";
    int i = 0;
    while ( i < s.size ( ) ) {
        if ( s [ i ] == 'A' ) {
            t += 'A';
            i += 1;
        }
        else if ( s [ i ] == 'B' ) {
            if ( i < s.size ( ) - 1 ) {
                if ( s [ i + 1 ] == 'C' ) {
                    t += 'D';
                    i += 2;
                }
                else {
                    t += 'X';
                    i += 1;
                }
            }
            else {
                t += 'X';
                i += 1;
            }
        }
        else {
            t += 'X';
            i += 1;
        }
    }
    int total = 0;
    int numA = 0;
    for ( int i = 0 ; i < t.size ( ) ; i++ ) {
        if ( t [ i ] == 'X' ) {
            numA = 0;
        }
        else {
            if ( t [ i ] == 'A' ) numA += 1;
            else total += numA;
        }
    }
    cout << total << endl;
    return 0;
}
