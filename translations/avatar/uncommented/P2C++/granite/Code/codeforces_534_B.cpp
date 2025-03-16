
#include <iostream>
#include <string>
using namespace std;

int main ( ) {
    string v1, v2 ;
    string t, d ;
    cin >> v1 >> v2 ;
    cin >> t >> d ;
    int v1_ = stoi ( v1 ) ;
    int v2_ = stoi ( v2 ) ;
    int t_ = stoi ( t ) ;
    int d_ = stoi ( d ) ;
    int a = 1 ;
    int v = v1_ ;
    int distance = 0 ;
    for ( int i = 0 ; i < t_ ; i ++ ) {
        if ( v - v2_ > ( t_ - i - 1 ) * d_ ) {
            a *= - 1 ;
            v = ( t_ - i - 1 ) * d_ + v2_ ;
        }
        distance += v ;
        v += a * d_ ;
    }
    cout << distance << endl ;
    return 0 ;
}

