#include <iostream>
#include <cmath>
using namespace std;
int next_int ( ) {
    int x;
    cin >> x;
    return x;
}
int next_ints ( ) {
    int x;
    cin >> x;
    return x;
}
int main ( ) {
    int n = next_int ( );
    int t = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( i + 1 & 1 ) {
            t += 1;
        }
    }
    cout << t / n << endl;
    return 0;
}



