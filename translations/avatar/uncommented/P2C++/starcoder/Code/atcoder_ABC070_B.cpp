#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ( ) {
    vector < int > A;
    for ( int i = 0 ; i < 4 ; i++ ) {
        int x;
        cin >> x;
        A.push_back ( x );
    }
    if ( A [ 1 ] <= A [ 2 ] || A [ 3 ] <= A [ 0 ] ) {
        cout << 0 << endl;
    } else {
        sort ( A.begin ( ), A.end ( ) );
        cout << A [ 2 ] - A [ 1 ] << endl;
    }
    return 0;
}
