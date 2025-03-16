#include <iostream>
using namespace std;
int main ( ) {
    int x, y, a, b, lcm;
    cin >> x >> y >> a >> b;
    lcm = x * y / __gcd ( x, y );
    cout << b / lcm - ( a - 1 ) / lcm << endl;
    return 0;
}
