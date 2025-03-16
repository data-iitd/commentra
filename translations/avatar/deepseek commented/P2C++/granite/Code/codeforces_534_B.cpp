

#include <iostream>
#include <string>

using namespace std;

int main ( ) {
    string v1, v2 ;
    cin >> v1 >> v2 ;
    int t, d ;
    cin >> t >> d ;
    int a = 1, v = stoi ( v1 ), distance = 0 ;
    for ( int i = 0 ; i < t ; i ++ ) {
        if ( v - stoi ( v2 ) > ( t - i - 1 ) * d ) {
            a *= - 1 ;
            v = ( t - i - 1 ) * d + stoi ( v2 ) ;
        }
        distance += v ;
        v += a * d ;
    }
    cout << distance << endl ;
    return 0 ;
}



Translate the above Python code to Java and end with comment "