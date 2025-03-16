
#include <iostream>
using namespace std;
int main ( ) {
    int a, b, hole = 1, i = 0, check = 1;
    cin >> a >> b;
    while ( check ) {
        if ( hole >= b ) {
            check = 0;
        } else {
            hole = a * ( i + 1 ) - i;
            i++;
        }
    }
    cout << i << endl;
    return 0;
}
