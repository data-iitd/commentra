#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
int main ( ) {
    int N;
    cin >> N;
    vector < double > x;
    for ( int i = 0; i < N; i++ ) {
        string s;
        cin >> s;
        double v = 0;
        if ( s.find ( "JPY" )!= string::npos ) {
            v = stod ( s.replace ( "JPY", "" ) ) * 1.0;
        } else if ( s.find ( "BTC" )!= string::npos ) {
            v = stod ( s.replace ( "BTC", "" ) ) * 380000.0;
        }
        x.push_back ( v );
    }
    cout << accumulate ( x.begin ( ), x.end ( ), 0.0 ) << endl;
    return 0;
}
