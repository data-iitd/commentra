
#include <iostream>
using namespace std;
int main ( ) {
    int k, n, w, total = 0 ;
    cin >> k >> n >> w ;
    if ( 1 <= k and k <= 1000 and 1 <= w and w <= 1000 ) {
        for ( int i = 1 ; i <= w ; i++ ) {
            total += i * k ;
        }
        if ( total > n ) {
            cout << total - n ;
        } else {
            cout << 0 ;
        }
    }
    return 0 ;
}
