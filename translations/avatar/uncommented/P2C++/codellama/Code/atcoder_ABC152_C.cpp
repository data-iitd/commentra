#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int main ( ) {
    int N;
    cin >> N;
    vector < int > n ( N );
    for ( int i = 0 ; i < N ; i++ ) {
        cin >> n [ i ];
    }
    int a = 1;
    int pos = 0;
    for ( int i = 1 ; i < N ; i++ ) {
        if ( n [ pos ] > n [ i ] ) {
            a += 1;
            pos = i;
        }
    }
    cout << a << endl;
    return 0;
}
