#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main ( ) {
    string xxs;
    cin >> xxs;
    vector < string > xxs_vec;
    stringstream ss ( xxs );
    string x;
    while ( ss >> x ) {
        xxs_vec.push_back ( x );
    }
    int x = stoi ( xxs_vec [ 0 ] );
    int t = stoi ( xxs_vec [ 1 ] );
    int a = stoi ( xxs_vec [ 2 ] );
    int b = stoi ( xxs_vec [ 3 ] );
    int da = stoi ( xxs_vec [ 4 ] );
    int db = stoi ( xxs_vec [ 5 ] );
    if ( x == 0 ) {
        cout << "YES" << endl;
        return 0;
    }
    int a_time = min ( a / da , t - 1 );
    int b_time = min ( b / db , t - 1 );
    for ( int i = 0 ; i <= a_time ; i++ ) {
        for ( int j = 0 ; j <= b_time ; j++ ) {
            if ( a - da * i == x || b - db * j == x ) {
                cout << "YES" << endl;
                return 0;
            }
            if ( ( a - da * i ) + ( b - db * j ) == x ) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
