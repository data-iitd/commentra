
#include <iostream>
#include <cmath>
using namespace std;

int next_int ( ) {
    int x;
    cin >> x;
    return x;
}

int next_ints ( ) {
    string s;
    cin >> s;
    int x;
    int t = 0;
    for ( int i = 0 ; i < s.length ( ) ; i++ ) {
        if ( s [ i ] == ' ' ) {
            continue;
        }
        x = x * 10 + s [ i ] - '0';
    }
    return x;
}

int main ( ) {
    int n = next_int ( );
    int t = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( i + 1 & 1 ) {
            t++;
        }
    }
    cout << t / n << endl;
    return 0;
}

