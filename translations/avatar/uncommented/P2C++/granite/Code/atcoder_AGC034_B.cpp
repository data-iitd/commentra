
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int N = 1e5 + 10;
const int M = 1e9 + 7;
const double eps = 1e-9;
const ll oo = 1e18 + 5;

int gcd ( int a, int b ) {
    a = max ( a, b ) ; b = min ( a, b ) ;
    while ( b ) {
        a %= b ; swap ( a, b ) ;
    } return a ;
}

int solve ( ) {
    string s ; cin >> s ;
    string t = "" ;
    int i = 0 ;
    while ( i < s.size ( ) ) {
        if ( s [ i ] == 'A' ) {
            t += 'A' ;
            i ++ ;
        }
        else if ( s [ i ] == 'B' ) {
            if ( i < s.size ( ) - 1 ) {
                if ( s [ i + 1 ] == 'C' ) {
                    t += 'D' ;
                    i += 2 ;
                }
                else {
                    t += 'X' ;
                    i ++ ;
                }
            }
            else {
                t += 'X' ;
                i ++ ;
            }
        }
        else {
            t += 'X' ;
            i ++ ;
        }
    }
    int total = 0 ;
    int numA = 0 ;
    for ( int i = 0 ; i < t.size ( ) ; i ++ ) {
        if ( t [ i ] == 'X' ) numA = 0 ;
        else {
            if ( t [ i ] == 'A' ) numA ++ ;
            else total += numA ;
        }
    }
    cout << total << endl ;
    return 0 ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ; cin.tie ( NULL ) ;
    solve ( ) ;
    return 0 ;
}

Translate the above C++ code to Java and end with comment "