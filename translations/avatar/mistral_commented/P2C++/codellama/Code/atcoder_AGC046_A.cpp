
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x;
    cout << "Enter an integer: ";
    cin >> x;
    int gcd_value = gcd( 360 , x );
    cout << 360 / gcd_value << endl;
    return 0;
}

