
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x;
    cout << "Enter an integer: ";
    cin >> x;
    cout << "The number of distinct cyclic permutations of a string of length " << x << " is " << 360 / gcd(360, x) << endl;
    return 0;
}

