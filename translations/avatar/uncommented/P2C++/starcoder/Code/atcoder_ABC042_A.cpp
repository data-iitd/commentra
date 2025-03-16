#include <iostream>
using namespace std;
int main ( ) {
    int A, B, C;
    cin >> A >> B >> C;
    if ( A == 5 && B == 5 ) {
        if ( C == 10 ) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
