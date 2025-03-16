#include <iostream>
#include <string>
#include <map>
using namespace std;
int main ( ) {
    int n;
    cin >> n;
    map < int , int > w;
    for ( int i = 0 ; i < n ; i ++ ) {
        int x;
        cin >> x;
        w [ x ] ++;
    }
    int c = 0;
    for ( auto i : w ) {
        if ( i.first == 0 ) {
            c += i.second * ( i.second - 1 );
        } else {
            if ( w.find ( - i.first ) != w.end ( ) ) {
                c += i.second * w [ - i.first ];
            }
        }
    }
    cout << c / 2 << endl;
    return 0;
}



